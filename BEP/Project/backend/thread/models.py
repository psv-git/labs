from django.db import models
from django.conf import settings
from django.utils.translation import ugettext_lazy as _
from django.contrib.contenttypes.models import ContentType



class Thread(models.Model):

    parent_id = models.PositiveIntegerField()
    parent_model = models.ForeignKey(ContentType, related_name="thread_parent_model", on_delete=models.PROTECT)

    creator = models.ForeignKey(settings.AUTH_USER_MODEL, related_name="thread_creator", on_delete=models.CASCADE)
    last_modifier = models.ForeignKey(settings.AUTH_USER_MODEL, related_name="thread_last_modifier", on_delete=models.CASCADE)

    first_post = models.ForeignKey("backend.Post", related_name="first_post", on_delete=models.CASCADE, blank=True, null=True)
    last_post = models.ForeignKey("backend.Post", related_name="last_post", on_delete=models.CASCADE, blank=True, null=True)

    created_date = models.DateTimeField(_("created date"), auto_now_add=True)
    modified_date = models.DateTimeField(_("modified date"), auto_now=True)
    
    is_modified = models.BooleanField(_("modified"), blank=True, default=False)
    is_deleted = models.BooleanField(_("deleted"), blank=True, default=False)
    is_hidden = models.BooleanField(_("hidden"), blank=True, default=False)
    is_pinned = models.BooleanField(_("pinned"), blank=True, default=False)

    posts_count = models.IntegerField(_("posts count"), blank=True, default=1)

    title = models.CharField(_("topic title"), max_length=255)

    # -------------------------------------------------------------------------

    class Meta:
        app_label = "backend"
        db_table = "thread"
        get_latest_by = "created_date"
        ordering = (
            "is_pinned", 
            "-modified_date"
        )

    # -------------------------------------------------------------------------

    def __str__(self):
        return self.title
