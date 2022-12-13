/*
  This file is declared to be in the Public Domain by its author,
  Ronald S. Burkey

  Filename:     modernHAL-S-FC.c
  Purpose:      A compiler front-end for the HAL/S language.  Generally not
                for direct usage, but instead via yaHAL-S-FC.py.
  Compiler:     GNU gcc.
  Reference:    http://www.ibibio.org/apollo
  Mods:         2022-12-12 RSB  Adapted from a makefile auto-generated by
                                BNF Converter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "temp/Parser.h"
#include "temp/Printer.h"
#include "temp/Absyn.h"

void usage(void) {
  printf("usage: Call with one of the following argument combinations:\n");
  printf("\t--help\t\tDisplay this help message.\n");
  printf("\t(no arguments)	Parse stdin verbosely.\n");
  printf("\t(files)\t\tParse content of files verbosely.\n");
  printf("\t-s (files)\tSilent mode. Parse content of files silently.\n");
}

int main(int argc, char ** argv)
{
  FILE *input;
  COMPILATION parse_tree;
  int quiet = 0;
  char *filename = NULL;

  if (argc > 1) {
    if (strcmp(argv[1], "-s") == 0) {
      quiet = 1;
      if (argc > 2) {
        filename = argv[2];
      } else {
        input = stdin;
      }
    } else {
      filename = argv[1];
    }
  }

  if (filename) {
    input = fopen(filename, "r");
    if (!input) {
      usage();
      exit(1);
    }
  }
  else input = stdin;
  /* The default entry point is used. For other options see Parser.h */
  parse_tree = pCOMPILATION(input);
  if (parse_tree)
  {
    if (!quiet) {
      printf("%s\n", showCOMPILATION(parse_tree));
    }
    return 0;
  }
  return 1;
}

