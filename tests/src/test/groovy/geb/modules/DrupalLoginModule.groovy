package geb.modules

import geb.Browser
import geb.Module
import geb.Page

import geb.pages.AdminPage


class DrupalLoginModule extends Module {
	//static base = { $("form")."user-login-form" }
	static content = {
		user {$("input", id: "edit-name")}
		pass {$("input", id: "edit-pass")}
		loginButton(to: AdminPage) { $("button", id: "edit-submit") }
	}


}