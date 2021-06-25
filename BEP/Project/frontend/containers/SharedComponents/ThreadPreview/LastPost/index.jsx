import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    getPost,
} from "../../../scripts/post";

import LastPostView from "./LastPostView";

import "../../styles/styles.css";



class LastPostController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            is_ready: false,

            post_data: null,
        };
    };


    preparePostData(post_data) {
        post_data["created_date"] = new Date(post_data.created_date).toLocaleString();
        post_data["modified_date"] = new Date(post_data.modified_date).toLocaleString();
    };


    updatePostData() {
        const {
            post_id,
            auth: { access_token, },
        } = this.props;

        getPost(access_token, post_id)
            .then((data) => {
                if (data) {
                    // console.log(data)
                    this.preparePostData(data);
                    this.setState({
                        is_ready: true,
                        post_data: data,
                    });
                };
            });
    };


    componentDidMount() {
        this.updatePostData();
    };


    render() {
        const {
            is_ready,
            post_data,
        } = this.state;

        // console.log(post_data)

        if (is_ready) {
            return (
                <LastPostView
                    post_data={post_data}
                />
            );
        } else {
            return null;
        };
    };

};



LastPostController.propTypes = {
    post_id: PropTypes.number.isRequired,
};


const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps, null)(LastPostController);
