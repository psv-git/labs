import React from "react";

import {
    Table,
    GridRow,
} from "semantic-ui-react";



const ForumBodyView = ({
    children,
}) => (
        <GridRow
            className="forum-container-forum-body"
        >
            <Table
                attached="bottom"
                celled={true}
            >
                <Table.Header>
                    <Table.Row>
                        <Table.HeaderCell
                            width="10"
                            content="Thread title"
                        />

                        <Table.HeaderCell
                            width="2"
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



export default ForumBodyView;
