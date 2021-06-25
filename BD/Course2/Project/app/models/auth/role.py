from app.models.auth.permission import Permission



class Role:
    """
    Class represent a role table row.
    """

    # static methods ==========================================================

    @staticmethod
    def create_role(db_manager, role_name, role_description):
        """
        Create new role.
        """
        role_id = db_manager.insert_row("auth_role", {
            "name": role_name,
            "description": role_description
        })

        if role_id:
            return Role(db_manager, role_id, role_name, role_description)
        return None


    @staticmethod
    def delete_role(db_manager, role_id):
        """
        Delete existed role.
        """
        pass


    @staticmethod
    def get_role(db_manager, role_name):
        query = f"SELECT id, description FROM role WHERE name={role_name};"
        result = db_manager.process_query(query)

        if result:
            role_id = result.get("id")
            role_description = result.get("description")
            return Role(db_manager, role_id, role_name, role_description)
        return None


    # public methods ==========================================================

    def add_permission(self, permission_action, forum_id=0, thread_id=0):
        """
        Add permission to this role.
        """
        permission = Permission.create_permission(self.__db_manager, permission_action, forum_id, thread_id)
        self.role_permissions_list.append(permission)


    # private methods =========================================================

    def __init__(self, db_manager, role_id, role_name, role_description):
        self.__db_manager = db_manager
        self.role_id = role_id
        self.role_name = role_name
        self.role_description = role_description
        self.role_permissions_list = []
        self.__get_permissions()


    def __eq__(self, other):
        return self.role_id == other.role_id


    def __ne__(self, other):
        return not self.__eq__(other)


    def __get_permissions(self):
        query = f"SELECT permission_id FROM auth_role_permission WHERE role_id={self.role_id};"
        result = self.__db_manager.process_query(query)

        if result:
            for permission_id in result.values():
                permission = Permission.get_permission(self.__db_manager, permission_id)
                self.role_permissions_list.append(permission)
