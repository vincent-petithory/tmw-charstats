## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src po

tmw_charstatsdocdir = ${prefix}/doc/tmw_charstats
tmw_charstatsdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(tmw_charstatsdoc_DATA) \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(tmw_charstatsdocdir)
