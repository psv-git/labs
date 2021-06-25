from django.urls import path, re_path

from backend.views import *



urlpatterns = [

# auth ========================================================================

    path("get/token", TokenObtainView.as_view(), name="token_obtain_pair"),
    # path("refresh/token", TokenRefreshView.as_view(), name="token_refresh"),
    # path("verify/token", TokenVerifyView.as_view(), name="token_verify"),

# user ========================================================================

    path("create/user", UserViewSet.as_view({"post": "create"})),

    path("get/users", UserViewSet.as_view({"get": "list"})),

    path("get/user/<int:pk>", UserViewSet.as_view({"get": "retrieve"})),

    path("update/user/<int:pk>", UserViewSet.as_view({"put": "update"})),
    path("partial-update/user/<int:pk>", UserViewSet.as_view({"patch": "partial_update"})),

    path("delete/user/<int:pk>", UserViewSet.as_view({"delete": "destroy"})),

# module ======================================================================

    path("create/module", ModuleViewSet.as_view({"post": "create"})),

    path("get/modules", ModuleViewSet.as_view({"get": "list"})),
    path("get/module/<int:pk>", ModuleViewSet.as_view({"get": "retrieve"})),
    path("get/module/<str:module_name>", ModuleViewSet.as_view({"get": "retrieve"})),

# forum =======================================================================

    path("create/forum", ForumViewSet.as_view({"post": "create"})),

    path("get/forums", ForumViewSet.as_view({"get": "list"})),
    path("get/forum/<int:pk>", ForumViewSet.as_view({"get": "retrieve"})),

    path("update/forum/<int:pk>", ForumViewSet.as_view({"patch": "partial_update"})),

    path("delete/forum/<int:pk>", ForumViewSet.as_view({"patch": "delete"})),
    path("hide/forum/<int:pk>", ForumViewSet.as_view({"patch": "hide"})),

    # path("destroy/forum/<int:pk>", ForumViewSet.as_view({"delete": "destroy"})),

# thread ======================================================================

    path("create/thread", ThreadViewSet.as_view({"post": "create"})),

    path("get/threads", ThreadViewSet.as_view({"get": "list"})),
    path("get/thread/<int:pk>", ThreadViewSet.as_view({"get": "retrieve"})),

    path("update/thread/<int:pk>", ThreadViewSet.as_view({"patch": "partial_update"})),

    # path("destroy/thread/<int:pk>", ThreadViewSet.as_view({"delete": "destroy"})),

# post ========================================================================

    path("create/post", PostViewSet.as_view({"post": "create"})),

    path("get/posts/<int:thread_id>", PostViewSet.as_view({"get": "list"})),
    path("get/post/<int:pk>", PostViewSet.as_view({"get": "retrieve"})),

    path("update/post/<int:pk>", PostViewSet.as_view({"patch": "partial_update"})),

    path("delete/post/<int:pk>", PostViewSet.as_view({"patch": "delete"})),
    path("hide/post/<int:pk>", PostViewSet.as_view({"patch": "hide"})),
    path("pin/post/<int:pk>", PostViewSet.as_view({"patch": "pin"})),

    # path("destroy/post/<int:pk>", PostViewSet.as_view({"delete": "destroy"})),

]
