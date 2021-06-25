import React from "react";
import {
    connect,
} from "react-redux";

import {
    logIn,
} from "../../../redux/actions";
import {
    getToken,
} from "../../../scripts/auth";

import LoginFormView from "./LoginFormView";
import HelpWindowController from "./HelpWindow";



class LoginFormController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            auth_error: false,
            username_field: {
                value: "",
                error: false,
            },
            password_field: {
                value: "",
                error: false,
            },
        };

        this.handleInputChange = this.handleInputChange.bind(this);
        this.handleLoginClick = this.handleLoginClick.bind(this);
    };


    checkInput(username_field_value, password_field_value) {
        var is_input_error = false;

        if (username_field_value === "") {
            this.setState({
                username_field: {
                    value: "",
                    error: true,
                },
            });
            is_input_error = true;
        };

        if (password_field_value === "") {
            this.setState({
                password_field: {
                    value: "",
                    error: true,
                },
            });
            is_input_error = true;
        };

        return !is_input_error;
    };


    handleInputChange(e) {
        const {
            auth_error,
        } = this.state;

        const name = e.target.name;
        const value = e.target.value;

        if (auth_error) {
            this.setState({
                auth_error: false,
            });
        };

        this.setState({
            [name]: {
                value: value,
                error: false,
            },
        });
    };


    handleLoginClick(e) {
        const {
            username_field,
            password_field,
        } = this.state;

        if (this.checkInput(username_field.value, password_field.value)) {
            const {
                logIn,
            } = this.props;

            getToken(username_field.value, password_field.value)
                .then((data) => {
                    if (data) {
                        logIn(data.access, data.refresh, data.user_id);
                    } else {
                        this.setState({
                            auth_error: true,
                        });
                    };
                });
        };
    };


    render() {
        const {
            auth_error,
            username_field,
            password_field,
        } = this.state;

        return (
            <LoginFormView
                auth_state={auth_error}
                username_field_state={username_field.error}
                password_field_state={password_field.error}
                handleInputChange={this.handleInputChange}
                handleLoginClick={this.handleLoginClick}
            >
                <HelpWindowController />
            </LoginFormView>
        );
    };

};



const actions = {
    logIn,
};



export default connect(null, actions)(LoginFormController);
