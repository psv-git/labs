import React from "react";
import PropTypes from "prop-types";

import {
    Table,
    GridRow,
} from "semantic-ui-react";




const ForumBodyView = ({
    children,
    is_visible,
}) => (
        <GridRow
            className={is_visible ? "forums-container-forum-body" : "hidden-element"}
        >
            <Table
                attached="bottom"
                celled={true}
            >
                <Table.Header>
                    <Table.Row>
                        <Table.HeaderCell
                            width="11"
                            content="Thread title"
                        />

                        <Table.HeaderCell
                            width="1"
                            textAlign="center"
                            content="Messages"
                        />

                        <Table.HeaderCell
                            width="4"
                            textAlign="center"
                            content="Last post"
                        />
                    </Table.Row>
                </Table.Header>
                <Table.Body>
                    {children}
                </Table.Body>
            </Table>
        </GridRow>
    );



ForumBodyView.propTypes = {
    is_visible: PropTypes.bool.isRequired,
};



export default ForumBodyView;
