import React from "react";

import {
    NotFoundContainer
} from "../../containers";



class NotFoundModuleController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            module_name: "not-found",
        };
    };


    render() {
        return (
            <NotFoundContainer />
        );
    };

};



export default NotFoundModuleController;
