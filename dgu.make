core = 7.x
api = 2

; Modules
; --------

projects[strongarm][subdir] = "contrib"
projects[diff][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[pathauto][subdir] = "contrib"

projects[admin_menu][version] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

projects[module_filter][version] = "1.7"
projects[module_filter][subdir] = "contrib"

projects[ctools][subdir] = "contrib"

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

projects[reply][type] = "module"
projects[reply][download][type] = "git"
projects[reply][download][url] = "http://git.drupal.org/project/reply.git"
projects[reply][download][revision] = "86da8b1c474de3ca63c4bf62caf976635e1c637c"
projects[reply][subdir] = "contrib"
 projects[reply][patch][] = "http://drupal.org/files/1983940-reply_login_register.patch"
projects[reply][patch][] = "http://drupal.org/files/1439600-exportable_reply_bundles-20_0.patch"
projects[reply][patch][] = "http://drupal.org/files/bundle_label_1920358.patch"
projects[reply][patch][] = "http://drupal.org/files/reply_max_depth.patch"

projects[rules][version] = "2.3"
projects[rules][subdir] = "contrib"

projects[field_formatter_settings][version] = "1.0"
projects[field_formatter_settings][subdir] = "contrib"

projects[field_replies][download][type] = "git"
projects[field_replies][download][url] = "http://git.drupal.org/project/field_replies.git"
projects[field_replies][subdir] = "contrib"

projects[entityreference][version] = "1.0"
projects[entityreference][subdir] = "contrib"

projects[migrate][type] = "module"
projects[migrate][download][type] = "git"
projects[migrate][download][url] = "http://git.drupal.org/project/migrate.git"
projects[migrate][download][tag] = "7.x-2.5"
projects[migrate][subdir] = "contrib"
projects[migrate][patch][] = "http://drupal.org/files/pass_warn_on_overrides-3.patch"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][subdir] = "contrib"

projects[migrate_d2d][version] = "2.0"
projects[migrate_d2d][subdir] = "contrib"

projects[fivestar][version] = "2.0-alpha2"
projects[fivestar][subdir] = "contrib"

projects[workbench_moderation][version] = "1.2"
projects[workbench_moderation][subdir] = "contrib"

projects[file_entity][version] = "2.0-unstable7"
projects[file_entity][subdir] = "contrib"

projects[lexicon][version] = "1.10"
projects[lexicon][version] = "contrib"

projects[media][version] = "2.0-unstable7"
projects[media][subdir] = "contrib"

projects[votingapi][version] = "2.10"
projects[votingapi][subdir] = "contrib"

projects[vote_up_down][type] = "module"
projects[vote_up_down][version] = "1.0-alpha1"
projects[vote_up_down][subdir] = "contrib"

projects[workbench][version] = "1.1"
projects[workbench][subdir] = "contrib"

projects[workbench_media][version] = "2.1"
projects[workbench_media][subdir] = "contrib"

projects[field_group][version] = "1.1"
projects[field_group][subdir] = "contrib"

projects[conditional_fields][version] = "3.x-dev"
projects[conditional_fields][subdir] = "contrib"

projects[logintoboggan][version] = "1.3"
projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][patch][] = "http://drupal.org/files/logintoboggin-unified-form-validation-errors-1163172-13.patch"

projects[stringoverrides][version] = "1.8"
projects[stringoverrides][subdir] = "contrib"

projects[ckan][type] = "module"
projects[ckan][download][type] = "git"
projects[ckan][download][url] = "http://git.drupal.org/project/ckan.git"
projects[ckan][download][branch] = "ckan_dgu_7.x-1.x"
projects[ckan][subdir] = "contrib"

projects[composer_manager][subdir] = "contrib"

projects[panels][version] = "3.3"
projects[panels][subdir] = "contrib"


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
