package geb.pages

import geb.*
import geb.modules.DrupalLoginModule

class DrupalPage extends Page {
    static content = {
        loginModule { module DrupalLoginModule }
    }
}