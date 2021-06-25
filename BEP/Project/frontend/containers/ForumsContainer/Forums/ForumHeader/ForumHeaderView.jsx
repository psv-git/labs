import React from "react";
import PropTypes from "prop-types";
import {
    NavLink
} from "react-router-dom";

import {
    Checkbox,
    Header,
    GridRow,
    GridColumn
} from "semantic-ui-react";



const ForumHeaderView = ({
    forum_path,
    forum_name,
    handleToggleThreadsClick
}) => (
        <GridRow
            className="forums-container-forum-header"
        >
            <GridColumn
                width="9"
                verticalAlign="middle"
            >
                <NavLink
                    to={forum_path}
                >
                    <Header
                        as="h3"
                        floated="left"
                        color="blue"
                        content={forum_name}
                    />
                </NavLink>
            </GridColumn>

            <GridColumn
                width="7"
                verticalAlign="middle"
                textAlign="right"
            >
                <Checkbox
                    toggle={true}
                    defaultChecked={true}
                    onChange={handleToggleThreadsClick}
                />
            </GridColumn>
        </GridRow>
    );



ForumHeaderView.propTypes = {
    forum_path: PropTypes.string.isRequired,
    forum_name: PropTypes.string.isRequired,
    handleToggleThreadsClick: PropTypes.func.isRequired
};



export default ForumHeaderView;
