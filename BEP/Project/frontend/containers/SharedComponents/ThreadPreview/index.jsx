import React from "react";
import PropTypes from "prop-types";

import ThreadPreviewView from "./ThreadPreviewView";
import LastPostController from "./LastPost";



class ThreadPreviewController extends React.Component {

    render() {
        const {
            thread_path,
            thread_data,
        } = this.props;

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
