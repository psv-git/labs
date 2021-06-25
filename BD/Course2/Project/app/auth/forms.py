from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField
from wtforms.validators import DataRequired, Length, Email



class SignupForm(FlaskForm):
    user_name_field = StringField("Name", validators=[DataRequired(), Length(min=2, max=30)])
    user_email_field = StringField("Email", validators=[DataRequired(), Length(min=2, max=30), Email()])
    user_password_field = PasswordField("Password", validators=[DataRequired(), Length(min=2, max=16)])
    signup_submit = SubmitField("Sign Up")


class SigninForm(FlaskForm):
    user_email_field = StringField("Email", validators=[DataRequired(), Length(min=2, max=30), Email()])
    user_password_field = PasswordField("Password", validators=[DataRequired(), Length(min=2, max=16)])
    remember_me_checkbox = BooleanField("Remember me")
    signin_submit = SubmitField("Sign In")
