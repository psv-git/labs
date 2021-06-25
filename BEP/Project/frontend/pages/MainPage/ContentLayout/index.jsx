import React from "react";
import {
    Route,
    Switch,
    withRouter,
} from "react-router-dom";
import {
    connect,
} from "react-redux";

import {
    NotFoundModule,
    GeneralForumModule,
} from "../../../modules";

import ContentLayoutView from "./ContentLayoutView";



const modules = {
    general_forum: "general-forum",
};



class ContentLayoutController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            root_path: "/",
        };
    };


    render() {
        const {
            mainpage: { content_loading, },
        } = this.props;
        const {
            root_path,
        } = this.state;

        return (
            <ContentLayoutView
                content_loading={false}
            >
                <Switch>
                    <Route
                        path={root_path + modules.general_forum}
                        render={(props) =>
                            <GeneralForumModule
                                {...props}
                                root_path={root_path}
                            />
                        }
                    />

                    <Route
                        render={(props) =>
                            <NotFoundModule
                                {...props}
                            />
                        }
                    />
                </Switch>
            </ContentLayoutView>
        );
    };

};



const mapStateToProps = (state) => ({
    mainpage: state.mainpage,
});



export default withRouter(connect(mapStateToProps)(ContentLayoutController));
