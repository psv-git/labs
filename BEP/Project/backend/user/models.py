from django.db import models
from django.db.models.signals import post_save
from django.core.mail import send_mail
from django.dispatch import receiver
from django.utils.translation import ugettext_lazy as _
from django.contrib.auth.base_user import AbstractBaseUser

from .managers import UserManager



# user ========================================================================

class User(AbstractBaseUser):

    username = models.CharField(_("username"), max_length=150, unique=True)
    password = models.CharField(_("password"), max_length=128, unique=False)
    joined_date = models.DateTimeField(_("registered"), auto_now_add=True)
    last_login = models.DateTimeField(_("last login"), auto_now=True)
    is_active = models.BooleanField(_("active"), blank=True, default=True)
    is_superuser = models.BooleanField(_("superuser"), blank=True, default=False)
    is_staff = models.BooleanField(_("staff"), blank=True, default=False)

    objects = UserManager()

    USERNAME_FIELD = "username"
    REQUIRED_FIELDS = []

    class Meta:
        app_label = "backend"
        db_table = "user"
        get_latest_by = "joined_date"
        verbose_name = _("user")
        verbose_name_plural = _("users")



# user profile ================================================================

class UserProfile(models.Model):

    user = models.OneToOneField(User, on_delete=models.CASCADE, primary_key=True)
    first_name = models.CharField(_("user name"), max_length=30)
    last_name = models.CharField(_("user surname"), max_length=30)
    birth_date = models.DateField(_("birth date"), blank=True, null=True)
    email = models.EmailField(_("email"), blank=True)
    avatar_path = models.FilePathField()

    class Meta:
        app_label = "backend"
        db_table = "user_profile"
        verbose_name = _("user profile")
        verbose_name_plural = _("users profiles")


    def get_full_name(self):
        full_name = "{0} {1}".format(self.first_name, self.last_name)
        return full_name.strip()


    def get_short_name(self):
        return self.first_name


    def email_user(self, subject, message, from_email=None, **kwargs):
        send_mail(subject, message, from_email, [self.email], **kwargs)


@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        profile = UserProfile.objects.create(user=instance)
        profile.avatar_path = "/static/assets/images/user_avatar/{0}.png".format(instance.id)


@receiver(post_save, sender=User)
def save_user_profile(sender, instance, **kwargs):
    instance.userprofile.save()
