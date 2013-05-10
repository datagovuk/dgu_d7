import geb.*
import geb.pages.*

this.metaClass.mixin(cucumber.runtime.groovy.Hooks)
this.metaClass.mixin(cucumber.runtime.groovy.EN)

Given(~'^I have entered (\\w+) into the username box$') { String user ->
    // Express the Regexp above with the code you wish you had
    to RegisterPage
    at RegisterPage
    page.registerModule.userName.value(user)
}

Given(~'^I have entered "([^"]*)" into the email box$') { String email ->
    page.registerModule.email.value(email)
}

Given(~'^I have entered "([^"]*)" into the confirm email box$') { String email ->
    page.registerModule.emailConfirm.value(email)
}

Given(~'^I have entered (\\w+) into the password box$') { String pass ->
    page.registerModule.pass.value(pass)
}

Given(~'^I have entered (\\w+) into the confirm password box$') { String pass ->
    page.registerModule.passConfirm.value(pass)
}

When(~'^I press Create new account button$') { ->
    page.registerModule.createButton.click()
}

Then(~'^I can see registration confirmation message$') { ->
    page.emailVerifyMessage()
}