import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    updatePost,
    deletePost,
    hidePost,
    pinPost,
} from "../../../scripts/post";

import PostWrapperView from "./PostWrapperView";



class PostWrapperController extends React.Component {

    constructor(props) {
        super(props);

        this.handleDeleteClick = this.handleDeleteClick.bind(this);
        this.handleHideClick = this.handleHideClick.bind(this);
        this.handlePinClick = this.handlePinClick.bind(this);
        this.handleEditClick = this.handleEditClick.bind(this);
        this.handleQuoteClick = this.handleQuoteClick.bind(this);
        this.handleLikeClick = this.handleLikeClick.bind(this);
        this.handleReportClick = this.handleReportClick.bind(this);
    };


    handleDeleteClick(e) {
        const {
            auth: { access_token, },
            post_data: { id, },
            pages_data: { active_page, items_on_page, },
            updatePostsData,
        } = this.props;

        deletePost(access_token, id)
            .then((state) => {
                if (state) {
                    if (items_on_page == 1) {
                        updatePostsData(active_page - 1);
                    } else {
                        updatePostsData(active_page);
                    };
                };
            });
    };


    handleHideClick(e) {
        const {
            auth: { access_token, },
            post_data: { id, },
            pages_data: { active_page, },
            updatePostsData,
        } = this.props;

        hidePost(access_token, id)
            .then((state) => {
                if (state) {
                    updatePostsData(active_page);
                };
            });
    };


    handlePinClick(e) {
        const {
            auth: { access_token, },
            post_data: { id, },
            pages_data: { active_page, },
            updatePostsData,
        } = this.props;

        pinPost(access_token, id)
            .then((state) => {
                if (state) {
                    updatePostsData(active_page);
                };
            });
    };


    handleEditClick(e) {
        return
    };


    handleQuoteClick(e) {
        return
    };


    handleLikeClick(e) {
        return
    };


    handleReportClick(e) {
        return
    };


    render() {
        const {
            post_data,
        } = this.props;

        return (
            <PostWrapperView
                post_data={post_data}
                handleDeleteClick={this.handleDeleteClick}
                handleHideClick={this.handleHideClick}
                handlePinClick={this.handlePinClick}
                handleEditClick={this.handleEditClick}
                handleQuoteClick={this.handleQuoteClick}
                handleLikeClick={this.handleLikeClick}
                handleReportClick={this.handleReportClick}
            />
        );
    };

};



PostWrapperController.propTypes = {
    post_data: PropTypes.object.isRequired,
    pages_data: PropTypes.object.isRequired,
    updatePostsData: PropTypes.func.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps, null)(PostWrapperController);
