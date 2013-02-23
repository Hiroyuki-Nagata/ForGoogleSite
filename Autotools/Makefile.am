lib_LTLIBRARIES		= libhello.la
libhello_la_SOURCES	= hello.c
libhello_la_LDFLAGS	= -no-undefined -version-info 0:0:0 -Wl,--enable-auto-import -Wl,--export-all-symbols

include_HEADERS		= hello.h

bin_PROGRAMS		= hello
hello_SOURCES		= main.c
hello_LDADD		= libhello.la

ACLOCAL_AMFLAGS		= -I m4