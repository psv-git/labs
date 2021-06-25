import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Button,
    Icon,
    Form,
    Dropdown,
    Accordion,
    Input,
} from "semantic-ui-react";



const font_sizes_list = [
    { key: '8', text: '8', value: '8' },
    { key: '12', text: '12', value: '12' },
    { key: '16', text: '16', value: '16' },
    { key: '20', text: '20', value: '20' },
    { key: '24', text: '24', value: '24' },
    { key: '28', text: '28', value: '28' },
];



const ThreadCreateFormView = ({
    is_visible,
    thread_title_field_state,
    handleInputChange,
    handleAcceptClick,
    handleCancelClick,
}) => (
        <Segment
            className={
                is_visible ? "forum-container-content-wrapper" : "hidden-element"
            }
        >
            <Segment basic>
                <Input
                    name="thread_title_field"
                    placeholder="Thread title"
                    fluid={true}
                    error={thread_title_field_state}
                    onChange={handleInputChange}
                />
            </Segment>

            <Accordion>
                <Accordion.Title active={false} content="Add voting" />
                <Accordion.Content active={false}>
                    <Form.Input
                        required placeholder='Voting title'
                        fluid={true}
                        error={true}
                    />
                </Accordion.Content>
            </Accordion>

            <Form>
                <Form.Field>
                    <Button.Group>
                        <Dropdown
                            icon='text height'
                            text=' '
                            scrolling={true}
                            button={true}
                            options={font_sizes_list}
                        />
                    </Button.Group>{' '}

                    <Button.Group>
                        <Button
                            icon="bold"
                        />
                        <Button
                            icon="italic"
                        />
                        <Button
                            icon="underline"
                        />
                        <Button
                            icon='strikethrough'
                        />
                        <Button
                            icon='subscript'
                        />
                        <Button
                            icon='superscript'
                        />
                    </Button.Group>{' '}

                    <Button.Group>
                        <Button
                            icon='align left'
                        />
                        <Button
                            icon='align center'
                        />
                        <Button
                            icon='align right'
                        />
                    </Button.Group>{' '}

                    <Button.Group>
                        <Button
                            icon='list ol'
                        />
                        <Button
                            icon='list ul'
                        />
                    </Button.Group>{' '}

                    <Button.Group>
                        <Button
                            icon='linkify'
                        />
                        <Button
                            icon='unlinkify'
                        />
                    </Button.Group>{' '}

                    <Button.Group>
                        <Button
                            icon='image'
                        />
                        <Button
                            icon='video'
                        />
                        <Button
                            icon='file'
                        />
                    </Button.Group>
                </Form.Field>

                <Form.TextArea
                    name="post_text_field"
                    placeholder="Post text here..."
                    rows="6"
                    onChange={handleInputChange}
                />
            </Form>

            <Segment
                textAlign="center"
                basic
            >
                <Button.Group>
                    <Button
                        animated="fade"
                        size="medium"
                        color="green"
                        onClick={handleAcceptClick}
                    >
                        <Button.Content
                            content="Accept"
                            visible={true}
                        />
                        <Button.Content
                            hidden
                            content={
                                <Icon
                                    name="check"
                                />
                            }
                        />
                    </Button>

                    <Button.Or
                        text="or"
                    />

                    <Button
                        animated="fade"
                        size="medium"
                        color="red"
                        onClick={handleCancelClick}
                    >
                        <Button.Content
                            content="Cancel"
                            visible={true}
                        />
                        <Button.Content
                            hidden={true}
                            content={
                                <Icon
                                    name="times"
                                />
                            }
                        />
                    </Button>
                </Button.Group>
            </Segment>
        </Segment>
    );



ThreadCreateFormView.propTypes = {
    is_visible: PropTypes.bool.isRequired,
    handleInputChange: PropTypes.func.isRequired,
    handleAcceptClick: PropTypes.func.isRequired,
    handleCancelClick: PropTypes.func.isRequired,
};



export default ThreadCreateFormView;
