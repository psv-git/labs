import React from "react";

import {
    Segment,
    Header,
} from "semantic-ui-react";



const NotFoundView = () => (
    <Segment
        id="not-found-module-wrapper"
        textAlign="center"
        basic={true}
    >
        <Header
            content="CONTENT NOT FOUND"
        />
    </Segment>
);



export default NotFoundView;
