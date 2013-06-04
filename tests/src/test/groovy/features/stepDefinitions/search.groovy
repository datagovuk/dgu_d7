import geb.*

this.metaClass.mixin(cucumber.runtime.groovy.Hooks)
this.metaClass.mixin(cucumber.runtime.groovy.EN)

Given(~'^I have entered search term into search box$') { ->
    // Express the Regexp above with the code you wish you had
    //throw new PendingException()
}


When(~'^I press search$') { ->
    // Express the Regexp above with the code you wish you had
}

Then(~'^I can see the search results$') { ->
    // Express the Regexp above with the code you wish you had
    //throw new PendingException()
}
