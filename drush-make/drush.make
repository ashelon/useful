core = 7.x
api = 2

; defaults
defaults[projects][subdir] = "contrib"

; Drupal core
projects[] = "drupal"

; Import libraries
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_standard.zip
libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][destination] = "/modules/contrib/ckeditor"


; Contrib modules
projects[] = better_exposed_filters
projects[] = ckeditor
projects[] = context
projects[] = ctools
projects[] = date
projects[] = email
projects[] = entity
projects[] = entityreference
projects[] = features
projects[] = field_collection
projects[] = field_group
projects[] = file_entity
projects[] = imce
projects[] = insert
projects[] = libraries
projects[] = link
projects[] = menu_block
projects[] = menu_trail_by_path
projects[media][version] = 2.x-dev
projects[] = nodequeue
projects[] = options_element
projects[] = pathauto
projects[] = strongarm
projects[] = title
projects[] = token
projects[] = transliteration
projects[] = views
projects[] = views_bulk_operations

; Contrib themes