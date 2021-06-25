import {
    fetch_data,
    make_query_string,
} from "./utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/";

// paths ======================================================================

const create_user_url = api_v0_prefix + "create/user";

const get_users_url = api_v0_prefix + "get/users";
const get_user_url = api_v0_prefix + "get/user/";

const update_user_url = api_v0_prefix + "update/user/";
const partial_update_user_url = api_v0_prefix + "partial-update/user/";

const delete_user_url = api_v0_prefix + "delete/user/";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function getUser(auth_token, user_id, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + auth_token,
        },
    };

    const url = get_user_url + user_id;

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return response.json();
            };
            return null;
        })
        .catch((err) => {
            console.log(err);
            return null;
        });
};
