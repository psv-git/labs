import {
    SET_BREADCRUMB_DATA,

    TOGGLE_THREAD_CREATE_FORM_VISIBLE,
    TOGGLE_POST_CREATE_FORM_VISIBLE,

    ADD_FORUM,
    TOGGLE_THREADS_LIST_VISIBLE,
} from "../actions_types";



// ============================================================================

export const setBreadcrumbData = (breadcrumb_data) => ({
    type: SET_BREADCRUMB_DATA,
    breadcrumb_data,
});



export const toggleThreadCreateFormVisible = () => ({
    type: TOGGLE_THREAD_CREATE_FORM_VISIBLE,
});



export const togglePostCreateFormVisible = () => ({
    type: TOGGLE_POST_CREATE_FORM_VISIBLE,
});



export const addForum = (id, is_visible) => ({
    type: ADD_FORUM,
    id,
    is_visible,
});



export const toggleThreadsListVisible = (id) => ({
    type: TOGGLE_THREADS_LIST_VISIBLE,
    id,
});
