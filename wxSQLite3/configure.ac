
#-----------------------------------------------------------------------
# Supports the following non-standard switches.
#
#   --enable-threadsafe
#   --enable-readline
#   --enable-dynamic-extensions
#

AC_PREREQ(2.68)
AC_INIT(janeclone, 1.0.0, newserver002@gmail.com)
AC_CANONICAL_TARGET
AC_CONFIG_SRCDIR([sqlite3/sqlite3.c])
AC_CONFIG_MACRO_DIR([m4])

# Use automake.
AM_INIT_AUTOMAKE([foreign])
AC_SYS_LARGEFILE

# Check for required programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_MAKE_SET
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AC_PROG_MKDIR_P

# Checks for HostOS
case "$host" in
        *-*-mingw*|*-*-cygwin*)
                AC_DEFINE(PLATFORM_WIN32, 1, [Platform is Win32])
                PLATFORM_STRING="Win32"
		AC_SUBST(PLATFORM_STRING)
                ;;
        *-*-linux*)
                AC_DEFINE(PLATFORM_LINUX, 1, [Platform is Linux])
                PLATFORM_STRING="Linux"
		AC_SUBST(PLATFORM_STRING)
                ;;
        *-*-darwin*)
                AC_DEFINE(PLATFORM_APPLE, 1, [Platform is Apple])
                PLATFORM_STRING="Apple"
		AC_SUBST(PLATFORM_STRING)
                ;;
        *)
                AC_MSG_WARN([*** Please add $host to configure.ac checks!])
                ;;
esac

# Check for windres
if test "$PLATFORM_STRING" = "Win32"; then
   AC_CHECK_TARGET_TOOL([WINDRES], [windres], [no])
   if test "x$WINDRES" = "xno"; then
      AC_MSG_ERROR([Cannot find windres])
   fi
   AC_SUBST(WINDRES)
   AM_CONDITIONAL(USE_WINDRES, true)
else
# Set false use_windres
AM_CONDITIONAL(USE_WINDRES, false)
fi

# Checks for wxWidgets.
AM_OPTIONS_WXCONFIG
reqwx=2.8.0
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.
 
		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi

# Check for library functions that SQLite can optionally use.
AC_CHECK_FUNCS([fdatasync usleep fullfsync localtime_r gmtime_r])
AC_FUNC_STRERROR_R

AC_CONFIG_FILES([sqlite3/Makefile
	         wxsqlite3/Makefile
		 Makefile])
AC_SUBST(BUILD_CFLAGS)

#-----------------------------------------------------------------------
#   --enable-readline
#
AC_ARG_ENABLE(readline, [AS_HELP_STRING(
  [--enable-readline], 
  [use readline in shell tool (yes, no) [default=yes]])], 
  [], [enable_readline=yes])
if test x"$enable_readline" != xno ; then
  sLIBS=$LIBS
  LIBS=""
  AC_SEARCH_LIBS(tgetent, curses ncurses ncursesw, [], [])
  AC_SEARCH_LIBS(readline, readline, [], [enable_readline=no])
  AC_CHECK_FUNCS(readline, [], [])
  READLINE_LIBS=$LIBS
  LIBS=$sLIBS
fi
AC_SUBST(READLINE_LIBS)
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
#   --enable-threadsafe
#
AC_ARG_ENABLE(threadsafe, [AS_HELP_STRING(
  [--enable-threadsafe], [build a thread-safe library [default=yes]])], 
  [], [enable_threadsafe=yes])
THREADSAFE_FLAGS=-DSQLITE_THREADSAFE=0
if test x"$enable_threadsafe" != "xno"; then
  THREADSAFE_FLAGS="-D_REENTRANT=1 -DSQLITE_THREADSAFE=1"
  AC_SEARCH_LIBS(pthread_create, pthread)
fi
AC_SUBST(THREADSAFE_FLAGS)
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
#   --enable-dynamic-extensions
#
AC_ARG_ENABLE(dynamic-extensions, [AS_HELP_STRING(
  [--enable-dynamic-extensions], [support loadable extensions [default=yes]])], 
  [], [enable_dynamic_extensions=yes])
if test x"$enable_dynamic_extensions" != "xno"; then
  AC_SEARCH_LIBS(dlopen, dl)
else
  DYNAMIC_EXTENSION_FLAGS=-DSQLITE_OMIT_LOAD_EXTENSION=1
fi
AC_MSG_CHECKING([for whether to support dynamic extensions])
AC_MSG_RESULT($enable_dynamic_extensions)
AC_SUBST(DYNAMIC_EXTENSION_FLAGS)
#-----------------------------------------------------------------------

AC_CHECK_FUNCS(posix_fallocate)

#-----------------------------------------------------------------------
# UPDATE: Maybe it's better if users just set CFLAGS before invoking
# configure. This option doesn't really add much...
#
#   --enable-tempstore
#
# AC_ARG_ENABLE(tempstore, [AS_HELP_STRING(
#   [--enable-tempstore], 
#   [in-memory temporary tables (never, no, yes, always) [default=no]])], 
#   [], [enable_tempstore=no])
# AC_MSG_CHECKING([for whether or not to store temp tables in-memory])
# case "$enable_tempstore" in
#   never )  TEMP_STORE=0 ;;
#   no )     TEMP_STORE=1 ;;
#   always ) TEMP_STORE=3 ;;
#   yes )    TEMP_STORE=3 ;;
#   * )
#     TEMP_STORE=1
#     enable_tempstore=yes
#   ;;
# esac
# AC_MSG_RESULT($enable_tempstore)
# AC_SUBST(TEMP_STORE)
#-----------------------------------------------------------------------

# Checks for zlib
AC_CHECK_LIB(z,gzopen,has_zlib=1,has_zlib=0)
if test $has_zlib = 0; then
  AC_MSG_ERROR("ERROR: cannot find zlib.")
fi
# Checks for pthread
AC_CHECK_LIB(pthread,pthread_create,has_pthread=1,has_pthread=0)
if test $has_pthread = 0; then
  AC_MSG_ERROR("ERROR: cannot find pthread.")
fi

# Add Flags
CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LIBS="$LIBS $WX_LIBS"

AC_OUTPUT
