/*
** my_goto.c<2> for my_goto in /home/geiger_a/PSU_2014_my_select
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Fri Dec 19 23:13:48 2014 anthony geiger
** Last update Wed Jan  7 13:48:56 2015 Anthony Geiger
*/

#include <stdlib.h>
#include <termcap.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "struct.h"
#include "my.h"

void			my_err_size(int i, int colone, t_win *win, int size_line)
{
  if (i / colone >= win->ws_row || colone * size_line >= win->ws_col)
    {
      my_clean(win);
      tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
      my_putstr_fd0("Please resize the window\n");
    }
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
}

void			my_alignement(int i, int colone)
{
  if (i == 2)
    tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, my_putc);
  else
    tputs(tgoto(tgetstr("cm", NULL), 0, i / colone - 1), 1, my_putc);
}
