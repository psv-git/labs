import {
    fetch_data,
    make_query_string,
} from "../../scripts/utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/";

// paths ======================================================================

const create_forum_path = api_v0_prefix + "create/forum";

const get_forums_path = api_v0_prefix + "get/forums";
const get_forum_path = api_v0_prefix + "get/forum/";

const update_forum_path = api_v0_prefix + "update/forum/";
const partial_update_forum_path = api_v0_prefix + "partial-update/forum/";

const destroy_forum_path = api_v0_prefix + "destroy/forum/";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function createForum(token, forum_data, timeout = default_timeout) {
    const options = {
        method: "POST",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(forum_data),
    };

    let url = create_forum_path;

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


// available query_params: 
// count: <int>
export async function getForums(token, query_params = null, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_forums_path;
    url += make_query_string(query_params);

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



export async function getForum(token, forum_id, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_forum_path + forum_id;

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



export async function updateForum(token, forum_id, update_data, is_partial = true, timeout = default_timeout) {
    const options = {
        method: is_partial ? "PATCH" : "PUT",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(update_data),
    };

    let url = is_partial ? partial_update_forum_path : update_forum_path;
    url += forum_id;

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



export async function deleteForum(token, forum_id, timeout = default_timeout) {
    const options = {
        method: "DELETE",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = destroy_forum_path + forum_id;

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return true;
            } else {
                return false;
            };
        })
        .catch((err) => {
            console.log(err);
            return false;
        });
};
