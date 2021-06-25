from flask import render_template, request, redirect, g

from app import db_manager
from app.main import bp
from app.main.forms import ForumCreateForm
from app.models.forum.forum import Forum

# import logging
# logger = logging.getLogger("app")
# logger.critical(user.id, forum_name)


@bp.route("/", methods=["GET", "POST"])
@bp.route("/main_page", methods=["GET", "POST"])
def main_page():
    user = g.user

    forum_create_form = ForumCreateForm()
    if forum_create_form.validate_on_submit():
        forum_name = forum_create_form.forum_name_field.data
        if forum_name:
            Forum.create(db_manager, None, user.id, forum_name)
        return redirect("/main_page")

    forums_data = Forum.get_forums(db_manager)

    page_template = "pages/main_page.html"
    page_data = {"page_name": "main_page", "page_title": "Main page"}
    return render_template(
        page_template,
        page_data=page_data,
        user=user,
        forum_create_form=forum_create_form,
        forums_data=forums_data,
    )


@bp.route("/profile_page")
def profile_page():
    user = g.user

    if not user.is_authenticated:
        return redirect("/main_page")

    page_template = "pages/profile_page.html"
    page_data = {"page_name": "profile_page", "page_title": "Profile page"}
    return render_template(
        page_template,
        page_data=page_data,
        user=user,
    )


@bp.route("/admin_page")
def admin_page():
    user = g.user

    if not user.is_admin:
        return redirect("/main_page")

    page_template = "pages/admin_page.html"
    page_data = {"page_name": "admin_page", "page_title": "Admin page"}
    return render_template(
        page_template,
        page_data=page_data,
        user=user,
    )
