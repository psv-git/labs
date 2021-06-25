import React from "react";

import {
    Segment,
    Grid,
} from "semantic-ui-react";



const ForumWrapperView = ({
    children,
}) => (
        <Segment
            color="blue"
        >
            <Grid>
                {children}
            </Grid>
        </Segment>
    );



export default ForumWrapperView;
