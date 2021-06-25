import os


# server parametres ===========================================================

HOST = "127.0.0.1"
PORT = 5000

# application parametres ======================================================

SECRET_KEY = os.urandom(32)

# paths =======================================================================

ROOT_PATH = os.getcwd()
IMAGES_PATH = "static/img/"
AVATARS_PATH = IMAGES_PATH + "avatars/"
DEFAULT_AVATAR_PATH = AVATARS_PATH + "default.png"
LOGGER_CONFIG_PATH = ROOT_PATH + "/configs/logger_config.conf"
