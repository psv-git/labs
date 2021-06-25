import React from "react";

import {
    Button,
    Header,
    Modal,
} from "semantic-ui-react";



const trigger = (
    <Button
        icon="help circle"
        attached="bottom"
        basic={true}
        fluid={true}
    />
);



const HelpWindowView = () => (
    <Modal
        trigger={trigger}
    >
        <Modal.Header>
            <p>
                Frequently Asked Questions
            </p>
        </Modal.Header>

        <Modal.Content
            image={true}
        >
            <Modal.Description>
                <Header>
                    <p>
                        Question: I forgot my login.
                    </p>
                </Header>

                <p>
                    Answer: ...
                </p>

                <Header>
                    <p>
                        Question: I forgot my password.
                    </p>
                </Header>

                <p>
                    Answer: ...
                </p>
            </Modal.Description>
        </Modal.Content>
    </Modal>
);



export default HelpWindowView;
