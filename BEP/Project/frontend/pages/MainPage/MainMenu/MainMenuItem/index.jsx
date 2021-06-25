import React from "react";
import PropTypes from "prop-types";

import MainMenuItemView from "./MainMenuItemView";



class MainMenuItemController extends React.Component {

    // handleAnimation = () => {
    //     const { visible, color } = this.state
    //     this.setState({
    //         visible: !visible,
    //         color: !color
    //     });
    // };


    // componentDidMount() {
    // setInterval(this.handleAnimation, 2000)
    // };


    render() {
        const {
            path,
            icon,
            animate,
        } = this.props;

        return (
            <MainMenuItemView
                path={path}
                icon={icon}
                visible={true}
                duration={1000}
            />
        );
    };

};



MainMenuItemController.propTypes = {
    path: PropTypes.string.isRequired,
    icon: PropTypes.string.isRequired,
    animate: PropTypes.bool.isRequired,
};



export default MainMenuItemController;
