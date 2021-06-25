import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    toggleThreadsListVisible,
} from "../../../../redux/actions";

import ForumHeaderView from "./ForumHeaderView";



class ForumHeaderController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            forum_path: "/forum/",
        };

        this.handleToggleThreadsClick = this.handleToggleThreadsClick.bind(this);
    };

    handleToggleThreadsClick(e) {
        const {
            forum_id,
            toggleThreadsListVisible,
        } = this.props;

        toggleThreadsListVisible(forum_id);
    };


    render() {
        const {
            parent_path,
            forum_id,
            forum_name,
        } = this.props;
        const {
            forum_path,
        } = this.state;

        return (
            <ForumHeaderView
                forum_path={parent_path + forum_path + forum_id}
                forum_name={forum_name}
                handleToggleThreadsClick={this.handleToggleThreadsClick}
            />
        );
    };

};



ForumHeaderController.propTypes = {
    parent_path: PropTypes.string.isRequired,
    forum_id: PropTypes.number.isRequired,
    forum_name: PropTypes.string.isRequired,
};



const actions = {
    toggleThreadsListVisible,
};



export default connect(null, actions)(ForumHeaderController);
