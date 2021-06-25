import React from "react";
import PropTypes from "prop-types";

import {
    MenuMenu,
    Image,
    Dropdown,
} from "semantic-ui-react";



const UserMenuView = ({
    children,
    user_first_name,
    user_last_name,
    user_avatar_path,
    handleLogoutClick,
}) => (
        <MenuMenu
            id="main-page-main-menu-user-menu-item"
            position="right"
        >
            <Dropdown
                trigger={
                    <Image
                        avatar
                        size="mini"
                        circular={true}
                        src={user_avatar_path}
                    />
                }
                pointing="top right"
                icon={null}
            >
                <Dropdown.Menu>
                    <Dropdown.Header
                        content={user_first_name + " " + user_last_name}
                    />

                    <Dropdown.Divider />

                    {children}

                    <Dropdown.Item
                        icon="log out"
                        content="Logout"
                        onClick={handleLogoutClick}
                    />
                </Dropdown.Menu>
            </Dropdown>

            {/* <Dropdown item text='Language'>
                <Dropdown.Menu>
                    <Dropdown.Item>English</Dropdown.Item>
                    <Dropdown.Item>Russian</Dropdown.Item>
                    <Dropdown.Item>Spanish</Dropdown.Item>
                </Dropdown.Menu>
            </Dropdown> */}
        </MenuMenu>
    );



UserMenuView.propTypes = {
    user_first_name: PropTypes.string.isRequired,
    user_last_name: PropTypes.string.isRequired,
    user_avatar_path: PropTypes.string.isRequired,
    handleLogoutClick: PropTypes.func.isRequired,
};



export default UserMenuView;
