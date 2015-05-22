core = 7.x
api = 2

; Modules
; --------

projects[bootstrap_tour][version] = "1.0-beta9"
projects[bootstrap_tour][subdir] = "contrib"

projects[apachesolr][type] = "module"
projects[apachesolr][download][type] = "git"
projects[apachesolr][download][url] = "http://git.drupal.org/project/apachesolr.git"
projects[apachesolr][download][tag] = "7.x-1.4"
projects[apachesolr][subdir] = "contrib"
projects[apachesolr][patch][] = "http://raw.github.com/datagovuk/dgu_d7/master/patches/apachesolr-text-field-mapping.patch"

projects[apachesolr_autocomplete][version] = "1.3"
projects[apachesolr_autocomplete][subdir] = "contrib"
; In review patch to apachesolr_autocomplete for autocompleting with filters applied.
projects[apachesolr_autocomplete][patch][] = "http://drupal.org/files/1444038-custom-page-autocomplete-with-panels.patch"

projects[apachesolr_panels][type] = "module"
projects[apachesolr_panels][download][type] = "git"
projects[apachesolr_panels][download][url] = "http://git.drupal.org/project/apachesolr_panels.git"
projects[apachesolr_panels][download][revision] = "7b49e370f22866283d8fe2c88bb66e8421d65516"
projects[apachesolr_panels][subdir] = "contrib"
projects[apachesolr_panels][patch][] = "http://drupal.org/files/apachesolr_panels-retain-facets-2103701-2.patch"

projects[book_access][version] = "2.1"
projects[book_access][subdir] = "contrib"

projects[facetapi][version] = "1.3"
projects[facetapi][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"
# Prevent losing manual aliases with node_save() calls https://drupal.org/node/936222
projects[pathauto][patch][] = "http://drupal.org/files/pathauto-persist-936222-130-pathauto-state.patch"

projects[admin_menu][version] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

projects[module_filter][version] = "1.7"
projects[module_filter][subdir] = "contrib"

projects[ctools][version] = "1.6"
projects[ctools][subdir] = "contrib"

projects[features][version] = "2.0"
projects[features][subdir] = "contrib"
projects[features][patch][] = "http://raw.github.com/datagovuk/dgu_d7/master/patches/features_dont_convert_strings_to_integers.patch"

projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

projects[views_data_export][version] = "3.0-beta6"
projects[views_data_export][subdir] = "contrib"

projects[better_exposed_filters][version] = "3.0-beta4"
projects[better_exposed_filters][subdir] = "contrib"

projects[link][version] = "1.1"
projects[link][subdir] = "contrib"
projects[linkchecker][version] = "1.1"
projects[linkchecker][subdir] = "contrib"
projects[extlink][version] = "1.13"
projects[extlink][subdir] = "contrib"

projects[email][version] = "1.2"
projects[email][subdir] = "contrib"

projects[entity][version] = "1.0-rc3"
projects[entity][subdir] = "contrib"
projects[entity][patch][] = "http://drupal.org/files/1514764-fix_entity_conditions-20.patch"

projects[reply][type] = "module"
projects[reply][download][type] = "git"
projects[reply][download][url] = "http://git.drupal.org/project/reply.git"
projects[reply][download][revision] = "4ea5b1b863c9bf2fac46eaf04143192086bf7f1d"
projects[reply][subdir] = "contrib"
projects[reply][patch][] = "http://raw.github.com/ratajczak/dgu_d7/master/patches/reply_bundle_filter.patch"
#projects[reply][patch][] = "http://drupal.org/files/issues/reply_mollom_integration_2.patch"

projects[rules][version] = "2.8"
projects[rules][subdir] = "contrib"
#https://www.drupal.org/node/2186363
projects[rules][patch][] = "http://drupal.org/files/issues/rules-fix-fatal-error-features-revert-2186363-1.patch"

projects[rules_url_argument][version] = "1.2"
projects[rules_url_argument][subdir] = "contrib"

projects[field_formatter_settings][version] = "1.0"
projects[field_formatter_settings][subdir] = "contrib"

projects[field_replies][download][type] = "git"
projects[field_replies][download][url] = "http://git.drupal.org/project/field_replies.git"
projects[field_replies][subdir] = "contrib"

projects[field_permissions][version] = "1.0-beta2"
projects[field_permissions][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[migrate][type] = "module"
projects[migrate][download][type] = "git"
projects[migrate][download][url] = "http://git.drupal.org/project/migrate.git"
projects[migrate][download][tag] = "7.x-2.6-rc1"
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][subdir] = "contrib"

projects[migrate_d2d][version] = "2.0"
projects[migrate_d2d][subdir] = "contrib"

projects[fivestar][version] = "2.0-alpha2"
projects[fivestar][subdir] = "contrib"

projects[workbench_moderation][type] = "module"
projects[workbench_moderation][download][type] = "git"
projects[workbench_moderation][download][url] = "http://git.drupal.org/project/workbench_moderation.git"
projects[workbench_moderation][download][revision] = "e7144c9f866879d0679b8116c7715865a91c6878"
projects[workbench_moderation][subdir] = "contrib"

projects[lexicon][version] = "1.10"
projects[lexicon][subdir] = "contrib"

projects[file_entity][version] = "2.0-alpha3"
projects[file_entity][subdir] = "contrib"

projects[media][version] = "2.0-alpha4"
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

projects[conditional_fields][type] = "module"
projects[conditional_fields][download][type] = "git"
projects[conditional_fields][download][url] = "http://git.drupal.org/project/conditional_fields.git"
projects[conditional_fields][download][revision] = "cd29b003a592d375f3fdb4c46f5639d0f26ed0be"
projects[conditional_fields][patch][] = "http://drupal.org/files/issues/conditional_fields-jquery_update_1.7_states_incompatible-1815896.patch"
projects[conditional_fields][subdir] = "contrib"

projects[logintoboggan][version] = "1.5"
projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][patch][] = "http://drupal.org/files/logintoboggin-unified-form-validation-errors-1163172-13.patch"

projects[stringoverrides][version] = "1.8"
projects[stringoverrides][subdir] = "contrib"

projects[ckan][type] = "module"
projects[ckan][download][type] = "git"
projects[ckan][download][url] = "http://git.drupal.org/project/ckan.git"
projects[ckan][download][branch] = "ckan_dgu_7.x-1.x"
projects[ckan][subdir] = "contrib"

projects[ckan_publisher_tree][type] = "module"
projects[ckan_publisher_tree][download][type] = "git"
projects[ckan_publisher_tree][download][url] = "http://git.drupal.org/project/ckan_publisher_tree.git"
projects[ckan_publisher_tree][download][branch] = "7.x-1.x"
projects[ckan_publisher_tree][subdir] = "contrib"

projects[composer_manager][version] = "1.7"
projects[composer_manager][subdir] = "contrib"

projects[panels][version] = "3.3"
projects[panels][subdir] = "contrib"

projects[fieldable_panels_panes][version] = "1.5"
projects[fieldable_panels_panes][subdir] = "contrib"

projects[context][version] = "3.0-beta7"
projects[context][subdir] = "contrib"

projects[services][version] = "3.11"
projects[services][subdir] = "contrib"

projects[services_views][version] = "1.0"
projects[services_views][subdir] = "contrib"

projects[smtp][version] = "1.0"
projects[smtp][subdir] = "contrib"

projects[libraries][version] = "2.1"
projects[libraries][subdir] = "contrib"

projects[wysiwyg][type] = "module"
projects[wysiwyg][download][type] = "git"
projects[wysiwyg][download][url] = "http://git.drupal.org/project/wysiwyg.git"
projects[wysiwyg][download][revision] = "898d022cf7d0b6c6a6e7d813199d561b4ad39f8b"
projects[wysiwyg][subdir] = "contrib"

projects[redirect][type] = "module"
projects[redirect][download][type] = "git"
projects[redirect][download][url] = "http://git.drupal.org/project/redirect.git"
projects[redirect][download][revision] = "20542c13c3004adf495633836842a83b7f343892"
projects[redirect][subdir] = "contrib"
projects[redirect][patch][] = "https://www.drupal.org/files/issues/fix_and_prevent-1796596-297.patch"

projects[tagclouds][version] = "1.9"
projects[tagclouds][subdir] = "contrib"

projects[mollom][version] = "2.13"
projects[mollom][subdir] = "contrib"

projects[google_analytics][version] = "2.1"
projects[google_analytics][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.1"
projects[views_bulk_operations][subdir] = "contrib"

projects[advuser][version] = "3.0-beta1"
projects[advuser][subdir] = "contrib"

projects[jquery_update][type] = "module"
projects[jquery_update][download][type] = "git"
projects[jquery_update][download][url] = "http://git.drupal.org/project/jquery_update.git"
projects[jquery_update][download][revision] = "65eecb0f1fc69cf6831a66440f72e33a1effb1f3"
projects[jquery_update][subdir] = "contrib"

projects[flag][version] = "3.2"
projects[flag][subdir] = "contrib"

projects[session_api][version] = "1.0-rc1"
projects[session_api][subdir] = "contrib"

projects[emptyparagraphkiller][version] = "1.0-beta2"
projects[emptyparagraphkiller][subdir] = "contrib"

projects[imagefield_crop][type] = "module"
projects[imagefield_crop][download][type] = "git"
projects[imagefield_crop][download][url] = "http://git.drupal.org/project/imagefield_crop.git"
;commit 366d78ae2cc260739555edeaf6eb00d2f2d8ee8d matches 7.x-1.1 tag
projects[imagefield_crop][download][revision] = "366d78ae2cc260739555edeaf6eb00d2f2d8ee8d"
projects[imagefield_crop][subdir] = "contrib"
projects[imagefield_crop][patch][] = "http://raw.github.com/datagovuk/dgu_d7/master/patches/imagefield_crop_undefined_index.patch"

projects[emptyparagraphkiller][version] = "1.0-beta2"
projects[emptyparagraphkiller][subdir] = "contrib"

projects[smart_trim][version] = "1.4"
projects[smart_trim][subdir] = "contrib"

projects[message][version] = "1.9"
projects[message][subdir] = "contrib"

projects[message_notify][version] = "2.5"
projects[message_notify][subdir] = "contrib"

projects[message_subscribe][version] = "1.0-rc2"
projects[message_subscribe][subdir] = "contrib"

projects[message_digest][type] = "module"
projects[message_digest][download][type] = "git"
projects[message_digest][download][url] = "http://git.drupal.org/project/message_digest.git"
projects[message_digest][download][revision] = "2ad5c154dc21028d153e455bda6c27224862bc62"
projects[message_digest][subdir] = "contrib"
projects[message_digest][patch][] = "https://www.drupal.org/files/issues/message_digest-remove_mail_header-2236179-8.patch"
projects[message_digest][patch][] = "https://www.drupal.org/files/issues/message_digest_pass_uid.patch"

projects[message_ui][version] = "1.4"
projects[message_ui][subdir] = "contrib"

projects[quickedit][version] = "1.1"
projects[quickedit][subdir] = "contrib"

projects[autologout][version] = "4.3"
projects[autologout][subdir] = "contrib"

projects[maxlength][version] = "3.0"
projects[maxlength][subdir] = "contrib"

projects[mass_contact][version] = "1.0"
projects[mass_contact][subdir] = "contrib"

projects[contact_deeplink][version] = "1.0"
projects[contact_deeplink][subdir] = "contrib"

projects[empty_fields][version] = "2.0"
projects[empty_fields][subdir] = "contrib"

projects[print][version] = "2.0"
projects[print][subdir] = "contrib"

projects[linkit][version] = "3.3"
projects[linkit][subdir] = "contrib"

;TODO - lock to some revision
projects[d3][subdir] = "contrib"

; Themes
; --------
projects[bootstrap][type] = "theme"
projects[bootstrap][subdir] = "contrib"
projects[bootstrap][download][type] = "git"
projects[bootstrap][download][url] = "http://git.drupal.org/project/bootstrap.git"
projects[bootstrap][download][tag] = "7.x-3.0"

; Libraries
; --------
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.2/ckeditor_4.2_full.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = "https://github.com/jashkenas/backbone/archive/1.1.2.zip"
libraries[backbone][directory_name] = "backbone"
libraries[backbone][destination] = "libraries"

libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = "https://github.com/jashkenas/underscore/archive/1.6.0.zip"
libraries[underscore][directory_name] = "underscore"
libraries[underscore][destination] = "libraries"

libraries[d3][download][type] = "get"
libraries[d3][download][url] = "https://github.com/mbostock/d3/zipball/master"
libraries[d3][directory_name] = "d3"
libraries[d3][destination] = "libraries"
