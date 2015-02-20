/*
** tab_fonction.c<2> for tab in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 23:01:53 2014 anthony geiger
** Last update Fri Dec 19 23:03:28 2014 anthony geiger
*/

#include "my.h"
#include "struct.h"

void			my_init_tab(t_eta *etat, int argc, char **argv)
{
  int			i;

  i = 0;
  while (i < argc - 1)
    {
      etat[i].argc = argc;
      if (i == 0)
	etat[i].cursor = 1;
      else
	etat[i].cursor = 0;
      etat[i].select = 0;
      etat[i].suppr_boole = 0;
      etat[i].str = argv[i + 1];
      i++;
    }
}

int			my_ptr_tab(unsigned long buffer, t_eta *etat)
{
  static const t_key	tab_ptr[] =
    {
      {LEFT, &case_left},
      {HIGHT, &case_hight},
      {RIGHT, &case_right},
      {DOWN, &case_down},
      {SPACE, &case_space},
      {SUPPR_KEY, &case_suppr}
    };
  int			i;

  i = 0;
  while (buffer != tab_ptr[i].key)
    i++;
  if (tab_ptr[i].ptr_tab(etat) == - 1)
    return (- 1);
  return (0);
}

void			my_show_tab(t_eta *etat, t_win *win, int size_colone)
{
  unsigned short 	i;
  int			colone;

  i = 1;
  colone = 1;
  colone = nb_colone(i, colone, win, etat);
  while (i < etat[0].argc)
    {
      i = my_aff_fonc(i, colone, etat, size_colone);
      my_alignement(i, colone);
    }
  my_err_size(i, colone, win, size_colone);
}
