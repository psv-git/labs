export function fetch_data(url, options, timeout = 5000) {
    return Promise.race([
        fetch(url, options),
        new Promise((_, reject) =>
            setTimeout(() => reject(new Error('timeout')), timeout)
        )
    ]);
};



export function make_query_string(query_params) {
    var query_string = "";
    if (query_params) {
        var params_count = Object.keys(query_params).length;
        query_string += "?";
        var i = 0;
        for (var key in query_params) {
            i++;
            query_string += key + "=" + query_params[key];
            if (i < params_count) query_string += "&&";
        };
        return query_string;
    };
    return query_string;
};
