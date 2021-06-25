import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    togglePostCreateFormVisible,
} from "../../../../redux/actions";

import TopPanelView from "./TopPanelView";



class TopPanelController extends React.Component {

    constructor(props) {
        super(props);

        this.handlePostCreateClick = this.handlePostCreateClick.bind(this);
    };


    handlePostCreateClick() {
        const {
            // bottom_page_ref,
            togglePostCreateFormVisible,
        } = this.props;

        togglePostCreateFormVisible();

        //     if (bottom_page_ref.current) {
        //         let moduleContentWrapper = document.getElementById("forums-module-content-wrapper");
        //         moduleContentWrapper.scrollTo(0, bottom_page_ref.current.offsetTop);
        //     };
    };


    render() {
        return (
            <TopPanelView
                handlePostCreateClick={this.handlePostCreateClick}
            />
        );
    };

};



const actions = {
    togglePostCreateFormVisible,
};



export default connect(null, actions)(TopPanelController);
