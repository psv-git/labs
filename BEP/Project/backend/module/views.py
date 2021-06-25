from django.shortcuts import get_object_or_404, get_list_or_404
from rest_framework import status
from rest_framework.response import Response
from django.contrib.contenttypes.models import ContentType

from backend.module.serializers import *
from backend.utils.views import MultiSerializerViewSet



class ModuleViewSet(MultiSerializerViewSet):

    queryset = Module.objects.all()

    serializers = {
        "create": ModuleSerializer,
        "list": ModuleSerializer,
        "retrieve": ModuleSerializer,
        "update": ModuleSerializer,
        "partial_update": ModuleSerializer,
    }

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        model_id = ContentType.objects.get_for_model(Module).id
        module_data = request.data
        module_data["model_id"] = model_id

        module_serializer = self.get_serializer(data=module_data)
        module_serializer.is_valid(raise_exception=True)
        self.perform_create(module_serializer)

        return Response(module_serializer.data, status=status.HTTP_201_CREATED)


    def list(self, request, *args, **kwargs):
        queryset = self.filter_queryset(self.get_queryset())
        list_serializer = self.get_serializer(queryset, many=True)

        return Response(list_serializer.data)


    def retrieve(self, request, *args, **kwargs):
        module_name = kwargs.get("module_name", None)

        if module_name:
            module_instance = get_object_or_404(self.queryset, name=module_name)
        else:
            module_instance = self.get_object()
        module_serializer = self.get_serializer(module_instance)

        return Response(module_serializer.data)


    def update(self, request, *args, **kwargs):
        update_data = request.data
        partial = kwargs.pop("partial", False)

        module_instance = self.get_object()
        module_serializer = self.get_serializer(module_instance, data=update_data, partial=partial)
        module_serializer.is_valid(raise_exception=True)
        self.perform_update(module_instance, module_serializer)

        return Response(module_serializer.data)


    def destroy(self, request, *args, **kwargs):
        module_instance = self.get_object()
        self.perform_destroy(module_instance)

        return Response(status=status.HTTP_204_NO_CONTENT)
