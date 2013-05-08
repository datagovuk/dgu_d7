package geb.pages

import geb.*
import geb.modules.DrupalLoginModule
import geb.modules.DrupalRegisterModule

class DrupalPage extends Page {
    static content = {
        loginModule { module DrupalLoginModule }
        registerModule { module DrupalRegisterModule }
    }
}