import {
    SET_CONTENT_LOAD_STATE,
} from "../actions_types";



const initial_state = {
    content_loading: false,
};



export default function mainpage(state = initial_state, action = {}) {
    switch (action.type) {
        case SET_CONTENT_LOAD_STATE:
            return {
                ...state,
                content_loading: action.load_state
            };
        default:
            return state;
    };
};
