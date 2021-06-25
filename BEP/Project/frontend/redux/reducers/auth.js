import {
    LOGIN,
    LOGOUT
} from "../actions_types";



const initial_state = {
    is_auth: false,
    access_token: null,
    refresh_token: null,
    user_id: null,
};



export default function auth(state = initial_state, action = {}) {
    switch (action.type) {
        case LOGIN:
            return {
                ...state,
                is_auth: true,
                access_token: action.access_token,
                refresh_token: action.refresh_token,
                user_id: action.user_id,
            };

        case LOGOUT:
            return {
                ...state,
                is_auth: false,
                access_token: null,
                refresh_token: null,
                user_id: null,
            };

        default:
            return state;
    };
};
