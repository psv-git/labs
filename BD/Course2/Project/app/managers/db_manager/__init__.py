from logging import getLogger
import pymysql

from configs import db_config as db_conf



class _DBMState(object):

    def __init__(self, dbm, app):
        self.dbm = dbm
        self.app = app


class MySQLManager:

    def __init__(self, app=None):
        self.__logger = getLogger("app_logger")
        self.__app = None
        self.__is_connected = False
        self.__db_name = db_conf.DB_NAME
        self.__user_name = db_conf.DB_USER
        self.__user_password = db_conf.DB_PASSWORD
        self.__open_conn()

        if app is not None:
            self.app = app
            self.init_app(app)


    # private methods =========================================================

    def init_app(self, app):
        if not hasattr(app, "extensions"):
            app.extensions = {}
        app.extensions["dbm"] = _DBMState(self, app)


    def __open_conn(self):
        self.__conn = pymysql.connect(host=db_conf.DB_HOST, user=self.__user_name, password=self.__user_password, db=self.__db_name, charset="utf8mb4", cursorclass=pymysql.cursors.DictCursor)
        self.__is_connected = True
        self.__conn.database = self.__db_name


    def __close_conn(self):
        if self.__is_connected:
            self.__conn.close()
            self.__is_connected = False


    # public methods ==========================================================

    def create_table(self, table, columns):
        """
        Create new table.

        Args:
            table: str
            columns: dict like {"id": "int(11) PRIMARY KEY", "user_id": "int(1) UNSIGNED NOT NULL", ...}
        """
        try:
            columns_list = ','.join(["{0} {1}".format(key, value) for key, value in columns.items()])
            query = f"CREATE TABLE IF NOT EXISTS {table} ({columns_list}) ENGINE=InnoDB DEFAULT CHARSET=utf8;"
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
            self.__conn.commit()
        except Exception:
            self.__conn.rollback()
            self.__logger.critical(f"Error. Table '{table}' was not created succesfully.")


    def delete_table(self, table):
        """
        Delete table from database.

        Args:
            table: string
        """
        try:
            query = f"DROP TABLE IF EXISTS {table}"
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
            self.__conn.commit()
        except Exception:
            self.__conn.rollback()
            self.__logger.critical(f"Error. Table '{table}' was not deleted succesfully.")


    def insert_row(self, table, row_data):
        """
        Insert row to table.

        Args:
            table: string
            row_data: dict like {"id": id, "name": name, "desc_text": "some text"}
        """
        result = None
        try:
            columns = ",".join(row_data.keys())
            values = tuple(row_data.values())
            query = f"INSERT INTO {table} ({columns}) VALUES {values};"
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
                result = self.__conn.insert_id()
            self.__conn.commit()
        except Exception:
            self.__conn.rollback()
            result = None
            self.__logger.critical(f"Error. Row for query '{query}' was not inserted succesfully.")

        return result


    def update_row(self, table, row_data):
        """
        Update table row.

        Args:
            table: string
            row_data: dict like {"id": id, "name": name, "desc_text": "some text"}
        """
        try:
            columns = ",".join(row_data.keys())
            values = tuple(row_data.values())
            query = f"REPLACE INTO {table} ({columns}) VALUES {values};"
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
            self.__conn.commit()
        except:
            self.__conn.rollback()
            self.__logger.critical(f"Error. Row for query '{query}' was not updated succesfully.")


    def delete_row(self, table, cond_data):
        """
        Delete table row.

        Args:
            table: string
            cond_data: dict like {"id": id, "name": name, ...}
        """
        try:
            conditions = ",".join([f"{key}={str(cond_data.get(key))}" for key in cond_data.keys()])
            query = f"DELETE FROM {table} WHERE {conditions};"
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
            self.__conn.commit()
        except:
            self.__conn.rollback()
            self.__logger.critical(f"Error. Row for query '{query}' was not deleted succesfully.")


    def process_query(self, query):
        """
        For select.

        Args:
            query: string like "SELECT name FROM test_table_2 WHERE id = 2"
        """
        result = None
        try:
            with self.__conn.cursor() as cursor:
                cursor.execute(query)
                result = cursor.fetchall()
            self.__conn.commit()
        except Exception:
            self.__conn.rollback()
            result = None
            self.__logger.critical(f"Error. Query '{query}' was not processed succesfully.")

        return result
