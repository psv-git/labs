import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
} from "semantic-ui-react";



const ForumView = ({
    children,
    is_visible,
}) => (
        <Segment
            className={is_visible ? "forum-container-content-wrapper" : "hidden-element"}
        >
            {children}
        </Segment>
    );



ForumView.propTypes = {
    is_visible: PropTypes.bool.isRequired,
};



export default ForumView;
