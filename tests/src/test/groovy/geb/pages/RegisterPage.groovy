package geb.pages

import geb.*

class RegisterPage extends DrupalPage{
	static url = "/user/register"

	static at = { $('body').classes().contains('page-user-register') }

  static emailVerifyMessage = {
    assert $("div.alert-success", text: contains("Thanks for registering with data.gov.uk - to complete registration - you will soon get an email to verify the email you supplied."))
  }
}