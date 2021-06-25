from rest_framework import serializers
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer

from .models import *



# auth ========================================================================

class TokenObtainSerializer(TokenObtainPairSerializer):

    def validate(self, attrs):
        data = super().validate(attrs)

        refresh = self.get_token(self.user)

        data["refresh"] = str(refresh)
        data["access"] = str(refresh.access_token)
        data["user_id"] = self.user.id

        return data



# user profile ================================================================

class UserProfileSerializer(serializers.ModelSerializer):

    class Meta:
        model = UserProfile
        exclude = (
            "user",
            "birth_date",
            "email",
        )
        read_only_fields = (
            "avatar_path",
        )



# user ========================================================================


class UserCreateSerializer(serializers.ModelSerializer):

    userprofile = UserProfileSerializer(required=True)

    class Meta:
        model = User
        fields = (
            "username",
            "password",
        )
        write_only_fields = (
            "password",
        )



class UserViewSerializer(serializers.ModelSerializer):

    userprofile = UserProfileSerializer(required=True)

    class Meta:
        model = User
        fields = (
            "userprofile",
        )



class UserUpdateSerializer(serializers.ModelSerializer):

    userprofile = UserProfileSerializer(required=True)

    class Meta:
        model = User
        fields = (
            "userprofile",
        )
