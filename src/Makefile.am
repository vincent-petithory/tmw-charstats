## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/tmw_charstats/ui
ui_DATA = tmw_charstats.ui \
	games-tmw_small.svg

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(TMW_CHARSTATS_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = \
	tmw-charstats

EXTRA_DIST = $(ui_DATA) \
	$(tmw-charstatsdoc_DATA)\
	$(tmw-charstatsdoc_DATA)

tmw_charstats_SOURCES = \
	character.cc   \
	character.h   \
	main.cc

tmw-charstatsdoc_DATA = 

tmw-charstatsdocdir = \
	$(pkgdatadir)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/tmw_charstats
