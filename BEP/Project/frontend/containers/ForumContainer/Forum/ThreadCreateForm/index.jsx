import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    toggleThreadCreateFormVisible,
} from "../../../../redux/actions";
import {
    createThread,
} from "../../../scripts/thread";

import ThreadCreateFormView from "./ThreadCreateFormView";



class ThreadCreateFormController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            thread_title_field: {
                value: "",
                error: false,
            },
            post_text_field: {
                value: "",
                error: false,
            },
        };

        this.handleInputChange = this.handleInputChange.bind(this);
        this.handleAcceptClick = this.handleAcceptClick.bind(this);
        this.handleCancelClick = this.handleCancelClick.bind(this);
    };


    checkInput(thread_title_field_value) {
        var is_input_error = false;

        if (thread_title_field_value === "") {
            this.setState({
                thread_title_field: {
                    value: "",
                    error: true
                },
            });
            is_input_error = true;
        };

        return !is_input_error;
    };


    handleInputChange(e) {
        const name = e.target.name;
        const value = e.target.value;

        this.setState({
            [name]: {
                value: value,
                error: false
            },
        });
    };


    handleAcceptClick(e) {
        const {
            thread_title_field,
            post_text_field,
        } = this.state;

        if (this.checkInput(thread_title_field.value)) {
            const {
                auth: { access_token, },
                forum_id,
                forum_model_id,
                updateThreadsData,
                toggleThreadCreateFormVisible,
            } = this.props;

            const request_data = {
                thread_data: {
                    parent_id: forum_id,
                    parent_model: forum_model_id,
                    title: thread_title_field.value,
                },
                post_data: {
                    content: post_text_field.value,
                },
            };

            toggleThreadCreateFormVisible();

            createThread(access_token, request_data)
                .then((data) => {
                    if (data) {
                        updateThreadsData();
                    };
                });
        };
    };


    handleCancelClick(e) {
        const {
            toggleThreadCreateFormVisible,
        } = this.props;

        toggleThreadCreateFormVisible();
    };


    render() {
        const {
            is_visible,
        } = this.props;
        const {
            thread_title_field,
        } = this.state;

        return (
            <ThreadCreateFormView
                is_visible={is_visible}
                thread_title_field_state={thread_title_field.error}
                handleInputChange={this.handleInputChange}
                handleAcceptClick={this.handleAcceptClick}
                handleCancelClick={this.handleCancelClick}
            />
        );
    };

};



ThreadCreateFormController.propTypes = {
    is_visible: PropTypes.bool.isRequired,
    forum_id: PropTypes.number.isRequired,
    forum_model_id: PropTypes.number.isRequired,
    updateThreadsData: PropTypes.func.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



const actions = {
    toggleThreadCreateFormVisible,
};



export default connect(mapStateToProps, actions)(ThreadCreateFormController);
