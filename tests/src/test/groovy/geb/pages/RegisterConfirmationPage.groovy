package geb.pages

import geb.*

class RegisterConfirmationPage extends DrupalPage{
	static url = "/"

	static at = {
		$("div.alert-success").text().contains("Thanks for registering")
	}

}