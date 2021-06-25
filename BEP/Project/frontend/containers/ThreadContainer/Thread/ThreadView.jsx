import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
} from "semantic-ui-react";



const ThreadView = ({
    children,
}) => (
        <Segment
            className="thread-container-content-wrapper"
        >
            {children}
        </Segment>
    );



export default ThreadView;
