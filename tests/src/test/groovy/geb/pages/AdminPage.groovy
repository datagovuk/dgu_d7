package geb.pages

import geb.*

class AdminPage extends Page{
	static url = "/admin"
	static at = {
		assert $("h1").text() == "Administration"
	}
}