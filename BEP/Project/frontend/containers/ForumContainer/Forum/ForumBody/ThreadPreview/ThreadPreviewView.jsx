import React from "react";
import PropTypes from "prop-types";
import {
    NavLink,
} from "react-router-dom";

import {
    TableRow,
    TableCell,
} from "semantic-ui-react";



const ThreadPreviewView = ({
    children,
    thread_path,
    thread_title,
    posts_count,
}) => (
        <TableRow>
            <TableCell
                content={
                    <NavLink
                        to={thread_path}
                    >
                        {thread_title}
                    </NavLink>
                }
            />
            <TableCell
                textAlign="center"
                content={posts_count}
            />
            <TableCell
                textAlign="center"
                content={children}
            />
        </TableRow>
    );



ThreadPreviewView.propTypes = {
    children: PropTypes.element.isRequired,
    thread_title: PropTypes.string.isRequired,
    posts_count: PropTypes.number.isRequired,
};



export default ThreadPreviewView;
