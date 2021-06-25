import React from "react";

import ThreadWrapperView from "./ThreadWrapperView";



class ThreadWrapperController extends React.Component {

    render() {
        const {
            children,
        } = this.props;

        return (
            <ThreadWrapperView>
                {children}
            </ThreadWrapperView>
        );
    };

};



export default ThreadWrapperController;
