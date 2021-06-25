import React from "react";
import PropTypes from "prop-types";

import {
    Header,
    GridRow,
    GridColumn,
} from "semantic-ui-react";



const ForumHeaderView = ({
    forum_name,
}) => (
        <GridRow
            className="forum-container-forum-header"
        >
            <GridColumn
                width="16"
                verticalAlign="middle"
                textAlign="center"
            >
                <Header
                    as="h3"
                    content={forum_name}
                />
            </GridColumn>
        </GridRow>
    );



ForumHeaderView.propTypes = {
    forum_name: PropTypes.string.isRequired,
};



export default ForumHeaderView;
