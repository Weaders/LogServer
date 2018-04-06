const path = require('path');

module.exports = {
    mode: 'development',
    entry: './assets/main.js',
    output: {
        path: path.resolve(__dirname, 'assets', 'js-minify'),
        filename: 'bundle-compile.js'
    },
    module: {
        rules: [
            {
                test: /\.jsx?$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        sourceMap: true,
                        presets: ['@babel/preset-env', '@babel/preset-react']
                    }
                }
            }
        ]
    },
    resolve: {
        extensions: ['.js', '.jsx']
    },
    watch: true,
    devtool: 'source-map'
};