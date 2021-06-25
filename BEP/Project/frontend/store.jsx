import thunk from "redux-thunk";
import {
    createStore,
    compose,
    applyMiddleware,
    combineReducers,
} from "redux";
import {
    persistStore,
    persistReducer,
} from "redux-persist";
import storage from "redux-persist/lib/storage"; // defaults to localStorage for web and AsyncStorage for react-native

import * as reducers from "./redux/reducers";



const persistConfig = {
    key: 'auth',
    storage,
    whitelist: ['auth'],
};



const persistedReducer = persistReducer(persistConfig, combineReducers(reducers));
const composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose;



export const store = createStore(persistedReducer, composeEnhancers(applyMiddleware(thunk)));
export const persistor = persistStore(store);
