import React from "react";
import PropTypes from "prop-types";

import {
    LastPostController,
} from "../../../../SharedComponents";

import ThreadPreviewView from "./ThreadPreviewView";
import LinkToPostView from "./LinkToPostView";



class ThreadPreviewController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            thread_path: "/thread/",
        };
    };


    render() {
        const {
            forum_path,
            thread_id,
            thread_title,
            posts_count,
        } = this.props;
        const {
            thread_path,
        } = this.state;

        return (
            <ThreadPreviewView
                thread_path={thread_path}
                thread_title={thread_data.title}
                posts_count={thread_data.posts_count}
            >
                <LastPostController
                    post_id={thread_data.last_post}
                />
            </ThreadPreviewView>
        );
    };

};



ThreadPreviewController.propTypes = {
    thread_path: PropTypes.string.isRequired,
    thread_data: PropTypes.object.isRequired,
};



export default ThreadPreviewController;
