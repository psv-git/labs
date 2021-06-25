import {
    fetch_data,
    make_query_string,
} from "../../scripts/utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/";

// paths ======================================================================

const create_thread_path = api_v0_prefix + "create/thread";

const get_threads_path = api_v0_prefix + "get/threads";
const get_thread_path = api_v0_prefix + "get/thread/";

const update_thread_path = api_v0_prefix + "update/thread/";
const partial_update_thread_path = api_v0_prefix + "partial-update/thread/";

const destroy_thread_path = api_v0_prefix + "destroy/thread/";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function createThread(token, thread_data, timeout = default_timeout) {
    const options = {
        method: "POST",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(thread_data),
    };

    let url = create_thread_path;

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
// count: <int>
export async function getThreads(token, query_params = null, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_threads_path;
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



export async function getThread(token, thread_id, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = get_thread_path + thread_id;

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



export async function updateThread(token, thread_id, update_data, is_partial = true, timeout = default_timeout) {
    const options = {
        method: is_partial ? "PATCH" : "PUT",
        headers: {
            "Authorization": "Bearer " + token,
            "Content-Type": "application/json",
        },
        body: JSON.stringify(update_data),
    };

    let url = opt.is_partial ? partial_update_thread_path : update_thread_path;
    url += thread_id;

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



export async function deleteThread(token, thread_id, timeout = default_timeout) {
    const options = {
        method: "DELETE",
        headers: {
            "Authorization": "Bearer " + token,
        },
    };

    let url = delete_thread_path + thread_id;

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
