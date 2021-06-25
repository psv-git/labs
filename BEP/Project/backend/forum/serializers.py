from rest_framework import serializers

from backend.forum.models import Forum



class ForumCreateProtectedSerializer(serializers.ModelSerializer):

    class Meta:
        model = Forum
        fields = (
            "id",
            "model",
            "parent_id",
            "parent_model",
            "creator",
            "last_modifier",
            "name",
        )
        read_only_fields = (
            "id",
        )
        write_only_fields = (
            "model",
            "parent_id",
            "parent_model",
            "creator",
            "last_modifier",
            "name",
        )



class ForumViewSerializer(serializers.ModelSerializer):

    class Meta:
        model = Forum
        fields = (
            "id",
            "model",
            "is_hidden",
            "is_deleted",
            "name",
        )



class ForumUpdateProtectedSerializer(serializers.ModelSerializer):

    class Meta:
        model = Forum
        fields = (
            "id",
            "parent_id",
            "parent_model",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "name",
        )
        read_only_fields = (
            "id",
        )
        write_only_fields = (
            "parent_id",
            "parent_model",
            "last_modifier",
            "is_modified",
            "is_hidden",
            "is_deleted",
            "name",
        )
