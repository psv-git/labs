import React from "react";

import ForumsWrapperView from "./ForumsWrapperView";



class ForumsWrapperController extends React.Component {

    render() {
        const {
            children,
        } = this.props;

        return (
            <ForumsWrapperView>
                {children}
            </ForumsWrapperView>
        );
    };

};



export default ForumsWrapperController;
