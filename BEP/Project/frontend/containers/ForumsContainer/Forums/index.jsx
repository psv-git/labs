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
    getForums,
} from "../../scripts/forum";
import {
    getThreads,
} from "../../scripts/thread";

import ForumsView from "./ForumsView";
import TopPanelController from "./TopPanel";
import ForumsWrapperController from "./ForumsWrapper";
import ForumHeaderController from "./ForumHeader";
import ForumBodyController from "./ForumBody";



class ForumsController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            is_ready: false,

            forums_data: [],
            threads_data: [],
        };

        this.updateForumsData = this.updateForumsData.bind(this);
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


    updateForumsData() {
        const {
            auth: { access_token, },
            parent_id,
            parent_model_id,
        } = this.props;

        this.setReadyState(false);

        getForums(access_token, { parent_id: parent_id, parent_model_id: parent_model_id, })
            .then((data) => {
                if (data) {
                    this.setState({
                        forums_data: data,
                    });
                    if (data.length) {
                        this.updateThreadsData(data);
                    } else {
                        this.setReadyState(true);
                    };
                    this.updateBreadcrumbData();
                } else {
                    this.setReadyState(true);
                };
            });
    };


    updateThreadsData(forums_data) {
        const {
            auth: { access_token, },
        } = this.props;

        var forums_count = forums_data.length;
        var loaded_forums = 0;

        forums_data.map((forum_data) => (
            getThreads(access_token, { parent_id: forum_data.id, parent_model_id: forum_data.model, count_from_begin: 5 })
                .then((data) => {
                    let threads_data = [...this.state.threads_data];
                    if (data) {
                        threads_data[forum_data.id] = data;
                    } else {
                        threads_data[forum_data.id] = [];
                    };
                    this.setState({
                        threads_data: threads_data,
                    });
                    loaded_forums += 1;
                    if (loaded_forums === forums_count) {
                        this.setReadyState(true);
                    };
                })
        ));
    };


    componentDidMount() {
        this.updateForumsData();
    };


    render() {
        const {
            parent_id,
            parent_model_id,
            parent_path,
        } = this.props;
        const {
            is_ready,
            forums_data,
            threads_data
        } = this.state;

        if (is_ready) {
            return (
                <ForumsView>
                    <TopPanelController
                        parent_id={parent_id}
                        parent_model_id={parent_model_id}
                        updateForumsData={this.updateForumsData}
                    />

                    {forums_data.map((forum_data) => (
                        <ForumsWrapperController
                            key={forum_data.id}
                        >
                            <ForumHeaderController
                                parent_path={parent_path}
                                forum_id={forum_data.id}
                                forum_name={forum_data.name}
                            />
                            <ForumBodyController
                                parent_path={parent_path}
                                forum_id={forum_data.id}
                                threads_data={threads_data[forum_data.id]}
                            />
                        </ForumsWrapperController>
                    ))}
                </ForumsView>
            );
        } else {
            return null;
        };
    };

};



ForumsController.propTypes = {
    parent_id: PropTypes.number.isRequired,
    parent_model_id: PropTypes.number.isRequired,
    parent_path: PropTypes.string.isRequired,
    breadcrumb_data: PropTypes.array.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



const actions = {
    setBreadcrumbData,
    setContentLoadState,
};



export default connect(mapStateToProps, actions)(ForumsController);
