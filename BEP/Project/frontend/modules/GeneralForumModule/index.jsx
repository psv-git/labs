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
    getModule,
} from "../../scripts/module";

import {
    ForumsContainer,
    NotFoundContainer,
} from "../../containers";

import GeneralForumModuleView from "./GeneralForumModuleView";
import NavigationPanelController from "./NavigationPanel";

import "../styles/general-forum-module.css";



class GeneralForumModuleController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            is_ready: false,

            module_name: "general-forum",

            module_data: null,
        };
    };


    getModuleData() {
        const {
            auth: { access_token, },
        } = this.props;
        const {
            module_name,
        } = this.state;

        getModule(access_token, null, module_name)
            .then((data) => {
                if (data) {
                    this.setState({
                        is_ready: true,
                        module_data: data,
                    });
                };
            });
    };


    componentDidMount() {
        this.getModuleData();
    };


    render() {
        const {
            root_path,
        } = this.props;
        const {
            is_ready,
            module_data,
        } = this.state;

        if (is_ready) {

            let module_path = root_path + module_data.name;

            return (
                <React.Fragment>
                    <NavigationPanelController />

                    <GeneralForumModuleView>
                        <Switch>
                            <Route
                                exact path={module_path + "/forums"}
                                render={(props) =>
                                    <ForumsContainer
                                        {...props}
                                        parent_id={module_data.id}
                                        parent_model_id={module_data.model_id}
                                        parent_path={module_path}
                                    />
                                }
                            />

                            <Route
                                exact path={module_path + "/forum/:forum_id"}
                                render={(props) =>
                                    <ForumsContainer
                                        {...props}
                                        parent_id={module_data.id}
                                        parent_model_id={module_data.model_id}
                                        parent_path={module_path}
                                    />
                                }
                            />

                            <Route
                                exact path={module_path + "/forum/:forum_id/thread/:thread_id"}
                                render={(props) =>
                                    <ForumsContainer
                                        {...props}
                                        parent_id={module_data.id}
                                        parent_model_id={module_data.model_id}
                                        parent_path={module_path}
                                    />
                                }
                            />

                            <Route
                                render={(props) =>
                                    <NotFoundContainer
                                        {...props}
                                    />
                                }
                            />
                        </Switch>
                    </GeneralForumModuleView>
                </React.Fragment>
            );
        } else {
            return null;
        };
    };

};



GeneralForumModuleController.propTypes = {
    root_path: PropTypes.string.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps, null)(GeneralForumModuleController);
