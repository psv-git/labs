import React from "react";
import PropTypes from "prop-types";

import ForumHeaderView from "./ForumHeaderView";



class ForumHeaderController extends React.Component {

    render() {
        const {
            forum_name,
        } = this.props;

        return (
            <ForumHeaderView
                forum_name={forum_name}
            />
        );
    };

};



ForumHeaderController.propTypes = {
    forum_name: PropTypes.string.isRequired,
};



export default ForumHeaderController;
