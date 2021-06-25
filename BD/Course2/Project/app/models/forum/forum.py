import time



class Forum:

    __db_manager = None


    # private methods =========================================================

    def __init__(self, db_manager=None):
        self.__db_manager = db_manager
        self.id = None
        self.parent_id = None
        self.creator_id = None
        self.name = None
        self.created_at = None

        self.sub_forums = []


    def __make_new(self, parent_id, creator_id, name):
        self.parent_id = parent_id
        self.creator_id = creator_id
        self.name = name
        self.created_at = time.strftime("%Y-%m-%d %H:%M:%S")

        forum_data = {"creator_id": self.creator_id, "name": self.name, "created_at": self.created_at}
        if self.parent_id:
            forum_data["parent_id"] = self.parent_id

        self.id = self.__db_manager.insert_row("forum", forum_data)

        if self.id:
            return True
        return False

    # static methods ==========================================================

    @staticmethod
    def get_forums(db_manager):
        forums = []
        query = "SELECT * FROM forum WHERE parent_id IS NULL"
        forums_data = db_manager.process_query(query)

        import logging
        logger = logging.getLogger("app")
        logger.critical(len(forums_data))

        if forums_data:
            for forum_data in forums_data:
                forum_id = forum_data.get("id")
                forum = Forum(db_manager)
                forum.id = forum_id
                forum.creator_id = forum_data.get("creator_id")
                forum.name = forum_data.get("name")
                forum.created_at = forum_data.get("created_at")

                query = "SELECT * FROM forum WHERE parent_id = '{0}'".format(forum_id)
                sub_forums_data = db_manager.process_query(query)
                if sub_forums_data:
                    forum.sub_forums = sub_forums_data

                forums.append(forum)

        return forums


    @staticmethod
    def create(db_manager, parent_id, creator_id, name):
        forum = Forum(db_manager)
        forum.__make_new(parent_id, creator_id, name)
        return forum


    @staticmethod
    def delete(id):
        pass
