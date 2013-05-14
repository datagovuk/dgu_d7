package geb.pages

import geb.*

class UserEditPage extends DrupalPage{
	static url = "/user"

	static content = {
		cancelAccountLink(wait: true) { $('input#edit-cancel') } 

	}

}