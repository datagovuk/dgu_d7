core = 7.x
api = 2
projects[drupal][version] = 7.22

projects[dgu][type] = "profile"
projects[dgu][download][type] = "git"
projects[dgu][download][url] = "git@github.com:datagovuk/dgu_d7.git"
projects[drupal][patch][] = "http://raw.github.com/datagovuk/dgu_d7/master/patches/menu-undefined-offset-1108314.patch"
