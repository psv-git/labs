from rest_framework import serializers

from backend.thread.models import Thread




class ThreadCreateProtectedSerializer(serializers.ModelSerializer):

    class Meta:
        model = Thread
        fields = (
            "id",
            "parent_id",
            "parent_model",
            "creator",
            "last_modifier",
            "first_post",
            "last_post",
            "title",
        )
        read_only_fields = (
            "id", 
        )
        write_only_fields = (
            "parent_id",
            "parent_model",
            "creator",
            "first_post",
            "last_post",
            "title",
        )



class ThreadViewSerializer(serializers.ModelSerializer):

    class Meta:
        model = Thread
        fields = (
            "id",
            "created_date",
            "modified_date",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "last_post",
            "posts_count",
            "title",
        )



class ThreadUpdateProtectedSerializer(serializers.ModelSerializer):

    class Meta:
        model = Thread
        fields = (
            "id",
            "parent_id",
            "parent_model",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "last_post",
            "title",
        )
        read_only_fields = (
            "id",
        )
        write_only_fields = (
            "parent_id",
            "parent_model",
            "last_post",
        )



class ThreadUpdateSerializer(serializers.ModelSerializer):

    class Meta:
        model = Thread
        fields = (
            "id",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "last_post",
            "posts_count",
            "title",
        )
        read_only_fields = (
            "id",
            "is_hidden",
            "is_deleted",
            "is_pinned",
            "last_post",
        )
