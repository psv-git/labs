from rest_framework import serializers

from backend.post.models import Post
from backend.user.serializers import UserViewSerializer



class PostCreateSerializer(serializers.ModelSerializer):

    class Meta:
        model = Post
        fields = (
            "id",
            "creator",
            "last_modifier",
            "thread",
            "is_pinned",
            "content",
        )
        read_only_fields = (
            "id",
        )
        write_only_fields = (
            "creator",
            "last_modifier",
            "thread",
            "is_pinned",
            "content",
        )



class PostViewSerializer(serializers.ModelSerializer):

    creator = UserViewSerializer(required=True)
    last_modifier = UserViewSerializer(required=True)

    class Meta:
        model = Post
        fields = (
            "id",
            "creator",
            "last_modifier",
            "created_date",
            "modified_date",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "likes_count",
            "content",
        )



class PostUpdateProtectedSerializer(serializers.ModelSerializer):

    class Meta:
        model = Post
        fields = (
            "id",
            "thread",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "content",
        )
        read_only_fields = (
            "id",
        )



class PostUpdateSerializer(serializers.ModelSerializer):

    class Meta:
        model = Post
        fields = (
            "id",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "content",
        )
        read_only_fields = (
            "id",
            "is_hidden",
            "is_deleted",
            "is_pinned",
        )
