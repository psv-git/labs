# database settings ===========================================================

DB_HOST = "localhost"
DB_NAME = "test_bd"
DB_USER = "test"
DB_PASSWORD = ""


# tables ======================================================================

TABLES_DICT = {
    "user": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "email": "varchar(50) UNIQUE NOT NULL",
        "password": "varchar(255) NOT NULL",
        "registred_at": "datetime(6) NOT NULL",
    },
    "user_profile": {
        "user_id": "int(5) UNSIGNED NOT NULL PRIMARY KEY",
        "name": "varchar(20) NOT NULL",
        "avatar": "varchar(255) NOT NULL",
        "FOREIGN KEY (user_id)": "REFERENCES user(id)"
    },
    "forum": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "parent_id": "int(5) UNSIGNED DEFAULT NULL",
        "creator_id": "int(5) UNSIGNED NOT NULL",
        "name": "varchar(20) NOT NULL",
        "created_at": "datetime(6) NOT NULL",
        "FOREIGN KEY (parent_id)": "REFERENCES forum(id)",
        "FOREIGN KEY (creator_id)": "REFERENCES user(id)"
    },
    "thread": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "forum_id": "int(5) UNSIGNED NOT NULL",
        "creator_id": "int(5) UNSIGNED NOT NULL",
        "title": "varchar(50) NOT NULL",
        "created_at": "datetime(6) NOT NULL",
        "FOREIGN KEY (forum_id)": "REFERENCES forum(id)",
        "FOREIGN KEY (creator_id)": "REFERENCES user(id)"
    },
    "post": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "thread_id": "int(5) UNSIGNED NOT NULL",
        "creator_id": "int(5) UNSIGNED NOT NULL",
        "text": "text NOT NULL",
        "FOREIGN KEY (thread_id)": "REFERENCES thread(id)",
        "FOREIGN KEY (creator_id)": "REFERENCES user(id)"
    },
    "auth_role": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "name": "varchar(20) UNIQUE NOT NULL",
        "description": "varchar(255)",
    },
    "auth_permission": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "action": "varchar(20) NOT NULL",
        "forum_id": "int(5) UNSIGNED DEFAULT NULL",
        "thread_id": "int(5) UNSIGNED DEFAULT NULL",
        "FOREIGN KEY (forum_id)": "REFERENCES forum(id)",
        "FOREIGN KEY (thread_id)": "REFERENCES thread(id)",
        "UNIQUE KEY (combined_key)": "(action, forum_id, thread_id)",
    },
    "auth_role_permission": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "role_id": "int(5) UNSIGNED NOT NULL",
        "permission_id": "int(5) UNSIGNED NOT NULL",
        "FOREIGN KEY (role_id)": "REFERENCES auth_role(id)",
        "FOREIGN KEY (permission_id)": "REFERENCES auth_permission(id)",
    },
    "auth_user_role": {
        "id": "int(5) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY",
        "user_id": "int(5) UNSIGNED NOT NULL",
        "role_id": "int(5) UNSIGNED NOT NULL",
        "FOREIGN KEY (user_id)": "REFERENCES user(id)",
        "FOREIGN KEY (role_id)": "REFERENCES auth_role(id)",
    }
}
