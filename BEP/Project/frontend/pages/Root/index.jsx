import React from "react";
import {
    connect,
} from "react-redux";
import {
    BrowserRouter,
    Route,
    Switch,
    Redirect,
} from "react-router-dom";

import MainPage from "../MainPage";
import LoginPage from "../LoginPage";

import "semantic-ui-css/semantic.min.css";
import "../styles/root.css"



class Root extends React.Component {

    render() {
        const {
            auth: { is_auth, },
        } = this.props;

        return (
            <BrowserRouter>
                <Switch>
                    <Route
                        exact path="/login"
                        component={LoginPage}
                    />
                    {is_auth ?
                        <Route
                            path="/"
                            component={MainPage}
                        /> :
                        <Redirect
                            to="/login"
                        />
                    }
                </Switch>
            </BrowserRouter>
        );
    };

};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps)(Root);
