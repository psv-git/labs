from flask import render_template, request, redirect, g
from flask_login import login_user, logout_user, current_user

from app import db_manager
from app import login_manager
from app.auth import bp
from app.auth.forms import SignupForm, SigninForm
from app.models.user.user import User



@login_manager.user_loader
def load_user(email):
    return User.get_user(db_manager, email)


@bp.route("/signup_page", methods=["GET", "POST"])
def sign_up():
    signup_form = SignupForm()
    if signup_form.validate_on_submit():
        user_name = signup_form.user_name_field.data
        user_email = signup_form.user_email_field.data
        user_password = signup_form.user_password_field.data
        if user_name and user_email and user_password:
            User.create(db_manager, user_name, user_email, user_password)
        return redirect("/signin_page")

    page_template = "auth/signup_page.html"
    page_data = {"page_name": "signup_page", "page_title": "Sign Up page"}
    return render_template(
        page_template,
        page_data=page_data,
        signup_form=signup_form,
    )


@bp.route("/signin_page", methods=["GET", "POST"])
def sign_in():
    if g.user.is_authenticated:
        return redirect("/main_page")

    signin_form = SigninForm()
    if signin_form.validate_on_submit():
        user_email = signin_form.user_email_field.data
        user = load_user(user_email)
        if user is not None:
            user_password = signin_form.user_password_field.data
            if user.check_password(user_password):
                is_remember = signin_form.remember_me_checkbox.data
                login_user(user, remember=is_remember)
                return redirect("/main_page")

    page_template = "auth/signin_page.html"
    page_data = {"page_name": "signin_page", "page_title": "Sign In page"}
    return render_template(
        page_template,
        page_data=page_data,
        signin_form=signin_form,
    )


@bp.route("/logout")
def logout():
    logout_user()
    return redirect("/main_page")
