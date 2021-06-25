import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    addForum,
} from "../../../../redux/actions";

import {
    ThreadPreviewController
} from "../../../SharedComponents";

import ForumBodyView from "./ForumBodyView";



class ForumBodyController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            forum_path: "/forum/",
            thread_path: "/thread/",
        };
    };


    addThisForum() {
        const {
            forum_id,
            addForum,
        } = this.props;

        addForum(forum_id, true);
    };


    componentWillMount() {
        this.addThisForum();
    };

    render() {
        const {
            parent_path,
            forum_id,
            threads_data,
            forum: { forum_threads_visible_by_id, },
        } = this.props;
        const {
            forum_path,
            thread_path,
        } = this.state;

        if (threads_data) {
            // console.log(forum_threads_visible_by_id);
            return (
                <ForumBodyView
                    is_visible={true}
                >
                    {threads_data.map((thread_data) => (
                        <ThreadPreviewController
                            key={thread_data.id}
                            thread_path={parent_path + forum_path + forum_id + thread_path + thread_data.id}
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
    parent_path: PropTypes.string.isRequired,
    forum_id: PropTypes.number.isRequired,
    threads_data: PropTypes.array.isRequired,
};



const mapStateToProps = (state) => ({
    forum: state.forum,
});


const actions = {
    addForum,
};



export default connect(mapStateToProps, actions)(ForumBodyController);
