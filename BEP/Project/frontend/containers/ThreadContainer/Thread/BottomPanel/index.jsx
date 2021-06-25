import React from "react";
import PropTypes from "prop-types";

import BottomPanelView from "./BottomPanelView";



class BottomPanelController extends React.Component {

    constructor(props) {
        super(props);

        this.handlePaginationChange = this.handlePaginationChange.bind(this);
    };


    handlePaginationChange(e, { activePage }) {
        const {
            updatePostsData,
        } = this.props;

        updatePostsData(activePage);
    };


    render() {
        const {
            pages_data,
        } = this.props;

        return (
            <BottomPanelView
                pages_data={pages_data}
                handlePaginationChange={this.handlePaginationChange}
            />
        );
    };

};



BottomPanelController.propTypes = {
    pages_data: PropTypes.object.isRequired,
    updatePostsData: PropTypes.func.isRequired,
};



export default BottomPanelController;
