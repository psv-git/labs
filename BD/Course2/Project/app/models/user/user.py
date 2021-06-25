import time
from werkzeug import generate_password_hash, check_password_hash

from app.models.user.user_profile import UserProfile



class User:

    # properties ==============================================================

    @property
    def is_authenticated(self):
        """
        Is user authenticated.
        """
        return self._is_authenticated

    @property
    def is_active(self):
        """
        Is user active.
        """
        return self._is_active

    @property
    def is_anonymous(self):
        """
        Is user anonymous.
        """
        return self._is_anonymous


    # static methods ==========================================================

    @staticmethod
    def create_user(db_manager, name, email, password):
        """
        Create new user.
        """
        user = User(db_manager)
        user._make_new(name, email, password)
        return user


    @staticmethod
    def delete_user(id):
        """
        Delete existed user.
        """
        pass


    @staticmethod
    def get_user(db_manager, email):
        """
        Get user by his email.
        """
        user = None
        query = f"SELECT * FROM user WHERE email='{email}';"
        user_data = db_manager.process_query(query)[0]

        if user_data:
            user_id = user_data.get("id")

            user = User(db_manager)
            user.id = user_id
            user.email = email
            user.password = user_data.get("password")
            user.registred_at = user_data.get("registred_at")
            user.profile = UserProfile.get_profile(db_manager, user_id)

            user._is_authenticated = True
            user._is_active = True
            user._is_anonymous = False

        return user


    # public methods ==========================================================

    def get_id(self):
        """
        flask_login required it
        """
        return self.email


    def update_password(self, new_password):
        """
        Update user password.
        """
        if self.id:
            self.password = generate_password_hash(new_password)

            self.__db_manager.update_row("user", {
                "id": self.id,
                "email": self.email,
                "password": self.password,
                "registred_at": self.registred_at
            })

            return True
        return False


    def check_password(self, password):
        """
        Check user password.
        """
        return check_password_hash(self.password, password)


    # private methods =========================================================

    def __init__(self, db_manager=None):
        self.__db_manager = db_manager
        self.id = None
        self.email = None
        self.password = None
        self.registred_at = None
        self.profile = UserProfile(None)

        self._is_authenticated = False
        self._is_active = False
        self._is_anonymous = True

        self.roles_list = []


    def __eq__(self, other):
        return self.get_id() == other.get_id()


    def __ne__(self, other):
        return not self.__eq__(other)


    def _make_new(self, name, email, password):
        self.email = email
        self.password = generate_password_hash(password)
        self.registred_at = time.strftime("%Y-%m-%d %H:%M:%S")

        self.id = self.__db_manager.insert_row("user", {
            "email": self.email,
            "password": self.password,
            "registred_at": self.registred_at
        })

        if self.id:
            self.profile = UserProfile(self.__db_manager)
            if self.profile.create(self.id, name):
                return True
            else:
                User.delete_user(self.id)
        return False
