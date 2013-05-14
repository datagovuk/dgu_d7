package geb.pages

import geb.*

class RegisterPage extends DrupalPage{
	static url = "/user/register"

	static at = { 
		$("body")?.classes().contains('page-user-register') 
	}

}