from rest_framework import status
from rest_framework.response import Response

from backend.post.serializers import *
from backend.utils.permissions import *
from backend.thread.models import Thread
from backend.thread.serializers import ThreadUpdateSerializer
from backend.utils.views import MultiSerializerViewSet
from backend.utils.paginations import PostsPaginator



# FOR TEST ===============================
# import logging
# logger = logging.getLogger("console_logger")
# ========================================



class PostViewSet(MultiSerializerViewSet):

    queryset = Post.objects.all()
    pagination_class = PostsPaginator

    serializers = {
        "create": PostCreateSerializer,
        "list": PostViewSerializer,
        "retrieve": PostViewSerializer,
        "update": PostUpdateSerializer,
        "partial_update": PostUpdateSerializer,
        "delete": PostUpdateProtectedSerializer,
        "hide": PostUpdateProtectedSerializer,
        "pin": PostUpdateProtectedSerializer,
    }

    # -------------------------------------------------------------------------

    def get_last_thread_post(self, thread_id):
        return self.get_queryset().filter(thread_id=thread_id, is_hidden=False).last()


    def perform_dhp(self, thread_instance, post_instance, update_data, posts_count):
        # first thread post is a part of thread - dont change it
        if post_instance.id != thread_instance.first_post_id:
            # mark post as deleted
            post_serializer = self.get_serializer(post_instance, data=update_data, partial=True)
            post_serializer.is_valid(raise_exception=True)
            self.perform_update(post_instance, post_serializer)

            post_instance = self.get_last_thread_post(thread_instance.id)

            # update thread data
            update_data = {
                "last_post": post_instance.id,
                "posts_count": posts_count,
            }

            thread_serializer = ThreadUpdateSerializer(thread_instance, data=update_data, partial=True)
            thread_serializer.is_valid(raise_exception=True)
            self.perform_update(thread_instance, thread_serializer)

            return Response(status=status.HTTP_200_OK)
        return Response(status=status.HTTP_403_FORBIDDEN)

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        post_data = request.data
        post_data["creator"] = request.user.id
        post_data["last_modifier"] = request.user.id

        # create new post
        post_serializer = self.get_serializer(data=post_data)
        post_serializer.is_valid(raise_exception=True)
        self.perform_create(post_serializer)
        post_data = post_serializer.data

        # update tread
        thread_instance = Thread.objects.get(id=post_data["thread"])
        update_data = {
            "last_post": post_data["id"],
            "posts_count": thread_instance.posts_count + 1,
        }
        thread_serializer = ThreadUpdateSerializer(thread_instance, data=update_data, partial=True)
        thread_serializer.is_valid(raise_exception=True)
        self.perform_update(thread_instance, thread_serializer)

        return Response(post_serializer.data, status=status.HTTP_201_CREATED)


    def list(self, request, *args, **kwargs):
        queryset = self.filter_queryset(self.get_queryset())

        forum_id = kwargs.get("forum_id", None)
        thread_id = kwargs.get("thread_id", None)
        if forum_id:
            queryset = queryset.filter(forum_id=forum_id)
        elif thread_id:
            queryset = queryset.filter(thread_id=thread_id)

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


    def retrieve(self, request, *args, **kwargs):
        post_instance = self.get_object()
        post_serializer = self.get_serializer(post_instance)

        return Response(post_serializer.data)


    def update(self, request, *args, **kwargs):
        update_data = request.data
        update_data["last_modifier"] = request.user.id
        update_data["is_modified"] = True

        partial = kwargs.pop("partial", False)

        post_instance = self.get_object()
        post_serializer = self.get_serializer(post_instance, data=update_data, partial=partial)
        post_serializer.is_valid(raise_exception=True)
        self.perform_update(post_instance, post_serializer)

        return Response(post_serializer.data)


    def destroy(self, request, *args, **kwargs):
        post_instance = self.get_object()
        self.perform_destroy(post_instance)

        return Response(status=status.HTTP_204_NO_CONTENT)

    # -------------------------------------------------------------------------

    def delete(self, request, *args, **kwargs):
        post_instance = self.get_object()
        thread_instance = post_instance.thread

        # if post is deleted now - we will restore it, else - delete it
        update_data = { 
            "is_deleted": not post_instance.is_deleted, 
        }
        posts_count = thread_instance.posts_count
        if not post_instance.is_hidden:
            if post_instance.is_deleted:
                posts_count = thread_instance.posts_count + 1
            else:
                posts_count = thread_instance.posts_count - 1

        return self.perform_dhp(thread_instance, post_instance, update_data, posts_count)


    def hide(self, request, *args, **kwargs):
        post_instance = self.get_object()

        # delete have higher priority
        if not post_instance.is_deleted:
            # if post is hidden now - we will unhidden it, else - hide it
            thread_instance = post_instance.thread

            update_data = { 
                "is_hidden": not post_instance.is_hidden, 
            }
            if (post_instance.is_hidden):
                posts_count = thread_instance.posts_count + 1
            else:
                posts_count = thread_instance.posts_count - 1

            return self.perform_dhp(thread_instance, post_instance, update_data, posts_count)

        return Response(status=status.HTTP_403_FORBIDDEN)


    def pin(self, request, *args, **kwargs):
        post_instance = self.get_object()
        thread_instance = post_instance.thread

        # if post is pinned now - we will unpin it, else - pin it
        update_data = { 
            "is_pinned": not post_instance.is_pinned, 
        }

        return self.perform_dhp(thread_instance, post_instance, update_data, thread_instance.posts_count)
