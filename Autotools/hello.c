/**
 * hello.c - libhello.dll source
 *
 * Copyright (c) 2013 Hiroyuki Nagata <newserver002@gmail.com>
 * 
 *
 */

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include "hello.h"

int hello (const char* who) {
  printf("Hello %s!\n", who);
  return 0;
}

