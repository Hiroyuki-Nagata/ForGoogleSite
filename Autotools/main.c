/**
 * main.c - main source
 *
 * Copyright (c) 2013 Hiroyuki Nagata <newserver002@gmail.com>
 * 
 *
 */

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include "hello.h"

int main (int argc, const char* argv[]) {
  return hello("World!!");
}
