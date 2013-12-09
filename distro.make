core = 7.x
api = 2
projects[drupal][type] = "core"
projects[drupal][download][type] = "git"
projects[drupal][download][url] = "http://git.drupal.org/project/drupal.git"
projects[drupal][download][tag] = "7.24"
projects[drupal][patch][] = "http://raw.github.com/datagovuk/dgu_d7/master/patches/menu-undefined-offset-1108314.patch"

projects[dgu][type] = "profile"
projects[dgu][download][type] = "git"
projects[dgu][download][url] = "git@github.com:datagovuk/dgu_d7.git"
projects[dgu][download][branch] = "redesign"
