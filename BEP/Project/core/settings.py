import os
import datetime



# Build paths inside the project like this: os.path.join(BASE_DIR, ...)
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = "+lira#ibxe$^m8kz*dxe2tv1*bh(-!4-u!bi@22)b8k*pz=_gh"
# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = True
ALLOWED_HOSTS = []


# Application =================================================================

INSTALLED_APPS = [
    "django.contrib.auth", # Фреймворк аутентификации и моделей по умолчанию.
    "django.contrib.contenttypes", # Django контент-типовая система (даёт разрешения, связанные с моделями).
    "django.contrib.sessions",
    "django.contrib.staticfiles",
    "webpack_loader",
    "rest_framework",
    "corsheaders",
    "backend",
    "api_v0",
]


MIDDLEWARE = [
    "django.middleware.security.SecurityMiddleware",
    "django.contrib.sessions.middleware.SessionMiddleware", # Управление сессиями между запросами
    "corsheaders.middleware.CorsMiddleware", # Note that this needs to be placed above CommonMiddleware
    "django.middleware.csrf.CsrfViewMiddleware",
    "django.contrib.auth.middleware.AuthenticationMiddleware", # Связывает пользователей, использующих сессии, запросами.
    "django.middleware.clickjacking.XFrameOptionsMiddleware",
]


ROOT_URLCONF = "core.urls"


TEMPLATES = [
    {
        "BACKEND": "django.template.backends.django.DjangoTemplates",
        "DIRS": ["static/templates"],
    },
]


WSGI_APPLICATION = "core.wsgi.application"

# Database ====================================================================

DATABASES = {
    "default": {
        "ENGINE": "django.db.backends.mysql",
        "NAME": "test_backend",
        "USER": "test",
        "PASSWORD": "",
        "HOST": "127.0.0.1",
        "PORT": "3306",
        "OPTIONS": {
            "init_command": "SET sql_mode='STRICT_TRANS_TABLES'",
        }
    }
}

# Password validation =========================================================

AUTH_USER_MODEL = "backend.User"


AUTH_PASSWORD_VALIDATORS = [
    { "NAME": "django.contrib.auth.password_validation.UserAttributeSimilarityValidator", }, 
    { "NAME": "django.contrib.auth.password_validation.MinimumLengthValidator", }, 
    { "NAME": "django.contrib.auth.password_validation.CommonPasswordValidator", }, 
    { "NAME": "django.contrib.auth.password_validation.NumericPasswordValidator", }, 
]

# Internationalization ========================================================

LANGUAGE_CODE = "en-us"
TIME_ZONE = "UTC"
USE_I18N = True
USE_L10N = True
USE_TZ = True

# Static files (CSS, JavaScript, Images) ======================================

STATIC_URL = "/static/"
STATICFILES_DIRS = (os.path.join(BASE_DIR, "static"),)
MEDIA_URL = "/media/"
MEDIA_ROOT = os.path.join(BASE_DIR, "media")

# Webpack =====================================================================

WEBPACK_LOADER = {
    "DEFAULT": {
        "BUNDLE_DIR_NAME": "static/local/",
        "STATS_FILE": os.path.join(BASE_DIR, "webpack-stats-local.json"),
    }
}

# Rest ========================================================================

REST_FRAMEWORK = {
    "DEFAULT_PERMISSION_CLASSES": [
        "rest_framework.permissions.IsAuthenticated"
    ],
    "DEFAULT_AUTHENTICATION_CLASSES": (
        "rest_framework.authentication.SessionAuthentication",
        "rest_framework.authentication.BasicAuthentication",
        "rest_framework_simplejwt.authentication.JWTAuthentication",
    ),
}


CORS_ORIGIN_WHITELIST = (
    "localhost:3000",
)


SIMPLE_JWT = {
    "ACCESS_TOKEN_LIFETIME": datetime.timedelta(days=1),
    "REFRESH_TOKEN_LIFETIME": datetime.timedelta(days=1),
    "ROTATE_REFRESH_TOKENS": False,
    "BLACKLIST_AFTER_ROTATION": True,

    "ALGORITHM": "HS256",
    "SIGNING_KEY": SECRET_KEY,
    "VERIFYING_KEY": None,

    "AUTH_HEADER_TYPES": ("Bearer",),
    "USER_ID_FIELD": "id",
    "USER_ID_CLAIM": "user_id",

    "AUTH_TOKEN_CLASSES": ("rest_framework_simplejwt.tokens.AccessToken",),
    "TOKEN_TYPE_CLAIM": "token_type",

    "JTI_CLAIM": "jti",

    "SLIDING_TOKEN_REFRESH_EXP_CLAIM": "refresh_exp",
    "SLIDING_TOKEN_LIFETIME": datetime.timedelta(minutes=5),
    "SLIDING_TOKEN_REFRESH_LIFETIME": datetime.timedelta(days=1),
}

# Logging =====================================================================

LOGGING = {
    "version": 1,
    "disable_existing_loggers": False,
    "formatters": {
        "verbose": {
            "format": "%(levelname)s : %(asctime)s %(module)s %(process)d %(thread)d %(message)s"
        },
        "simple": {
            "format": "%(levelname)s : %(message)s"
        },
    },
    "handlers": {
        "console": {
            "level": "INFO",
            "class": "logging.StreamHandler",
            "formatter": "simple"
        },
        "file": {
            "level": "INFO",
            "class": "logging.FileHandler",
            "filename": os.getcwd() + "/logs/debug.log",
        },
    },
    "loggers": {
        "console_logger": {
            "handlers": ["console"],
            "level": "INFO",
        },
    },
}
