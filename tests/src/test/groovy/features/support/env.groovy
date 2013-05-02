package features.support

import geb.*
import geb.binding.BindingUpdater

this.metaClass.mixin(cucumber.runtime.groovy.Hooks)
this.metaClass.mixin(cucumber.runtime.groovy.EN)

Before () {
    bindingUpdater = new BindingUpdater (binding, new Browser ())
    bindingUpdater.initialize ()
}

After () {
    bindingUpdater.remove ()
}