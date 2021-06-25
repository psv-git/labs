import React from "react";
import {
    connect,
} from "react-redux";

import NavigationPanelView from "./NavigationPanelView";
import NavigationPanelItemView from "./NavigationPanelItemView";



class NavigationPanelController extends React.Component {

    render() {
        const {
            forum: { breadcrumb_data, },
        } = this.props;

        return (
            <NavigationPanelView>
                {breadcrumb_data.map((item_data, index) => (
                    <NavigationPanelItemView
                        key={index}
                        name={item_data.name}
                        path={item_data.path}
                    />
                ))}
            </NavigationPanelView>
        );
    };

};



const mapStateToProps = (state) => ({
    forum: state.forum,
});



export default connect(mapStateToProps, null)(NavigationPanelController);
