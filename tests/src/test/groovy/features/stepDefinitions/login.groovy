import geb.*
import geb.pages.*

this.metaClass.mixin(cucumber.runtime.groovy.Hooks)
this.metaClass.mixin(cucumber.runtime.groovy.EN)

Given(~'^I have entered (\\w+) into the user box$') { String user ->
    // Express the Regexp above with the code you wish you had
    to HomePage
    at HomePage
    page.loginModule.user.value(user)
}

Given(~'^I have entered (\\w+) into the password$') { String Pass ->
    page.loginModule.pass.value(Pass)
}

When(~'^I press login$') { ->
    page.loginModule.loginButton.click()
}

Then(~'^I can see the admin menu$') { ->
    to AdminPage
    at AdminPage
}