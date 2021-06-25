from django.db import models
from django.utils.translation import ugettext_lazy as _
from django.contrib.contenttypes.models import ContentType



class Module(models.Model):

    model = models.ForeignKey(ContentType, on_delete=models.PROTECT)

    name = models.CharField(_("module name"), max_length=100, unique=True)

    # -------------------------------------------------------------------------

    class Meta:
        app_label = "backend"
        db_table = "module"

    # -------------------------------------------------------------------------

    def __str__(self):
        return self.name
