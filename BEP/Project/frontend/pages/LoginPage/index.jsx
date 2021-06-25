import React from "react";
import {
    connect,
} from "react-redux";
import {
    Redirect,
} from "react-router-dom";

import LoginPageView from "./LoginPageView";
import LoginFormController from "./LoginForm";

import "../styles/login-page.css";



class LoginPageController extends React.Component {

    render() {
        const {
            auth: { is_auth, },
        } = this.props;

        if (is_auth) {
            return (
                <Redirect
                    to="/profile"
                />
            );
        } else {
            return (
                <LoginPageView>
                    <LoginFormController />
                </LoginPageView>
            );
        };
    };

};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps, null)(LoginPageController);
