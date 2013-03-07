# -- Top-level Makefile.am --
# Subdirectories to descend into.
SUBDIRS		= sqlite3 wxsqlite3

bin_PROGRAMS	= minimal
minimal_SOURCES = Main.cpp HelloWorld.cpp
minimal_CXXFLAGS= -I$(top_builddir)/sqlite3 -I$(top_builddir)/wxsqlite3
minimal_LDADD	= $(top_builddir)/sqlite3/libsqlite3.la $(top_builddir)/wxsqlite3/libwxsqlite3.la