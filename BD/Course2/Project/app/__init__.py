from logging.config import fileConfig
from flask import Flask, g
from flask_login import LoginManager, current_user
from werkzeug.debug import DebuggedApplication

from configs import app_config as app_conf
from configs import db_config as db_conf
from app.managers.db_manager import MySQLManager
from app.managers.auth_manager import AuthManager
from app.models.user.user import User
from app.models.auth.role import Role



app = Flask(__name__)
login_manager = LoginManager()
db_manager = MySQLManager()


# =============================================================================

def setup_app():
    fileConfig(app_conf.LOGGER_CONFIG_PATH, disable_existing_loggers=False)

    from app.auth import bp as auth_bp
    from app.main import bp as main_bp
    app.register_blueprint(auth_bp)
    app.register_blueprint(main_bp)
    app.config["SECRET_KEY"] = app_conf.SECRET_KEY
    app.config['PROPAGATE_EXCEPTIONS'] = True # DEBUG
    app.wsgi_app = DebuggedApplication(app.wsgi_app, True) # DEBUG

    login_manager.init_app(app)
    login_manager.anonymous_user = User

    db_manager.init_app(app)
    __make_default_tables()
    __make_default()


def run_app():
    app.run(host=app_conf.HOST, port=app_conf.PORT)


# =============================================================================

@app.before_request
def before_request():
    g.user = current_user


def __make_default_tables():
    db_manager.create_table("user", db_conf.TABLES_DICT.get("user"))
    db_manager.create_table("user_profile", db_conf.TABLES_DICT.get("user_profile"))
    db_manager.create_table("forum", db_conf.TABLES_DICT.get("forum"))
    db_manager.create_table("thread", db_conf.TABLES_DICT.get("thread"))
    db_manager.create_table("post", db_conf.TABLES_DICT.get("post"))
    db_manager.create_table("auth_role", db_conf.TABLES_DICT.get("auth_role"))
    db_manager.create_table("auth_permission", db_conf.TABLES_DICT.get("auth_permission"))
    db_manager.create_table("auth_role_permission", db_conf.TABLES_DICT.get("auth_role_permission"))
    db_manager.create_table("auth_user_role", db_conf.TABLES_DICT.get("auth_user_role"))


def __make_default():
    admin_role = Role.create_role(db_manager, "admin", "Forum administrator")
    admin_role.add_permission("create")
    admin_role.add_permission("read")
    admin_role.add_permission("update")
    admin_role.add_permission("delete")

    super_moderator = Role.create_role(db_manager, "moderator", "Forum super moderator")
    super_moderator.add_permission("create")
    super_moderator.add_permission("read")
    super_moderator.add_permission("update")
    super_moderator.add_permission("delete")

    Role.create_role(db_manager, "user", "Forum user")
    User.create_user(db_manager, "Admin", "admin@admin.com", "123456")
