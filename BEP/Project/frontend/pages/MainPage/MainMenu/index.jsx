import React from "react";
import PropTypes from "prop-types";

import MainMenuView from "./MainMenuView";
import MainMenuItemController from "./MainMenuItem";
import UserMenuController from "./UserMenu";



const menu_list = [
    { id: 1, path: "/profile", icon: "home" },
    { id: 2, path: "/messages", icon: "mail" },
    { id: 3, path: "/groups", icon: "group" },
    { id: 4, path: "/courses", icon: "graduation cap" },
    { id: 5, path: "/general-forum/forums", icon: "talk" },
];



class MainMenuController extends React.Component {

    render() {
        return (
            <MainMenuView>
                {menu_list.map((item_data) => (
                    <MainMenuItemController
                        key={item_data.id}
                        path={item_data.path}
                        icon={item_data.icon}
                        animate={false}
                    />
                ))}

                <UserMenuController />
            </MainMenuView>
        );
    };

};



export default MainMenuController;
