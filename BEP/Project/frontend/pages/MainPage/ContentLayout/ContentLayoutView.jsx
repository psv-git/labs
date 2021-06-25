import React from "react";
import PropTypes from "prop-types";

import {
    Segment,
    Dimmer,
    Loader,
} from "semantic-ui-react";



const ContentLayoutView = ({
    children,
    content_loading,
}) => (
        <div
            id="main-page-content-wrapper"
        >
            <Dimmer.Dimmable
                id="main-page-content"
                as={Segment}
                dimmed={content_loading}
            >
                {children}

                <Dimmer
                    active={content_loading}
                    inverted={true}
                >
                    <Loader
                        size="big"
                    />
                </Dimmer>
            </Dimmer.Dimmable >
        </div>
    );



ContentLayoutView.propTypes = {
    content_loading: PropTypes.bool.isRequired,
};



export default ContentLayoutView;
