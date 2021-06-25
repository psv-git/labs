from rest_framework import status
from rest_framework.response import Response
from django.contrib.contenttypes.models import ContentType

from backend.forum.serializers import *
from backend.utils.permissions import *
from backend.thread.models import Thread
from backend.post.models import Post
from backend.thread.serializers import ThreadUpdateSerializer
from backend.post.serializers import PostUpdateSerializer
from backend.utils.views import MultiSerializerViewSet



# FOR TEST ===============================
import logging
logger = logging.getLogger("console_logger")
# ========================================



class ForumViewSet(MultiSerializerViewSet):

    queryset = Forum.objects.all()

    serializers = {
        "create": ForumCreateProtectedSerializer,
        "list": ForumViewSerializer,
        "retrieve": ForumViewSerializer,
        "update": ForumUpdateProtectedSerializer,
        "partial_update": ForumUpdateProtectedSerializer,
        "delete": ForumUpdateProtectedSerializer,
        "hide": ForumUpdateProtectedSerializer,
    }

    # -------------------------------------------------------------------------

    def __perform_dh(self, forum_instance, update_data):
        forum_serializer = self.get_serializer(forum_instance, data=update_data, partial=True)
        forum_serializer.is_valid(raise_exception=True)
        self.perform_update(forum_instance, forum_serializer)

        return Response(status=status.HTTP_200_OK)

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        model_id = ContentType.objects.get_for_model(Forum).id
        forum_data = request.data
        forum_data["model"] = model_id
        forum_data["creator"] = request.user.id
        forum_data["last_modifier"] = request.user.id

        logger.info(forum_data)

        forum_serializer = self.get_serializer(data=forum_data)
        forum_serializer.is_valid(raise_exception=True)
        self.perform_create(forum_serializer)

        logger.info("accept")

        return Response(forum_serializer.data, status=status.HTTP_201_CREATED)


    def list(self, request, *args, **kwargs):
        parent_id = request.query_params.get("parent_id", None)
        parent_model_id = request.query_params.get("parent_model_id", None)

        # this is a required query params
        if parent_id and parent_model_id:
            queryset = self.filter_queryset(self.get_queryset()).filter(parent_model=parent_model_id, parent_id=parent_id)

            count_from_begin = request.query_params.get("count_from_begin", None)
            if count_from_begin:
                queryset = queryset[:int(count_from_begin)]

            list_serializer = self.get_serializer(queryset, many=True)
            return Response(list_serializer.data)

        return Response(status=status.HTTP_400_BAD_REQUEST)


    def retrieve(self, request, *args, **kwargs):
        forum_instance = self.get_object()
        forum_serializer = self.get_serializer(forum_instance)

        return Response(forum_serializer.data)


    def update(self, request, *args, **kwargs):
        update_data = request.data
        update_data["last_modifier"] = request.user.id
        update_data["is_modified"] = True

        partial = kwargs.pop("partial", False)

        forum_instance = self.get_object()
        forum_serializer = self.get_serializer(forum_instance, data=update_data, partial=partial)
        forum_serializer.is_valid(raise_exception=True)
        self.perform_update(forum_instance, forum_serializer)

        return Response(forum_serializer.data)


    def destroy(self, request, *args, **kwargs):
        forum_instance = self.get_object()
        self.perform_destroy(forum_instance)

        return Response(status=status.HTTP_200_OK)

    # -------------------------------------------------------------------------

    def delete(self, request, *args, **kwargs):
        forum_instance = self.get_object()

        update_data = { 
            "is_deleted": not forum_instance.is_deleted,
        }

        return self.__perform_dh(forum_instance, update_data)


    def hide(self, request, *args, **kwargs):
        forum_instance = self.get_object()

        if not forum_instance.is_deleted:
            update_data = {
                "is_hidden": not forum_instance.is_hidden,
            }

            return self.__perform_dh(forum_instance, update_data)

        return Response(status=status.HTTP_403_FORBIDDEN)
