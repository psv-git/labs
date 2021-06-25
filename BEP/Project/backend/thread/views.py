from rest_framework import status
from rest_framework.response import Response
from django.contrib.contenttypes.models import ContentType

from backend.thread.serializers import *
from backend.utils.permissions import *
from backend.post.models import Post
from backend.post.serializers import PostCreateSerializer
from backend.utils.views import MultiSerializerViewSet
from backend.utils.paginations import ThreadsPaginator


# FOR TEST ===============================
# import logging
# logger = logging.getLogger("console_logger")
# ========================================



class ThreadViewSet(MultiSerializerViewSet):

    queryset = Thread.objects.all()
    pagination_class = ThreadsPaginator

    serializers = {
        "create": ThreadCreateProtectedSerializer,
        "list": ThreadViewSerializer,
        "retrieve": ThreadViewSerializer,
        "update": ThreadUpdateSerializer,
        "partial_update": ThreadUpdateSerializer,
        "delete": ThreadUpdateProtectedSerializer,
        "hide": ThreadUpdateProtectedSerializer,
        "pin": ThreadUpdateProtectedSerializer,
    }

    # -------------------------------------------------------------------------

    def __perform_dhp(self, thread_instance, update_data):
        thread_serializer = self.get_serializer(thread_instance, data=update_data, partial=True)
        thread_serializer.is_valid(raise_exception=True)
        self.perform_update(thread_instance, thread_serializer)

        return Response(status=status.HTTP_200_OK)

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        thread_data = request.data.get("thread_data", None)
        thread_data["creator"] = request.user.id
        thread_data["last_modifier"] = request.user.id

        # create new thread
        thread_serializer = self.get_serializer(data=thread_data)
        thread_serializer.is_valid(raise_exception=True)
        self.perform_create(thread_serializer)
        thread_data = thread_serializer.data

        # create new post
        post_data = request.data.get("post_data", {"content": ""})
        post_data["creator"] = request.user.id
        post_data["last_modifier"] = request.user.id
        post_data["thread"] = thread_data["id"]
        post_data["is_pinned"] = True

        post_serializer = PostCreateSerializer(data=post_data)
        post_serializer.is_valid(raise_exception=True)
        self.perform_create(post_serializer)
        post_data = post_serializer.data

        # update thread data
        # use ThreadCreateSerializer for update in this case
        update_data = {
            "first_post": post_data["id"],
            "last_post": post_data["id"],
        }
        thread_instance = Thread.objects.get(id=thread_data["id"])
        thread_serializer = self.get_serializer(thread_instance, data=update_data, partial=True)
        thread_serializer.is_valid(raise_exception=True)
        self.perform_update(thread_instance, thread_serializer)

        return Response(thread_serializer.data, status=status.HTTP_201_CREATED)


    def list(self, request, *args, **kwargs):
        parent_id = request.query_params.get("parent_id", None)
        parent_model_id = request.query_params.get("parent_model_id", None)

        # this is a required query params
        if parent_id and parent_model_id:
            queryset = self.filter_queryset(self.get_queryset()).filter(parent_id=parent_id, parent_model=parent_model_id)

            page_number = request.query_params.get("page", None)
            count_from_begin = request.query_params.get("count_from_begin", None)
            if page_number:
                page = self.paginate_queryset(queryset)
                if page is not None:
                    page_serializer = self.get_serializer(page, many=True)
                    return self.get_paginated_response(page_serializer.data)
            elif count_from_begin:
                queryset = queryset[:int(count_from_begin)]

            list_serializer = self.get_serializer(queryset, many=True)

            return Response(list_serializer.data)

        return Response(status=status.HTTP_400_BAD_REQUEST)


    def retrieve(self, request, *args, **kwargs):
        thread_instance = self.get_object()
        thread_serializer = self.get_serializer(thread_instance)

        return Response(thread_serializer.data)


    def update(self, request, *args, **kwargs):
        update_data = request.data
        update_data["last_modifier"] = request.user.id
        update_data["is_modified"] = True

        partial = kwargs.pop("partial", False)

        thread_instance = self.get_object()
        thread_serializer = self.get_serializer(thread_instance, data=update_data, partial=partial)
        thread_serializer.is_valid(raise_exception=True)
        self.perform_update(thread_instance, thread_serializer)

        return Response(thread_serializer.data)


    def destroy(self, request, *args, **kwargs):
        thread_instance = self.get_object()
        self.perform_destroy(thread_instance)

        return Response(status=status.HTTP_200_OK)

    # -------------------------------------------------------------------------

    def delete(self, request, *args, **kwargs):
        thread_instance = self.get_object()

        update_data = { 
            "is_deleted": not thread_instance.is_deleted,
        }

        return self.__perform_dhp(thread_instance, update_data)


    def hide(self, request, *args, **kwargs):
        thread_instance = self.get_object()

        update_data = { 
            "is_hidden": not thread_instance.is_hidden,
        }

        return self.__perform_dhp(thread_instance, update_data)


    def pin(self, request, *args, **kwargs):
        thread_instance = self.get_object()

        update_data = { 
            "is_pinned": not thread_instance.is_pinned,
        }

        return self.__perform_dhp(thread_instance, update_data)
