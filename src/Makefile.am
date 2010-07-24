## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/tmw_charstats/ui
ui_DATA = tmw_charstats.ui

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(TMW_CHARSTATS_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = tmw_charstats

tmw_charstats_SOURCES = \
	main.cc        \
	character.cc        \
	character.h

tmw_charstats_LDFLAGS = 

tmw_charstats_LDADD = $(TMW_CHARSTATS_LIBS)

EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/tmw_charstats
