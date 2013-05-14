package geb.pages

import geb.*

class CancelUserConfirmPage extends DrupalPage{
	static url = "/user"

	static content = {
		cancelConfirmForm {$('form#user-cancel-confirm-form')}
		submit {$('input#edit-submit')}
	}

}