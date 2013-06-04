package geb.pages

import geb.*

class UserPage extends DrupalPage{
	static url = "/users"

	static content = {
		editLink { $('ul.nav-tabs li a', text: "Edit") }

	}

}