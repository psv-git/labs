import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Button,
    Input,
} from "semantic-ui-react";



const TopPanelView = ({
    forum_name_field_state,
    handleInputChange,
    handleForumCreateClick,
}) => (
        <Segment.Group
            className="forums-container-top-panel-wrapper"
            horizontal={true}
        >
            <Segment
                textAlign="left"
                basic={true}
            >
                <Input
                    name="forum_name_field"
                    placeholder="Forum name..."
                    error={forum_name_field_state}
                    onChange={handleInputChange}
                    action={
                        <Button
                            size="medium"
                            color="blue"
                            content="Add forum"
                            onClick={handleForumCreateClick}
                        />
                    }
                />
            </Segment>

        </Segment.Group>
    );



TopPanelView.propTypes = {
    forum_name_field_state: PropTypes.bool.isRequired,
    handleInputChange: PropTypes.func.isRequired,
    handleForumCreateClick: PropTypes.func.isRequired,
};



export default TopPanelView;
