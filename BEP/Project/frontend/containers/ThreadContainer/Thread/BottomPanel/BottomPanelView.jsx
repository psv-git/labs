import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Pagination,
} from "semantic-ui-react";



const BottomPanelView = ({
    pages_data,
    handlePaginationChange,
}) => (
        <Segment.Group
            className={pages_data.pages_count > 1 ? "thread-container-bottom-panel-wrapper" : "hidden-element"}
            horizontal={true}
        >
            <Segment
                textAlign="center"
                basic={true}
            >
                <Pagination
                    size="small"
                    boundaryRange={1}
                    siblingRange={0}
                    activePage={pages_data.active_page}
                    totalPages={pages_data.pages_count}
                    onPageChange={handlePaginationChange}
                />
            </Segment>
        </Segment.Group>
    );



BottomPanelView.propTypes = {
    pages_data: PropTypes.object.isRequired,
    handlePaginationChange: PropTypes.func.isRequired,
};



export default BottomPanelView;
