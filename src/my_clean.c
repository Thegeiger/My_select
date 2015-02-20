/*
** my_clean.c<2> for my_clean in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 22:55:39 2014 anthony geiger
** Last update Fri Dec 19 23:11:35 2014 anthony geiger
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int			my_put_rest(struct termios *term)
{
  term->c_lflag |= ECHO;
  term->c_lflag |= ICANON;
  if (my_actualisation(term) == - 1)
    return (- 1);
  tputs(tgetstr("ve", NULL), 1, my_putc);
  return (0);
}

int			my_final_clear()
{
  t_win			win;

  if (ioctl(0, TIOCGWINSZ, &win) == - 1)
    return (- 1);
  my_clean(&win);
  tputs(tgetstr("ve", NULL), 1, my_putc);
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
  return (0);
}

void			my_clean(t_win *win)
{
  int	x;
  int	y;

  tputs(tgetstr("vi", NULL), 1, my_putc);
  x = 0;
  while (x != win->ws_col)
    {
      y = 0;
      while (y != win->ws_row)
	{
	  my_putchar_fd0(' ');
	  y++;
	}
      x++;
    }
}
