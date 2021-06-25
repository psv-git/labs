from django.urls import path, re_path, include
from django.conf import settings
from django.conf.urls.static import static
from django.contrib.staticfiles.urls import staticfiles_urlpatterns

from .views import IndexView



urlpatterns = [
    path("api/v0/", include("api_v0.urls"), name="api_v0"),
    re_path(r"^.*", IndexView.as_view(), name="app"),
]


urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
urlpatterns += staticfiles_urlpatterns()
