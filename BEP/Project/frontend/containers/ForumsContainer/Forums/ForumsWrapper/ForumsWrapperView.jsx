import React from "react";

import {
    Segment,
    Grid,
} from "semantic-ui-react";



const ForumsWrapperView = ({
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



export default ForumsWrapperView;
