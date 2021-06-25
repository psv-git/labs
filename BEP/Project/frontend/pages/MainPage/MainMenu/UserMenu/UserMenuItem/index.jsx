import React from "react";
import PropTypes from "prop-types";

import UserMenuItemView from "./UserMenuItemView";



class UserMenuItemController extends React.Component {

    render() {
        const {
            path,
            icon,
            content,
        } = this.props;

        return (
            <UserMenuItemView
                path={path}
                icon={icon}
                content={content}
            />
        );
    };

};



UserMenuItemController.propTypes = {
    path: PropTypes.string.isRequired,
    icon: PropTypes.string.isRequired,
    content: PropTypes.string.isRequired,
};



export default UserMenuItemController;
