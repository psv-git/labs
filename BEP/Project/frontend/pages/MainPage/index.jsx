import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    setUserData,
} from "../../redux/actions";
import {
    getUser,
} from "../../scripts/user";

import MainPageView from "./MainPageView";
import MainMenuController from "./MainMenu";
import ContentLayoutController from "./ContentLayout";

import "../styles/main-page.css";



class MainPageController extends React.Component {

    updateUserData() {
        const {
            auth: { access_token, user_id, },
            setUserData,
        } = this.props;

        getUser(access_token, user_id)
            .then((data) => {
                if (data) {
                    setUserData(data.userprofile);
                };
            });
    };


    componentDidMount() {
        this.updateUserData();
    };


    render() {
        return (
            <MainPageView>
                <MainMenuController />
                <ContentLayoutController />
            </MainPageView>
        );
    };

};



const mapStateToProps = (state) => ({
    auth: state.auth,
    user: state.user,
});



const actions = {
    setUserData,
};



export default connect(mapStateToProps, actions)(MainPageController);
