import {
    fetch_data,
} from "./utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/";

// paths ======================================================================

export const get_modules_url = api_v0_prefix + "get/modules";
export const get_module_url = api_v0_prefix + "get/module/";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function getModules(auth_token, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + auth_token,
        },
    };

    const url = get_modules_url;

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



export async function getModule(auth_token, module_id = null, module_name = null, timeout = default_timeout) {
    const options = {
        method: "GET",
        headers: {
            "Authorization": "Bearer " + auth_token,
        },
    };

    let url = get_module_url;
    if (module_id) {
        url += module_id;
    } else {
        url += module_name;
    };

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
