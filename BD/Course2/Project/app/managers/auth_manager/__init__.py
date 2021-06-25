class AuthManager:

    __db_handler = None
    user = None


    # private methods =========================================================

    def __init__(self, app=None):
        pass


    # def __try_to_create_default_roles(self):
        # self.id = self.__db_handler.insert_data("user", {"email": self.email, "password": self.password, "registred_date": self.registred_date})


    def __get_user_roles(self):
        pass
        # user_id = self.user.id
        # query = "SELECT * FROM user WHERE email = '{0}'".format(email)
        # user_data = self.db_handler.process_query(query)[0]
