/*
** main.c for main in /home/geiger_a/PSU_2014_my_select/src
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 10:06:43 2015 anthony geiger
** Last update Wed Jan  7 13:48:44 2015 Anthony Geiger
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <term.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "struct.h"
#include "my.h"

int                     main(int argc, char **argv)
{
  struct termios        term;
  int			size_colone;

  if (argc <= 2)
    {
      my_putsterr("No argument or to few arguments.\n");
      return (1);
    }
  if (tcgetattr(0, &term) == - 1)
    {
      my_putsterr("Tcgetattr error.\n");
      return (1);
    }
  size_colone = get_colone_size(argc, argv);
  signal(SIGINT, nothing);
  if (my_gere_select(argc, argv, size_colone, &term) == - 1)
    return (- 1);
  my_final_clear();
  return (0);
}
