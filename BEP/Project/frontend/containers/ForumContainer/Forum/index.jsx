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
    getThreads,
} from "../../scripts/thread";

import ForumView from "./ForumView";
import TopPanelController from "./TopPanel";
import ForumWrapperController from "./ForumWrapper";
import ForumHeaderController from "./ForumHeader";
import ForumBodyController from "./ForumBody";
import BottomPanelController from "./BottomPanel";
import ThreadCreateFormController from "./ThreadCreateForm";



class ForumController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            is_ready: false,

            pages_data: {
                active_page: 1,
                pages_count: 0,
            },
            threads_data: [],
        };

        this.top_page_ref = React.createRef();
        this.bottom_page_ref = React.createRef();

        this.updateThreadsData = this.updateThreadsData.bind(this);
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


    updateThreadsData(active_page = 1) {
        const {
            forum_data,
            auth: { access_token, },
        } = this.props;

        this.setReadyState(false);

        getThreads(access_token, { parent_id: forum_data.id, parent_model_id: forum_data.model, page: active_page })
            .then((data) => {
                if (data) {
                    this.setState({
                        threads_data: data.results,
                        pages_data: data.pages_data,
                    });
                    this.updateBreadcrumbData();
                };
                this.setReadyState(true);
            });
    };


    componentDidMount() {
        const {
            pages_data: { active_page, },
        } = this.state;

        this.updateThreadsData(active_page);
    };


    render() {
        const {
            forum_path,
            forum_data,
            forum: { is_thread_create_form_visible, }
        } = this.props;
        const {
            is_ready,
            threads_data,
            pages_data,
        } = this.state;

        if (is_ready) {
            return (
                <React.Fragment>
                    <ForumView
                        is_visible={!is_thread_create_form_visible}
                    >
                        <TopPanelController />

                        <ForumWrapperController>
                            <ForumHeaderController
                                forum_name={forum_data.name}
                            />
                            <ForumBodyController
                                forum_path={forum_path}
                                threads_data={threads_data}
                            />
                        </ForumWrapperController>

                        <BottomPanelController
                            pages_data={pages_data}
                            updateThreadsData={this.updateThreadsData}
                        />
                    </ForumView>

                    <ThreadCreateFormController
                        is_visible={is_thread_create_form_visible}
                        forum_id={forum_data.id}
                        forum_model_id={forum_data.model}
                        updateThreadsData={this.updateThreadsData}
                    />
                </React.Fragment>
            );
        } else {
            return null;
        };
    };

};



ForumController.propTypes = {
    forum_path: PropTypes.string.isRequired,
    forum_data: PropTypes.object.isRequired,
    breadcrumb_data: PropTypes.array,
};



ForumController.defaultProps = {
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



export default connect(mapStateToProps, actions)(ForumController);
