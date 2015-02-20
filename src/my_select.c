/*
** bsq.c for bsq in /home/geiger_a/rendu/tmp
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Sun Dec 14 19:52:06 2014 anthony geiger
** Last update Thu Jan  8 11:59:25 2015 anthony geiger
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include "struct.h"
#include "my.h"

extern char	**environ;

int	my_actualisation(struct termios *term)
{
  if (tcsetattr(0, TCSANOW, term) == - 1)
    {
      my_putsterr("Tcsetattr error.\n");
      return (- 1);
    }
  return (0);
}

int		my_select(struct termios *term, t_eta *etat, int size_colone)
{
  static t_win	win;
  t_win		save;

  save = win;
  term->c_lflag &= ~ECHO;
  term->c_lflag &= ~ICANON;
  term->c_cc[VMIN] = 0;
  term->c_cc[VTIME] = 10;
  if (my_actualisation(term) == - 1)
    return (- 1);
  if (tgetent(NULL, find_term(environ)) == - 1)
    return (- 1);
  if (ioctl(0, TIOCGWINSZ, &win) == - 1)
    return (- 1);
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
  if (save.ws_row != win.ws_row || save.ws_col != win.ws_col)
    my_clean(&win);
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
  tputs(tgetstr("vi", NULL), 1, my_putc);
  my_show_tab(etat, &win, size_colone);
  return (0);
}

int			my_gere_key(struct termios *term, t_eta *etat)
{
  unsigned long		buffer;
  int			boole;

  boole = 0;
  buffer = 0;
  if (read(0, &buffer, 8) == - 1)
    return (- 1);
  if (buffer == HIGHT || buffer == DOWN || buffer == LEFT
      || buffer == RIGHT || buffer == SPACE || buffer == SUPPR_KEY)
    {
      if (my_ptr_tab(buffer, etat) == - 1)
	return (- 1);
    }
  else if (buffer == ESC)
    {
      if (my_put_rest(term) == -1)
	return (- 1);
      boole = 1;
    }
  return (boole);
}

int			my_gere_select(int argc, char **argv,
				       int size_colone, struct termios *term)
{
  int			boole;
  t_eta			*etat;

  boole = 0;
  if ((etat = malloc(sizeof(t_eta) * argc)) == NULL)
    {
      my_putstr("malloc failed\n");
      return (- 1);
    }
  my_init_tab(etat, argc, argv);
  while (boole == 0)
    {
      if (my_select(term, etat, size_colone) == - 1)
	return (- 1);
      if ((boole = my_gere_key(term, etat)) == - 1)
	return (- 1);
    }
  my_put_selec(etat);
  return (0);
}
