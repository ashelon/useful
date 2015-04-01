ROOT := htdocs
DRUSHMAKE := drush.make
DEVMAKE := drush.dev.make
DRUSH := drush

DEVMODULES = devel \
 	diff \
	module_filter \
	field_ui \
	views_ui \
	migrate \
	migrate_ui \
	context_ui

build: clean chmod drushmake patch finish

clean:
	-rm -r $(ROOT)/sites/all
	-rm -r $(ROOT)/includes
	-rm -r $(ROOT)/misc
	-rm -r $(ROOT)/modules
	-rm -r $(ROOT)/scripts
	-rm -r $(ROOT)/themes
	-rm -r $(ROOT)/profiles/minimal
	-rm -r $(ROOT)/profiles/standard
	-rm -r $(ROOT)/profiles/testing
	-rm -r $(ROOT)/vendor
	-rm -f $(ROOT)/web.config
	-rm -r $(ROOT)/.htaccess
	-rm -r $(ROOT)/.gitignore
	-rm $(ROOT)/*.php
	-rm $(ROOT)/*.txt

chmod:
	chmod a+w $(ROOT)/sites/default

drushmake:
	cd $(ROOT) && $(DRUSH) make --no-gitinfofile ../$(DRUSHMAKE) .

patch:
	@echo "No patches for now."
	# patch -p1 < patches/nothing.patch

finish:
	# Remove some files we don't want to keep.
	-rm -r $(ROOT)/INSTALL*.txt
	-rm -r $(ROOT)/CHANGELOG.txt
	-rm -r $(ROOT)/COPYRIGHT.txt
	-rm -r $(ROOT)/MAINTAINERS.txt
	-rm -r $(ROOT)/LICENSE.txt
	-rm -r $(ROOT)/README.txt
	-rm -r $(ROOT)/UPGRADE.txt
	-rm -r $(ROOT)/update.php
	-rm -r $(ROOT)/install.php
	-rm -r $(ROOT)/xmlrpc.php
	@echo 'Finished.'

dev: devmake devenable

devmake:
	cd $(ROOT) && $(DRUSH) make --no-core --no-gitinfofile ../$(DEVMAKE) .

# Enable development environment for this Drupal installation
devenable:
	# enable our default development modules
	cd $(ROOT) && $(DRUSH) -y en $(DEVMODULES)
	# set username and password of user 1 to 'admin'
	cd $(ROOT) && drush sqlq "update users set name='admin' where uid=1;"
	cd $(ROOT) && drush upwd admin --password=admin
	# run Makefile.custom if it exists to give to developer the opportunity
	# to further customize the development environment
	@if [ -f Makefile.custom ]; \
	then \
		$(MAKE) ROOT=$(ROOT) DRUSH=$(DRUSH) -f Makefile.custom devenable; \
	fi;

devinstall: install dev

install:
	cd $(ROOT) && $(DRUSH) -y si anbwebsite
	$(MAKE) zipcodes
	cd $(ROOT) && $(DRUSH) -y dis update
