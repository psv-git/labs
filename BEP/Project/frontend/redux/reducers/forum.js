import {
    SET_BREADCRUMB_DATA,

    TOGGLE_THREAD_CREATE_FORM_VISIBLE,
    TOGGLE_POST_CREATE_FORM_VISIBLE,

    ADD_FORUM,
    TOGGLE_THREADS_LIST_VISIBLE,
} from "../actions_types";



const initial_state = {
    is_thread_create_form_visible: false,
    is_post_create_form_visible: false,

    forums_id_list: [],
    forum_threads_visible_by_id: {},

    breadcrumb_data: [], // array of {"name", "path"} items
};



export default function forum(state = initial_state, action = {}) {
    switch (action.type) {
        case SET_BREADCRUMB_DATA:
            // console.log("before: ", state.breadcrumb_data)
            // console.log("after:", action.breadcrumb_data)
            return {
                ...state,
                breadcrumb_data: action.breadcrumb_data,
            };

        case TOGGLE_THREAD_CREATE_FORM_VISIBLE:
            return {
                ...state,
                is_thread_create_form_visible: !state.is_thread_create_form_visible,
            };

        case TOGGLE_POST_CREATE_FORM_VISIBLE:
            return {
                ...state,
                is_post_create_form_visible: !state.is_post_create_form_visible,
            };

        case ADD_FORUM:
            var id_list;
            const is_exist = state.forums_id_list.includes(action.id);
            if (is_exist) {
                id_list = state.forums_id_list.slice();
            } else {
                id_list = state.forums_id_list.concat(action.id);
            };
            return {
                ...state,
                forums_id_list: id_list,
                forum_threads_visible_by_id: {
                    ...state.forum_threads_visible_by_id,
                    [action.id]: action.is_visible,
                }
            };

        case TOGGLE_THREADS_LIST_VISIBLE:
            const is_visible = state.forum_threads_visible_by_id[action.id];
            return {
                ...state,
                forum_threads_visible_by_id: {
                    ...state.forum_threads_visible_by_id,
                    [action.id]: !is_visible,
                }
            };

        default:
            return state;
    };
};
