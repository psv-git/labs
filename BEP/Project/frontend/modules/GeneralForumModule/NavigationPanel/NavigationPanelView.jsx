import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Breadcrumb,
} from "semantic-ui-react";



const NavigationPanelView = ({
    children,
}) => (
        <Segment
            id="forums-module-nav-panel-wrapper"
        >
            <Breadcrumb
                size="large"
            >
                {children}
            </Breadcrumb>
        </Segment>
    );



export default NavigationPanelView;
