from django.db import models
from django.conf import settings
from django.utils.translation import ugettext_lazy as _



class Post(models.Model):

    thread = models.ForeignKey("backend.Thread", on_delete=models.CASCADE)

    creator = models.ForeignKey(settings.AUTH_USER_MODEL, related_name="post_creator", on_delete=models.CASCADE)
    last_modifier = models.ForeignKey(settings.AUTH_USER_MODEL, related_name="post_last_modifier", on_delete=models.CASCADE)

    created_date = models.DateTimeField(_("created date"), auto_now_add=True)
    modified_date = models.DateTimeField(_("modified date"), auto_now=True)

    is_modified = models.BooleanField(_("modified"), blank=True, default=False)
    is_deleted = models.BooleanField(_("deleted"), blank=True, default=False)
    is_hidden = models.BooleanField(_("hidden"), blank=True, default=False)
    is_pinned = models.BooleanField(_("pinned"), blank=True, default=False)

    likes_count = models.IntegerField(_("likes count"), blank=True, default=0)
    content = models.TextField(_("post content"), blank=True, default="")

    # -------------------------------------------------------------------------

    class Meta:
        app_label = "backend"
        db_table = "post"
        get_latest_by = "created_date"
        ordering = (
            "-is_pinned", 
            "created_date"
        )

    # -------------------------------------------------------------------------

    def __str__(self):
        return self.content
