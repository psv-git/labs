import React from "react";
import {
    connect,
} from "react-redux";

import {
    logOut,
    clearUserData,
} from "../../../../redux/actions";

import UserMenuView from "./UserMenuView";
import UserMenuItemController from "./UserMenuItem";



const menu_list = [
    { id: 1, path: "/test", icon: "bug", content: "Test" },
    { id: 2, path: "/support", icon: "question", content: "Support" },
    { id: 3, path: "/profile/settings", icon: "settings", content: "Settings" },
];



class UserMenuController extends React.Component {

    constructor(props) {
        super(props);

        this.handleLogoutClick = this.handleLogoutClick.bind(this);
    };


    handleLogoutClick(e) {
        const {
            logOut,
            clearUserData,
        } = this.props;

        logOut();
        clearUserData();
    };


    render() {
        const {
            user: { user_data, },
        } = this.props;

        if (user_data) {
            return (
                <UserMenuView
                    user_first_name={user_data.first_name}
                    user_last_name={user_data.last_name}
                    user_avatar_path={user_data.avatar_path}
                    handleLogoutClick={this.handleLogoutClick}
                >
                    {menu_list.map((item_data) => (
                        <UserMenuItemController
                            key={item_data.id}
                            path={item_data.path}
                            icon={item_data.icon}
                            content={item_data.content}
                        />
                    ))}
                </UserMenuView>
            );
        } else {
            return null;
        };
    };

};



const mapStateToProps = (state) => ({
    user: state.user,
});



const actions = {
    logOut,
    clearUserData,
};



export default connect(mapStateToProps, actions)(UserMenuController);
