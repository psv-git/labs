import React from "react";
import PropTypes from "prop-types";
import {
    NavLink,
} from "react-router-dom";

import {
    BreadcrumbDivider,
} from "semantic-ui-react";



const NavigationPanelItemView = ({
    name,
    path,
}) => (
        <React.Fragment>
            <BreadcrumbDivider
                icon="right chevron"
            />
            <NavLink
                to={path}
            >
                {name}
            </NavLink>
        </React.Fragment>
    );



NavigationPanelItemView.propTypes = {
    name: PropTypes.string.isRequired,
    path: PropTypes.string.isRequired,
};



export default NavigationPanelItemView;
