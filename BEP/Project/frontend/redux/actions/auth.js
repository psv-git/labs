import {
    LOGIN,
    LOGOUT,
} from "../actions_types";



export const logIn = (access_token, refresh_token, user_id) => ({
    type: LOGIN,
    access_token,
    refresh_token,
    user_id,
});



export const logOut = () => ({
    type: LOGOUT,
});
