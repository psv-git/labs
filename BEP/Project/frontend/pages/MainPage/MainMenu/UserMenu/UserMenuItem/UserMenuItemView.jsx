import React from "react";
import PropTypes from "prop-types";
import {
    NavLink,
} from "react-router-dom";

import {
    DropdownItem,
} from "semantic-ui-react";



const UserMenuItemView = ({
    path,
    icon,
    content,
}) => (
        <DropdownItem
            as={NavLink}
            to={path}
            icon={icon}
            content={content}
        />
    );



UserMenuItemView.propTypes = {
    path: PropTypes.string.isRequired,
    icon: PropTypes.string.isRequired,
    content: PropTypes.string.isRequired,
};



export default UserMenuItemView;
