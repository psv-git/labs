import React from "react";
import PropTypes from "prop-types";

import {
    Header,
    GridRow,
    GridColumn,
} from "semantic-ui-react";



const ThreadHeaderView = ({
    thread_title,
}) => (
        <GridRow
            className="thread-container-thread-header"
        >
            <GridColumn
                width="16"
                verticalAlign="middle"
                textAlign="center"
            >
                <Header
                    as="h3"
                    content={thread_title}
                />
            </GridColumn>
        </GridRow>
    );



ThreadHeaderView.propTypes = {
    thread_title: PropTypes.string.isRequired,
};



export default ThreadHeaderView;
