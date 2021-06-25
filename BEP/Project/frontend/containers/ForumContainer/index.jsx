import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";
import {
    Route,
    Switch,
} from "react-router-dom";

import {
    setContentLoadState,
} from "../../redux/actions";
import {
    getForum,
} from "../scripts/forum";

import {
    ThreadContainer,
} from "../../containers";

import Forum from "./Forum";

import "../styles/forum-container.css";



class ForumContainer extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            forum_path: "/forum/",

            forum_data: null,
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
            forum_path,
            forum_data: { id, name, },
        } = this.state;

        if (parent_breadcrumb_data) {
            let breadcrumb_data = parent_breadcrumb_data.concat([{
                name: name,
                path: parent_path + forum_path + id,
            }]);

            this.setState({
                self_breadcrumb_data: breadcrumb_data,
            });
        };
    };


    updateForumData() {
        const {
            auth: { access_token, },
            match: { params: { forum_id, }, }
        } = this.props;

        this.setLoadState(true);

        getForum(access_token, forum_id)
            .then((data) => {
                if (data && data != {}) {
                    this.setState({
                        forum_data: data,
                    });
                    this.setBreadcrumbData();
                } else {
                    this.setLoadState(false);
                };
            });
    };


    componentDidMount() {
        this.updateForumData();
    };


    render() {
        const {
            parent_path,
        } = this.props;
        const {
            forum_path,
            forum_data,
            self_breadcrumb_data,
        } = this.state;

        if (forum_data) {
            return (
                <Switch>
                    <Route
                        exact path={parent_path + forum_path + forum_data.id}
                        render={(props) =>
                            <Forum
                                {...props}
                                forum_path={parent_path + forum_path + forum_data.id}
                                forum_data={forum_data}
                                breadcrumb_data={self_breadcrumb_data}
                            />
                        }
                    />

                    <Route
                        render={(props) =>
                            <ThreadContainer
                                {...props}
                                parent_path={parent_path + forum_path + forum_data.id}
                                parent_breadcrumb_data={self_breadcrumb_data}
                            />
                        }
                    />
                </Switch>
            );
        } else {
            return null;
        };
    };
};



ForumContainer.propTypes = {
    parent_path: PropTypes.string.isRequired,
    parent_breadcrumb_data: PropTypes.array,
};



ForumContainer.defaultProps = {
    parent_breadcrumb_data: null,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



const actions = {
    setContentLoadState,
};



export default connect(mapStateToProps, actions)(ForumContainer);
