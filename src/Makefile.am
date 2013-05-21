CFLAGS_LANGUAGE=-std=c99 -pedantic -D_POSIX_C_SOURCE \
		-D_SVID_SOURCE
CFLAGS_WARNS=-Wall -Wextra -Werror
CFLAGS_INCLUDES=-Iinclude

AM_CFLAGS=	-ggdb -fPIC -O2 $(CFLAGS_LANGUAGE) \
		$(CFLAGS_WARNS) \
		$(CFLAGS_INCLUDES)

lib_LTLIBRARIES=libunstable.la

libunstable_la_SOURCES =  unstable.c

libunstable_la_LDFLAGS = -version-info 1:0:0

library_includedir=$(includedir)/unstable
library_include_HEADERS	= include/unstable/unstable.h
