import React from "react";

import {
    Segment,
} from "semantic-ui-react";



const GeneralForumModuleView = ({
    children,
}) => (
        <Segment
            id="forums-module-content-wrapper"
        >
            {children}
        </Segment>
    );



export default GeneralForumModuleView;
