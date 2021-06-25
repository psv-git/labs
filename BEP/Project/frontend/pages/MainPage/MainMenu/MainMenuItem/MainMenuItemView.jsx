import React from "react";
import PropTypes from "prop-types";
import {
    NavLink,
} from "react-router-dom";

import {
    MenuItem,
    Icon,
    Transition,
} from "semantic-ui-react";



const MainMenuItemView = ({
    path,
    icon,
    visible,
    duration,
}) => (
        <MenuItem
            className="main-page-main-menu-item"
        >
            <NavLink
                to={path}
            >
                <Transition
                    animation="tada"
                    duration={duration}
                    visible={visible}
                >
                    <Icon
                        size="large"
                        inverted={true}
                        name={icon}
                    />
                </Transition>
            </NavLink>
        </MenuItem>
    );



MainMenuItemView.propTypes = {
    path: PropTypes.string.isRequired,
    icon: PropTypes.string.isRequired,
    visible: PropTypes.bool.isRequired,
    duration: PropTypes.number.isRequired,
};



export default MainMenuItemView;
