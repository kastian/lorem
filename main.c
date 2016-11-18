/*
  lorem - simple text filler generator.

  Copyright 2016 Konstantin Shakhnov.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  TODO:
  - output to file (-o)
  - max line widht (-w)
  - add frases to check font (The quick brown fox jumps over the lazy dog, etc)
  - not one lorem but all from the list
  ? read from file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define PROGRAM "lorem"
#define VERSION "0.1"
#define URL     "https://github.com/kastian/lorem"
#define MAIL    "kastian@mail.ru"
#define YEAR	"2016"
#define AUTHOR	"Konstantin Shakhnov"

char *lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut \
enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut \
aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit \
in voluptate velit esse cillum dolore eu fugiat nulla \
pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa \
qui officia deserunt mollit anim id est laborum.";

void
print_usage (FILE * stream, int exit_code)
{
  fprintf (stream, "%s - simple text filler generator.\n", PROGRAM);
  fprintf (stream, "Usage: %s [options]\n", PROGRAM);
  fprintf (stream,
	   "  -p  --paragraph       print each lorem at separate line\n"
	   "  -s  --string=STRING   use STRING as lorem\n"
	   "  -t  --times=N         repeat lorem N times\n"
	   /* "  -w, --width=WIDTH     maximum line width\n" */
	   /* "  -o  --output=FILENAME write output to file.\n" */
	   "  -h  --help            display this help and exit\n"
	   "  -v  --version         output version information and exit\n");
  fprintf (stream, "Report bugs to: %s\n", MAIL);
  fprintf (stream, "%s home page: <%s>\n", PROGRAM, URL);
  exit (exit_code);
}

void
print_version (FILE * stream, int exit_code)
{
  fprintf (stream, "%s %s\n", PROGRAM, VERSION);
  fprintf (stream, "Copyright (C) %s %s.\n", YEAR, AUTHOR);
  fprintf (stream,
	   "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n");
  fprintf (stream,
	   "This is free software: you are free to change and redistribute it.\n");
  fprintf (stream, "There is NO WARRANTY, to the extent permitted by law.\n");
  exit (exit_code);
}

int
main (int argc, char *argv[])
{
  int paragraph = 0;
  int times = 1;
  char *current;

  /* abcdefghijklmnopqrstuvwxyz */
  char *short_options = "hps:t:v";
  struct option long_options[] = {
    {"paragraph", 0, NULL, 'p'},
    {"string", 1, NULL, 's'},
    {"times", 1, NULL, 't'},
    {"help", 0, NULL, 'h'},
    {"version", 0, NULL, 'v'},
    {0, 0, 0, 0},
  };
  int next_option;
  do
    {
      next_option = getopt_long (argc, argv, short_options,
				 long_options, NULL);
      switch (next_option)
	{
	case 'h':
	  print_usage (stdout, 0);
	case 'p':
	  paragraph = 1;
	  break;
	case 's':
	  lorem = optarg;
	  break;
	case 't':
	  times = atoi (optarg);
	  break;
	case 'v':
	  print_version (stdout, 0);
	  break;
	case '?':
	  print_usage (stderr, 1);
	  break;
	case -1:
	  break;
	default:
	  abort ();
	}
    }
  while (next_option != -1);

  while (times)
    {
      for (current = lorem; *current != '\0'; current++)
	{
	  putchar (*current);
	}
      (paragraph) ? putchar ('\n') : putchar (' ');
      times--;
    }
  return 0;
}
