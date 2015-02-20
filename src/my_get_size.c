/*
** my_get_size.c<2> for get_size in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 22:39:01 2014 anthony geiger
** Last update Fri Dec 19 22:53:57 2014 anthony geiger
*/

#include "my.h"

int			nb_colone(int i, int colone, t_win *win, t_eta *etat)
{
  colone = 1;
  while (i != etat[0].argc - 1)
    {
      if (i > win->ws_row * colone)
	colone++;
      i++;
    }
  return (colone);
}

int			get_colone_size(int argc, char **argv)
{
  int			i;
  int			x;
  int			stock;

  x = 1;
  stock = 0;
  while (x != argc)
    {
      i = 0;
      while (argv[x][i])
	i++;
      if (i > stock)
	stock = i;
      x++;
    }
  return (stock);
}
