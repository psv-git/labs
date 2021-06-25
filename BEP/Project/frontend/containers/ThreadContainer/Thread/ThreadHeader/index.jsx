import React from "react";
import PropTypes from "prop-types";

import ThreadHeaderView from "./ThreadHeaderView";



class ThreadHeaderController extends React.Component {

    render() {
        const {
            thread_title,
        } = this.props;

        return (
            <ThreadHeaderView
                thread_title={thread_title}
            />
        );
    };

};



ThreadHeaderController.propTypes = {
    thread_title: PropTypes.string.isRequired,
};



export default ThreadHeaderController;
