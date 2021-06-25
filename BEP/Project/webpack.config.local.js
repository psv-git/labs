var path = require("path")
var webpack = require('webpack')
var BundleTracker = require('webpack-bundle-tracker')
var ip = 'localhost'


module.exports = {

    context: __dirname,
    mode: 'development',


    entry: {
        index: './frontend/index.jsx',
        vendors: ['react'],
    },


    output: {
        publicPath: "http://" + ip + ":3000" + "/static/",
        path: path.resolve("static/local/"),
        filename: "[name]-[hash].js",
    },


    plugins: [
        new webpack.HotModuleReplacementPlugin(),
        new BundleTracker({ filename: 'webpack-stats-local.json' }),
        new webpack.NoEmitOnErrorsPlugin(),
        new webpack.DefinePlugin({
            'process.env': {
                'NODE_ENV': JSON.stringify('development'),
            }
        }),
    ],


    module: {
        rules: [
            {
                test: /\.(js|jsx)$/,
                exclude: /node_modules/,
                loader: require.resolve('babel-loader'),
                options: {
                    // This is a feature of `babel-loader` for webpack (not Babel itself).
                    // It enables caching results in ./node_modules/.cache/babel-loader/
                    // directory for faster rebuilds.
                    cacheDirectory: true,
                    plugins: [
                        'react-hot-loader/babel',
                        // '@babel/plugin-proposal-class-properties',
                    ],
                },
            },
            {
                test: /\.css$/,
                loader: 'style-loader!css-loader'
            },
            {
                test: /\.(jpg|png|gif|jpeg|woff|woff2|eot|ttf|svg)$/,
                loader: 'url-loader?limit=100000'
            }
        ]
    },


    resolve: {
        modules: [
            'node_modules',
        ],
        extensions: ['.js', '.jsx', '.css'],
        alias: {
            'react-dom': '@hot-loader/react-dom'
        }
    },

    devServer: {
        // for react-router-dom + redux
        historyApiFallback: true
    }

}
