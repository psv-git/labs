import {
    fetch_data,
} from "./utils";



// prefixes ===================================================================

const api_v0_prefix = "/api/v0/"

// paths ======================================================================

const get_token_url = api_v0_prefix + "get/token";
const refresh_token_url = api_v0_prefix + "refresh/token";
const verify_token_url = api_v0_prefix + "verify/token";

// defaults ===================================================================

const default_timeout = 5000;



// ============================================================================

export async function getToken(username, password, timeout = default_timeout) {
    const options = {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            username: username,
            password: password,
        }),
    };

    const url = get_token_url;

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
