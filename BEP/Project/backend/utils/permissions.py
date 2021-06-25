from rest_framework.permissions import IsAdminUser, BasePermission, SAFE_METHODS



class ReadOnly(BasePermission):

    def has_permission(self, request, view):
        return request.method in SAFE_METHODS
