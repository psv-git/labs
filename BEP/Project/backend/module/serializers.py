from rest_framework import serializers

from backend.module.models import Module



class ModuleSerializer(serializers.ModelSerializer):

    class Meta:
        model = Module
        fields = (
            "id",
            "model_id",
            "name",
        )
