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
    setBreadcrumbData,
} from "../../redux/actions";

import {
    ForumContainer,
} from "../../containers";

import Forums from "./Forums";

import "../styles/forums-container.css";



class ForumsContainer extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            forums_path: "/forums",

            self_breadcrumb_data: [{
                name: "Forums",
                path: this.props.parent_path + "/forums",
            }],
        };
    };


    render() {
        const {
            parent_id,
            parent_model_id,
            parent_path,
        } = this.props;
        const {
            forums_path,
            self_breadcrumb_data,
        } = this.state;

        return (
            <Switch>
                <Route
                    exact path={parent_path + forums_path}
                    render={(props) =>
                        <Forums
                            {...props}
                            parent_id={parent_id}
                            parent_model_id={parent_model_id}
                            parent_path={parent_path}
                            breadcrumb_data={self_breadcrumb_data}
                        />
                    }
                />

                <Route
                    render={(props) =>
                        <ForumContainer
                            {...props}
                            parent_path={parent_path}
                            parent_breadcrumb_data={self_breadcrumb_data}
                        />
                    }
                />
            </Switch>
        );
    };

};



ForumsContainer.propTypes = {
    parent_id: PropTypes.number.isRequired,
    parent_model_id: PropTypes.number.isRequired,
    parent_path: PropTypes.string.isRequired,
};



const mapStateToProps = (state) => ({
    forum: state.forum,
});



const actions = {
    setBreadcrumbData,
};



export default connect(mapStateToProps, actions)(ForumsContainer);
