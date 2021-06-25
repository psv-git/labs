from rest_framework import status
from rest_framework.response import Response
from rest_framework_simplejwt.views import TokenObtainPairView

from .serializers import *
from ..utils.views import MultiSerializerViewSet
from ..utils.permissions import *



# auth ========================================================================

class TokenObtainView(TokenObtainPairView):

    serializer_class = TokenObtainSerializer



# user ========================================================================

class UserViewSet(MultiSerializerViewSet):

    queryset = User.objects.all() # .select_related("userprofile")

    serializers = {
        "create": UserCreateSerializer,
        "list": UserViewSerializer,
        "retrieve": UserViewSerializer,
        "update": UserUpdateSerializer,
        "partial_update": UserUpdateSerializer,
    }

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        user_serializer = self.get_serializer(data=request.data)
        user_serializer.is_valid(raise_exception=True)
        self.perform_create(user_serializer)
        return Response(user_serializer.data, status=status.HTTP_201_CREATED)


    def list(self, request, *args, **kwargs):
        queryset = self.filter_queryset(self.get_queryset())
        users_serializer = self.get_serializer(queryset, many=True)
        return Response(users_serializer.data)


    def retrieve(self, request, *args, **kwargs):
        user_instance = self.get_object()
        user_serializer = self.get_serializer(user_instance)
        return Response(user_serializer.data)


    def update(self, request, *args, **kwargs):
        partial = kwargs.pop("partial", False)
        user_instance = self.get_object()
        user_serializer = self.get_serializer(user_instance, data=request.data, partial=partial)
        user_serializer.is_valid(raise_exception=True)
        self.perform_update(user_instance, user_serializer)
        return Response(user_serializer.data)


    def destroy(self, request, *args, **kwargs):
        user_instance = self.get_object()
        self.perform_destroy(user_instance)
        return Response(status=status.HTTP_204_NO_CONTENT)
