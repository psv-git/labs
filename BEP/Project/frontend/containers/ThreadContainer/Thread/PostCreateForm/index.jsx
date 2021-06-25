import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    togglePostCreateFormVisible,
} from "../../../../redux/actions";
import {
    createPost,
} from "../../../scripts/post";

import PostCreateFormView from "./PostCreateFormView";



class PostCreateFormController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            post_text_field: {
                value: "",
            },
        };

        this.handleInputChange = this.handleInputChange.bind(this);
        this.handleAcceptClick = this.handleAcceptClick.bind(this);
        this.handleCancelClick = this.handleCancelClick.bind(this);
    };


    handleInputChange(e) {
        const name = e.target.name;

        this.setState({
            [name]: {
                value: e.target.value,
            },
        });
    };


    handleAcceptClick(e) {
        const {
            post_text_field,
        } = this.state;

        const {
            thread_id,
            auth: { access_token, },
            pages_data: { pages_count, is_last_page_full, },
            updatePostsData,
            togglePostCreateFormVisible,
        } = this.props;

        togglePostCreateFormVisible();

        const post_data = {
            thread: thread_id,
            content: post_text_field.value,
        };

        createPost(access_token, post_data)
            .then((post_data) => {
                if (post_data) {
                    if (is_last_page_full) {
                        updatePostsData(pages_count + 1);
                    } else {
                        updatePostsData(pages_count);
                    };
                };
            });
    };


    handleCancelClick(e) {
        const {
            togglePostCreateFormVisible,
        } = this.props;

        togglePostCreateFormVisible();
    };


    // componentDidUpdate() {
    //     const {
    //         post_create_form_ref,
    //     } = this.props;

    //     if (post_create_form_ref.current) {
    //         var contentWrapper = document.getElementById("forums-module-content-wrapper");
    //         contentWrapper.scrollTo(0, post_create_form_ref.current.offsetTop);
    //     };
    // };


    render() {
        const {
            is_visible,
        } = this.props;

        return (
            <PostCreateFormView
                is_visible={is_visible}
                handleInputChange={this.handleInputChange}
                handleAcceptClick={this.handleAcceptClick}
                handleCancelClick={this.handleCancelClick}
            />
        );
    };

};



PostCreateFormController.propTypes = {
    is_visible: PropTypes.bool.isRequired,
    thread_id: PropTypes.number.isRequired,
    pages_data: PropTypes.object.isRequired,
    updatePostsData: PropTypes.func.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



const actions = {
    togglePostCreateFormVisible,
};



export default connect(mapStateToProps, actions)(PostCreateFormController);
