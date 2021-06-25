import React from "react";
import PropTypes from "prop-types";

import {
    ThreadPreviewController
} from "../../../SharedComponents";

import ForumBodyView from "./ForumBodyView";



class ForumBodyController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            thread_path: "/thread/",
        };
    };


    render() {
        const {
            forum_path,
            threads_data,
        } = this.props;
        const {
            thread_path,
        } = this.state;

        if (threads_data) {
            return (
                <ForumBodyView>
                    {threads_data.map((thread_data) => (
                        <ThreadPreviewController
                            key={thread_data.id}
                            thread_path={forum_path + thread_path + thread_data.id}
                            thread_data={thread_data}
                        />
                    ))}
                </ForumBodyView>
            );
        } else {
            return null;
        };
    };

};



ForumBodyController.propTypes = {
    forum_path: PropTypes.string.isRequired,
    threads_data: PropTypes.array.isRequired,
};



export default ForumBodyController;
