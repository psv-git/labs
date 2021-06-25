import React from "react";
import PropTypes from "prop-types";

import {
    Menu,
    Container,
} from "semantic-ui-react";



const MainMenuView = ({
    children,
}) => (
        <Menu
            id="main-page-main-menu-wrapper"
            fixed="top"
            icon="labeled"
            size="small"
        >
            <Container
                id="main-page-main-menu"
            >
                {children}
            </Container>
        </Menu>
    );



export default MainMenuView;
