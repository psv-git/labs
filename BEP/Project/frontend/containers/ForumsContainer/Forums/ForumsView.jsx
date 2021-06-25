import React from "react";

import {
    Segment,
} from "semantic-ui-react";



const ForumsView = ({
    children,
}) => (
        <Segment
            className="forums-container-content-wrapper"
        >
            {children}
        </Segment>
    );



export default ForumsView;
