; ----------------
; Generated makefile from http://drushmake.me
; Permanent URL: http://drushmake.me/file.php?token=2f40cca575a6
; ----------------
;
; This is a working makefile - try it! Any line starting with a `;` is a comment.
  
; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.
  
core = 7.x
  
; API version
; ------------
; Every makefile needs to declare its Drush Make API version. This version of
; drush make uses API version `2`.
  
api = 2
  
; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.
  
; Drupal 7.x. Requires the `core` property to be set to 7.x.
projects[drupal][version] = 7

  
  
; Modules
; --------
projects[ctools][version] = 1.2
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[features][version] = 1.0
projects[features][type] = "module"
projects[features][subdir] = "contrib"

projects[views][version] = 3.5
projects[views][type] = "module"
projects[views][subdir] = "contrib"

projects[link][version] = 1.0
projects[link][type] = "module"
projects[link][subdir] = "contrib"

projects[email][version] = 1.2
projects[email][type] = "module"
projects[email][subdir] = "contrib"

projects[entity][version] = 1.0-rc3
projects[entity][type] = "module"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = 1.2
projects[entityreference][type] = "module"
projects[entityreference][subdir] = "contrib"



  

; Themes
; --------
projects[] = bootstrap

  
  
; Libraries
; ---------
libraries[jquery][download][type] = "file"
libraries[jquery][download][url] = "https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"


