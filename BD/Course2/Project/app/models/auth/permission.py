class Permission:
    """
    Class represent a permission table row.
    """

    # static methods ==========================================================

    @staticmethod
    def create_permission(db_manager, permission_action, forum_id=0, thread_id=0):
        """
        Create new permission.

        for forum_id, thread_id - 0 mean all
        """
        permission_id = db_manager.insert_row("auth_permission", {
            "action": permission_action,
            "forum_id": forum_id,
            "thread_id": thread_id,
        })

        if permission_id:
            return Permission(db_manager, permission_id, permission_action, forum_id, thread_id)
        return None


    @staticmethod
    def delete_permission(db_manager, permission_id):
        """
        Delete existed permission.
        """
        pass


    @staticmethod
    def get_permission(db_manager, permission_id):
        """
        Get permission by id.
        """
        query = f"SELECT action, forum_id, thread_id FROM auth_permission WHERE id={permission_id};"
        result = db_manager.process_query(query)

        if result:
            permission_action = result.get("action")
            forum_id = result.get("forum_id")
            thread_id = result.get("thread_id")
            return Permission(db_manager, permission_id, permission_action, forum_id, thread_id)
        return None


    # public methods ==========================================================


    # private methods =========================================================

    def __init__(self, db_manager, permission_id, permission_action, forum_id, thread_id):
        self.__db_manager = db_manager
        self.permission_id = permission_id
        self.permission_action = permission_action
        self.forum_id = forum_id
        self.thread_id = thread_id


    def __eq__(self, other):
        return self.permission_id == other.permission_id


    def __ne__(self, other):
        return not self.__eq__(other)
