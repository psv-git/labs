from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired, Length



class ForumCreateForm(FlaskForm):
    forum_name_field = StringField("Forum name", validators=[DataRequired(), Length(min=2, max=50)])
    forum_create_submit = SubmitField("Create forum")
