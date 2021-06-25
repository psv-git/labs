import os, sys

if len(sys.argv) == 2:
    platform = sys.argv[1]

    os.system("npm install")

    if not os.path.exists("./static/local"):
        os.mkdir("./static/local")

    if platform == "linux" or platform == "l":
        os.system("rm -rf ./static/local/*")
        os.system("./node_modules/.bin/webpack --config webpack.config.local.js")
    if platform == "win" or platform == "w":
        os.system("del /Q .\\static\\local\\*")
        os.system(".\\node_modules\\.bin\\webpack --config webpack.config.local.js")
