from rest_framework.viewsets import GenericViewSet
from rest_framework.settings import api_settings



class MultiSerializerViewSet(GenericViewSet):

    queryset = None
    serializers = {}

    # -------------------------------------------------------------------------

    def get_serializer_class(self):
        return self.serializers.get(self.action, None)


    def get_success_headers(self, data):
        try:
            return {"Location": str(data[api_settings.URL_FIELD_NAME])}
        except (TypeError, KeyError):
            return {}


    def perform_create(self, serializer):
        serializer.save()


    def perform_update(self, instance, serializer):
        if getattr(instance, '_prefetched_objects_cache', None):
            # If 'prefetch_related' has been applied to a queryset, we need to
            # forcibly invalidate the prefetch cache on the instance.
            instance._prefetched_objects_cache = {}
        serializer.save()


    def perform_destroy(self, instance):
        instance.delete()

    # -------------------------------------------------------------------------

    def create(self, request, *args, **kwargs):
        raise NotImplementedError("Must implement 'create' method.")


    def list(self, request, *args, **kwargs):
        raise NotImplementedError("Must implement 'list' method.")


    def retrieve(self, request, *args, **kwargs):
        raise NotImplementedError("Must implement 'retrieve' method.")


    def update(self, request, *args, **kwargs):
        raise NotImplementedError("Must implement 'update' method.")


    def partial_update(self, request, *args, **kwargs):
        kwargs["partial"] = True
        return self.update(request, *args, **kwargs)


    def destroy(self, request, *args, **kwargs):
        raise NotImplementedError("Must implement 'destroy' method.")

    # -------------------------------------------------------------------------

    def post(self, request, *args, **kwargs):
        return self.retrieve(request, *args, **kwargs)


    def get(self, request, *args, **kwargs):
        return self.retrieve(request, *args, **kwargs)


    def put(self, request, *args, **kwargs):
        return self.update(request, *args, **kwargs)


    def patch(self, request, *args, **kwargs):
        return self.partial_update(request, *args, **kwargs)


    def delete(self, request, *args, **kwargs):
        return self.destroy(request, *args, **kwargs)
