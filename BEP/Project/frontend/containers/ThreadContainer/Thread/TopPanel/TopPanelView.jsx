import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Button,
    Input,
} from "semantic-ui-react";



const TopPanelView = ({
    handlePostCreateClick,
}) => (
        <Segment.Group
            className="thread-container-top-panel-wrapper"
            horizontal={true}
        >
            <Segment
                textAlign="left"
                basic={true}
            >
                <Button
                    size="medium"
                    color="blue"
                    content="New post"
                    onClick={handlePostCreateClick}
                />
            </Segment>

            <Segment
                textAlign="right"
                basic
            >
                <Input
                    placeholder="Search..."
                    size="small"
                    action={
                        { icon: "search" }
                    }
                />
            </Segment>

        </Segment.Group>
    );



TopPanelView.propTypes = {
    handlePostCreateClick: PropTypes.func.isRequired,
};



export default TopPanelView;
