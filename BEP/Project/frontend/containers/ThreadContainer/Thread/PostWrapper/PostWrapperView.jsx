import React from "react";
import PropTypes from "prop-types";

import {
    Item,
    Icon,
    Label,
    Button,
    Container,
    Popup,
} from "semantic-ui-react";


function get_post_class(data) {
    if (data.is_deleted) {
        return "thread-container-deleted-post-wrapper";
    } else if (data.is_hidden) {
        return "thread-container-hidden-post-wrapper";
    } else if (data.is_pinned) {
        return "thread-container-pinned-post-wrapper";
    } else {
        return "thread-container-post-wrapper";
    };
};



const PostWrapperView = ({
    post_data,
    handleDeleteClick,
    handleHideClick,
    handlePinClick,
    handleEditClick,
    handleQuoteClick,
    handleLikeClick,
    handleReportClick,
}) => (
        <Item
            className={get_post_class(post_data)}
        >
            <Item.Image
                size="mini"
                avatar
                src={post_data.creator.userprofile.avatar_path}
            />

            <Item.Content>
                <Item.Header>
                    {post_data.creator.userprofile.first_name} {post_data.creator.userprofile.last_name}
                </Item.Header>

                <Item.Meta>
                    <p><b>created:</b> {post_data.created_date}</p>
                    {/* <p>modified: {post_data.modified_date}</p> */}
                </Item.Meta>

                <Item.Description>
                    <Container
                        className="thread-container-post-content"
                        content={post_data.content}
                    />
                </Item.Description>

                <Item.Extra>
                    <Button.Group
                        basic={true}
                    >
                        <Button
                            onClick={handleDeleteClick}
                            icon={
                                <Icon
                                    name={post_data.is_deleted ? "undo" : "trash alternate"}
                                    color="red"
                                />
                            }
                        />

                        <Button
                            className={post_data.is_deleted ? "hidden-element" : ""}
                            onClick={handleHideClick}
                            icon={
                                <Icon
                                    name={post_data.is_hidden ? "unhide" : "hide"}
                                    color="yellow"
                                />
                            }
                        />

                        <Button
                            className={post_data.is_hidden || post_data.is_deleted ? "hidden-element" : ""}
                            onClick={handlePinClick}
                            icon={
                                <Icon
                                    name="pin"
                                    color="blue"
                                />
                            }
                        />
                    </Button.Group>

                    <Button.Group
                        className={post_data.is_hidden || post_data.is_deleted ? "hidden-element" : ""}
                        basic={true}
                    >
                        <Button
                            icon="edit"
                            onClick={handleEditClick}
                        />

                        <Button
                            icon="quote left"
                            onClick={handleQuoteClick}
                        />

                        <Button
                            icon="reply"
                            onClick={handleEditClick}
                        />
                    </Button.Group>

                    <Button
                        as="div"
                        className={post_data.is_hidden || post_data.is_deleted ? "hidden-element" : ""}
                        floated="right"
                        labelPosition="right"
                        onClick={handleLikeClick}
                    >
                        <Popup
                            on="hover"
                            position="top center"
                            content="Like it..."
                            trigger={
                                <Button
                                    basic={true}
                                    icon={
                                        <Icon
                                            name="thumbs up"
                                            color="green"
                                        />
                                    }
                                />
                            }
                        />

                        <Label
                            basic={true}
                            content={post_data.likes_count}
                        />
                    </Button>

                    <Popup
                        on="hover"
                        position="top center"
                        content="Report it..."
                        trigger={
                            <Button
                                className={post_data.is_hidden || post_data.is_deleted ? "hidden-element" : ""}
                                floated="right"
                                basic={true}
                                circular={true}
                                icon={
                                    <Icon
                                        name="exclamation"
                                        color="red"
                                    />
                                }
                                onClick={handleReportClick}
                            />
                        }
                    />
                </Item.Extra>
            </Item.Content>
        </Item>
    );



PostWrapperView.propTypes = {
    post_data: PropTypes.object.isRequired,
    handleDeleteClick: PropTypes.func.isRequired,
    handleHideClick: PropTypes.func.isRequired,
    handlePinClick: PropTypes.func.isRequired,
    handleEditClick: PropTypes.func.isRequired,
    handleQuoteClick: PropTypes.func.isRequired,
    handleLikeClick: PropTypes.func.isRequired,
    handleReportClick: PropTypes.func.isRequired,
};



export default PostWrapperView;
