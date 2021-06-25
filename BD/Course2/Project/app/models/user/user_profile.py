from configs import app_config as app_conf



class UserProfile:

    __db_handler = None


    # private methods =========================================================

    def __init__(self, db_manager):
        self.__db_manager = db_manager
        self.user_id = None
        self.name = "Guest"
        self.avatar = app_conf.DEFAULT_AVATAR_PATH


    # static methods ==========================================================

    @staticmethod
    def get_profile(db_manager, user_id):
        user_profile = None

        query = "SELECT * FROM user_profile WHERE user_id = {0}".format(user_id)
        user_profile_data = db_manager.process_query(query)[0]

        if user_profile_data:
            user_profile = UserProfile(db_manager)
            user_profile.user_id = user_id
            user_profile.name = user_profile_data.get("name")
            user_profile.avatar = user_profile_data.get("avatar")

        return user_profile


    # public methods ==========================================================

    def create(self, user_id, name):
        self.user_id = user_id
        self.name = name

        profile_id = self.__db_manager.insert_row("user_profile", {
            "user_id": self.user_id,
            "name": self.name,
            "avatar": self.avatar
        })

        if profile_id:
            return True
        return False
