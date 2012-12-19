core = 7.x
api = 2

; Modules
; --------

projects[strongarm][subdir] = "contrib"
projects[diff][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[pathauto][subdir] = "contrib"





projects[admin_menu][version] = "3.0-rc3"
projects[admin_menu][subdir] = "contrib"

projects[ctools][version] = "1.2"
projects[ctools][subdir] = "contrib"

projects[features][version] = "1.0"
projects[features][subdir] = "contrib"

projects[views][version] = "3.5"
projects[views][subdir] = "contrib"

projects[link][version] = "1.0"
projects[link][subdir] = "contrib"

projects[email][version] = "1.2"
projects[email][subdir] = "contrib"

projects[entity][version] = "1.0-rc3"
projects[entity][subdir] = "contrib"
projects[entity][patch][] = "http://drupal.org/files/1514764-fix_entity_conditions-20.patch"

projects[entityreference][version] = "1.2"
projects[entityreference][subdir] = "contrib"

projects[migrate][version] = "2.5"
projects[migrate][subdir] = "contrib"

projects[migrate_extra][version] = "2.5"
projects[migrate_extra][subdir] = "contrib"



; Themes
; --------
projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "2.0-beta2"
  
; Libraries
; ---------
libraries[jquery][download][type] = "file"
libraries[jquery][download][url] = "https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"
libraries[bootstrap][download][type] = "file"
libraries[bootstrap][download][url] = "http://twitter.github.com/bootstrap/assets/bootstrap.zip"
libraries[bootstrap][destination] = "themes/contrib/bootstrap"
