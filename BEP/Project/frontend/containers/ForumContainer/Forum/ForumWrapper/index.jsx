import React from "react";

import ForumWrapperView from "./ForumWrapperView";



class ForumWrapperController extends React.Component {

    render() {
        const {
            children,
        } = this.props;

        return (
            <ForumWrapperView>
                {children}
            </ForumWrapperView>
        );
    };

};



export default ForumWrapperController;
