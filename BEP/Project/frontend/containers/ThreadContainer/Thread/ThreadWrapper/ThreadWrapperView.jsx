import React from "react";

import {
    Segment,
    ItemGroup,
} from "semantic-ui-react";



const ThreadWrapperView = ({
    children,
}) => (
        <Segment
            className="thread-container-thread-wrapper"
            color="blue"
        >
            <ItemGroup
                className="thread-container-posts-wrapper"
            >
                {children}
            </ItemGroup>
        </Segment>
    );



export default ThreadWrapperView;
