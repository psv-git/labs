import {
    fetch_data,
    make_query_string,
} from "../../scripts/utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/";

// paths ======================================================================

const create_post_path = api_v0_prefix + "create/post";

const get_posts_path = api_v0_prefix + "get/posts/";
const get_post_path = api_v0_prefix + "get/post/";

const update_post_path = api_v0_prefix + "update/post/";
const partial_update_post_path = api_v0_prefix + "partial-update/post/";

const delete_post_path = api_v0_prefix + "delete/post/";
const hide_post_path = api_v0_prefix + "hide/post/";
const pin_post_path = api_v0_prefix + "pin/post/";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function createPost(token, post_data, timeout = default_timeout) {
    const options = {
        method: "POST",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(post_data),
    };

    let url = create_post_path;

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return response.json();
            } else {
                return null;
            };
        })
        .catch((err) => {
            console.log(err);
            return null;
        });
};



// available query_params: 
// page: <int>,
// count_from_begin: <int>
export async function getPosts(token, thread_id, query_params = null, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_posts_path + thread_id;
    url += make_query_string(query_params);

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return response.json();
            } else {
                return null;
            };
        })
        .catch((err) => {
            console.log(err);
            return null;
        });
};



export async function getPost(token, post_id, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_post_path + post_id;

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return response.json();
            } else {
                return null;
            };
        })
        .catch((err) => {
            console.log(err);
            return null;
        });
};



export async function updatePost(token, post_id, update_data, is_partial = true, timeout = default_timeout) {
    const options = {
        method: is_partial ? "PATCH" : "PUT",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(update_data),
    };

    let url = is_partial ? partial_update_post_path : update_post_path;
    url += post_id;

    return await fetch_data(url, options, timeout)
        .then((response) => {
            if (response.ok) {
                return response.json();
            } else {
                return null;
            };
        })
        .catch((err) => {
            console.log(err);
            return null;
        });
};



export async function deletePost(token, post_id, timeout = default_timeout) {
    const options = {
        method: "PATCH",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = delete_post_path + post_id;

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



export async function hidePost(token, post_id, timeout = default_timeout) {
    const options = {
        method: "PATCH",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = hide_post_path + post_id;

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



export async function pinPost(token, post_id, timeout = default_timeout) {
    const options = {
        method: "PATCH",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = pin_post_path + post_id;

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
