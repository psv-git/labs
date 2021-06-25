import {
    SET_USER_DATA,
    CLEAR_USER_DATA,
} from "../actions_types";



export const setUserData = (data) => ({
    type: SET_USER_DATA,
    data,
});



export const clearUserData = () => ({
    type: CLEAR_USER_DATA,
});
