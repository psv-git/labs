import React from "react";
import {
    connect,
} from "react-redux";

import {
    toggleThreadCreateFormVisible,
} from "../../../../redux/actions";

import TopPanelView from "./TopPanelView";



class TopPanelController extends React.Component {

    constructor(props) {
        super(props);

        this.handleThreadCreateClick = this.handleThreadCreateClick.bind(this);
    };


    handleThreadCreateClick() {
        const {
            toggleThreadCreateFormVisible,
        } = this.props;

        toggleThreadCreateFormVisible();
    };


    render() {
        return (
            <TopPanelView
                handleThreadCreateClick={this.handleThreadCreateClick}
            />
        );
    };

};



const actions = {
    toggleThreadCreateFormVisible,
};



export default connect(null, actions)(TopPanelController);
