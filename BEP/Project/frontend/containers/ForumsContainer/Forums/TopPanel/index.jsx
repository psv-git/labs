import React from "react";
import PropTypes from "prop-types";
import {
    connect,
} from "react-redux";

import {
    createForum,
} from "../../../scripts/forum";

import TopPanelView from "./TopPanelView";



class TopPanelController extends React.Component {

    constructor(props) {
        super(props);

        this.state = {
            forum_name_field: {
                value: "",
                error: false,
            },
        };

        this.handleInputChange = this.handleInputChange.bind(this);
        this.handleForumCreateClick = this.handleForumCreateClick.bind(this);
    };


    checkInput(forum_name_field_value) {
        var is_input_error = false;

        if (forum_name_field_value === "") {
            this.setState({
                forum_name_field: {
                    value: "",
                    error: true,
                },
            });
            is_input_error = true;
        };

        return !is_input_error;
    };


    handleInputChange(e) {
        const name = e.target.name;
        const value = e.target.value;

        this.setState({
            [name]: {
                value: value,
                error: false,
            },
        });
    };


    handleForumCreateClick() {
        const {
            forum_name_field,
        } = this.state;

        if (this.checkInput(forum_name_field.value)) {
            const {
                auth: { access_token, },
                updateForumsData,
                parent_id,
                parent_model_id,
            } = this.props;

            let forum_data = {
                parent_id: parent_id,
                parent_model: parent_model_id,
                name: forum_name_field.value,
            };

            createForum(access_token, forum_data)
                .then((state) => {
                    if (state) {
                        updateForumsData();
                    };
                });
        };
    };


    render() {
        const {
            forum_name_field,
        } = this.state;

        return (
            <TopPanelView
                forum_name_field_state={forum_name_field.error}
                handleInputChange={this.handleInputChange}
                handleForumCreateClick={this.handleForumCreateClick}
            />
        );
    };

};



TopPanelController.propTypes = {
    parent_id: PropTypes.number.isRequired,
    parent_model_id: PropTypes.number.isRequired,
    updateForumsData: PropTypes.func.isRequired,
};



const mapStateToProps = (state) => ({
    auth: state.auth,
});



export default connect(mapStateToProps)(TopPanelController);
