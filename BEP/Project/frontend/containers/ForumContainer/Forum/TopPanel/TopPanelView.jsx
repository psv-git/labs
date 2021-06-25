import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Button,
    Input,
} from "semantic-ui-react";



const TopPanelView = ({
    handleThreadCreateClick,
}) => (
        <Segment.Group
            className="forum-container-top-panel-wrapper"
            horizontal={true}
        >
            <Segment
                textAlign="left"
                basic={true}
            >
                <Button
                    size="medium"
                    color="blue"
                    content="New thread"
                    onClick={handleThreadCreateClick}
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
    handleThreadCreateClick: PropTypes.func.isRequired,
};



export default TopPanelView;
