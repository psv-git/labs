import React from "react";
import PropTypes from "prop-types";

import {
    Form,
    Segment,
    Message,
    Icon,
} from "semantic-ui-react";



const LoginFormView = ({
    children,
    auth_state,
    username_field_state,
    password_field_state,
    handleInputChange,
    handleLoginClick,
}) => (
        <Form
            id="login-page-module-login-form-wrapper"
        >
            <Segment
                id="login-page-module-login-form"
                attached="top"
            >
                <Form.Input
                    className="login-page-module-login-form-item"
                    name="username_field"
                    placeholder="Username"
                    icon="user"
                    iconPosition="left"
                    fluid={true}
                    error={username_field_state}
                    onChange={handleInputChange}
                />

                <Form.Input
                    className="login-page-module-login-form-item"
                    name="password_field"
                    placeholder="Password"
                    type="password"
                    icon="lock"
                    iconPosition="left"
                    fluid={true}
                    error={password_field_state}
                    onChange={handleInputChange}
                />

                <Message
                    icon={true}
                    negative={true}
                    hidden={!auth_state}
                >
                    <Message.Content>
                        <Icon
                            name='exclamation'
                        />
                        Incorrect username or password
                    </Message.Content>
                </Message>

                <Form.Button
                    className="login-page-module-login-form-item"
                    content="Login"
                    size="large"
                    color="blue"
                    fluid={true}
                    onClick={handleLoginClick}
                />
            </Segment>

            {children}
        </Form>
    );



LoginFormView.propTypes = {
    auth_state: PropTypes.bool.isRequired,
    username_field_state: PropTypes.bool.isRequired,
    password_field_state: PropTypes.bool.isRequired,
    handleInputChange: PropTypes.func.isRequired,
    handleLoginClick: PropTypes.func.isRequired,
};



export default LoginFormView;
