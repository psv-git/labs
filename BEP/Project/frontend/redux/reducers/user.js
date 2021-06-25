import {
    SET_USER_DATA,
    CLEAR_USER_DATA,
} from "../actions_types";



const initial_state = {
    user_data: null,
};



export default function user(state = initial_state, action = {}) {
    switch (action.type) {
        case SET_USER_DATA:
            return {
                ...state,
                user_data: action.data
            };

        case CLEAR_USER_DATA:
            return {
                ...state,
                user_data: {}
            };

        default:
            return state;
    };
};
