import {
    SET_CONTENT_LOAD_STATE,
} from "../actions_types";



export const setContentLoadState = (load_state) => ({
    type: SET_CONTENT_LOAD_STATE,
    load_state,
});
