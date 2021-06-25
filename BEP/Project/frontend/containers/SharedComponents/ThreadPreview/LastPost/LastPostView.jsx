import React from "react";
import PropTypes from "prop-types";
import {
    NavLink,
} from "react-router-dom";

import {
    Grid,
    Icon,
    Header,
} from "semantic-ui-react";


const LastPostView = ({
    post_data,
}) => (
        <Grid>
            <Grid.Row
                className="shared-components-last-post-row"
            >
                <Grid.Column>
                    <Header
                        as='h4'
                    >
                        {post_data.creator.userprofile.first_name} {post_data.creator.userprofile.last_name}
                    </Header>
                </Grid.Column>
            </Grid.Row>

            <Grid.Row
                className="shared-components-last-post-row"
            >
                <Grid.Column
                    width="12"
                >
                    {post_data.modified_date}
                </Grid.Column>

                <Grid.Column
                    width="4"
                >
                    <NavLink
                        to={"ololo"}
                    >
                        <Icon
                            name="arrow alternate circle right"
                        />
                    </NavLink>
                </Grid.Column>
            </Grid.Row>
        </Grid>
    );



LastPostView.propTypes = {
    post_data: PropTypes.object.isRequired,
};



export default LastPostView;
