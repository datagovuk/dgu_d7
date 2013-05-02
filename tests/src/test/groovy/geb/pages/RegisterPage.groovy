package geb.pages

import geb.*

class RegisterPage extends Page{
	static url = "/admin"
	static at = {
		assert $("h1").text() == "Administration"
	}
}
/*
<div class="alert alert-block alert-success">
  <a class="close" data-dismiss="alert" href="#">x</a>
<h2 class="element-invisible">Status message</h2>
A validation e-mail has been sent to your e-mail address. In order to gain full access to the site, you will need to follow the instructions in that message.</div>
*
* as a registered user I want to have my email verified so that I can show that I'm legitimate user
* as a registered user I want to specify my password ate the time of registration so that it works like most sites
*
*
*/