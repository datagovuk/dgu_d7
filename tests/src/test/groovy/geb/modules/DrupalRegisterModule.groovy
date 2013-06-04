package geb.modules

import geb.Browser
import geb.Module
import geb.Page

import geb.pages.RegisterPage

class DrupalRegisterModule extends Module {
	static content = {
		userName {$("input", id: "edit-name--2")}
		email {$("input", id: "edit-mail")}
		emailConfirm {$("input", id: "edit-conf-mail")}
		pass {$("input", id: "edit-pass-pass1")}
		passConfirm {$("input", id: "edit-pass-pass2")}
		createButton(to: RegisterPage) { $("button", id: "edit-submit--2") }
	}
}
