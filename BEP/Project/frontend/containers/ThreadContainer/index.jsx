import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    setContentLoadState,
} from "../../redux/actions";
import {
    getThread,
} from "../scripts/thread";

import Thread from "./Thread";

import "../styles/thread-container.css";



class ThreadContainer extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            thread_path: "/thread/",

            thread_data: null,
            self_breadcrumb_data: null,
        };
    };


    setLoadState(load_state) {
        const {
            setContentLoadState,
        } = this.props;

        setContentLoadState(load_state);
    };


    setBreadcrumbData() {
        const {
            parent_path,
            parent_breadcrumb_data,
        } = this.props;
        const {
            thread_path,
            thread_data: { id, title, },
        } = this.state;

        if (parent_breadcrumb_data) {
            let breadcrumb_data = parent_breadcrumb_data.concat([{
                name: title,
                path: parent_path + thread_path + id,
            }]);

            this.setState({
                self_breadcrumb_data: breadcrumb_data,
            });
        };
    };


    updateThreadData() {
        const {
            auth: { access_token, },
            match: { params: { thread_id, }, },
        } = this.props;

        this.setLoadState(false);

        getThread(access_token, thread_id)
            .then((data) => {
                if (data && data != {}) {
                    this.setState({
                        thread_data: data,
                    });
                    this.setBreadcrumbData();
                } else {
                    this.setLoadState(true);
                };
            });
    };


    componentDidMount() {
        this.updateThreadData();
    };


    render() {
        const {
            parent_path,
        } = this.props;
        const {
            thread_path,
            thread_data,
            self_breadcrumb_data,
        } = this.state;

        if (thread_data) {
            return (
                <Thread
                    thread_path={parent_path + thread_path + thread_data.id}
                    thread_data={thread_data}
                    breadcrumb_data={self_breadcrumb_data}
                />
            );
        } else {
            return null;
        };
    };
};



ThreadContainer.propTypes = {
    parent_path: PropTypes.string.isRequired,
    parent_breadcrumb_data: PropTypes.array,
};



ThreadContainer.defaultProps = {
    parent_breadcrumb_data: null,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



const actions = {
    setContentLoadState,
};



export default connect(mapStateToProps, actions)(ThreadContainer);
