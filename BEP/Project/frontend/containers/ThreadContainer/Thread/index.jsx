import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    setBreadcrumbData,
    setContentLoadState,
} from "../../../redux/actions";
import {
    getPosts,
} from "../../scripts/post";

import {
    ScrollAnchor,
} from "../../SharedComponents";

import ThreadView from "./ThreadView";
import ThreadWrapperController from "./ThreadWrapper";
import PostWrapperController from "./PostWrapper";
import PostCreateFormController from "./PostCreateForm";
import TopPanelController from "./TopPanel";
import BottomPanelController from "./BottomPanel";



class ThreadController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            is_ready: false,

            pages_data: {
                active_page: null,
                page_size: null,
                pages_count: null,
                items_on_page: null,
                is_last_page_full: null,
            },
            posts_data: [],
        };

        this.top_page_ref = React.createRef();
        this.bottom_page_ref = React.createRef();

        this.updatePostsData = this.updatePostsData.bind(this);
    };


    setReadyState(ready_state) {
        const {
            setContentLoadState,
        } = this.props;

        setContentLoadState(!ready_state);

        this.setState({
            is_ready: ready_state,
        });
    };


    updateBreadcrumbData() {
        const {
            breadcrumb_data,
            setBreadcrumbData,
        } = this.props;

        if (breadcrumb_data) {
            setBreadcrumbData(breadcrumb_data);
        };
    };


    preparePostsData(posts_data) {
        posts_data.map(function (post_data) {
            post_data["created_date"] = new Date(post_data.created_date).toLocaleString();
            post_data["modified_date"] = new Date(post_data.modified_date).toLocaleString();
        });
    };


    updatePostsData(active_page = 1) {
        const {
            thread_data: { id, },
            auth: { access_token, },
        } = this.props;

        this.setReadyState(false);

        getPosts(access_token, id, { page: active_page })
            .then((data) => {
                if (data) {
                    this.preparePostsData(data.results);
                    this.setState({
                        posts_data: data.results,
                        pages_data: data.pages_data,
                    });
                    this.updateBreadcrumbData();
                };
                this.setReadyState(true);
            });
    };


    componentDidMount() {
        this.updatePostsData();
    };


    render() {
        const {
            thread_data,
            forum: { is_post_create_form_visible, },
        } = this.props;
        const {
            is_ready,
            posts_data,
            pages_data,
        } = this.state;

        if (is_ready) {
            return (
                <ThreadView>
                    <ScrollAnchor
                        this_ref={this.top_page_ref}
                    />

                    <TopPanelController />

                    <ThreadWrapperController>
                        <PostCreateFormController
                            is_visible={is_post_create_form_visible}
                            thread_id={thread_data.id}
                            pages_data={pages_data}
                            updatePostsData={this.updatePostsData}
                        />

                        {posts_data.map((post_data) => (
                            <PostWrapperController
                                key={post_data.id}
                                post_data={post_data}
                                pages_data={pages_data}
                                updatePostsData={this.updatePostsData}
                            />
                        ))}
                    </ThreadWrapperController>

                    <BottomPanelController
                        pages_data={pages_data}
                        updatePostsData={this.updatePostsData}
                    />

                    <ScrollAnchor
                        this_ref={this.bottom_page_ref}
                    />
                </ThreadView>
            );
        } else {
            return null;
        };
    };

};



ThreadController.propTypes = {
    thread_path: PropTypes.string.isRequired,
    thread_data: PropTypes.object.isRequired,
    breadcrumb_data: PropTypes.array,
};



ThreadController.defaultProps = {
    breadcrumb_data: null,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
    forum: state.forum,
});



const actions = {
    setBreadcrumbData,
    setContentLoadState,
};



export default connect(mapStateToProps, actions)(ThreadController);
