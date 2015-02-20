/*
** aff_fonction.c<2> for aff in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 22:09:16 2014 anthony geiger
** Last update Tue Jan  6 10:13:11 2015 anthony geiger
*/

#include "struct.h"
#include "my.h"

int			my_put_selec(t_eta *etat)
{
  int			i;

  i = 0;
  while (i != etat[0].argc - 1)
    {
      if (etat[i].select == 1)
	{
	  my_putstr(etat[i].str);
	  my_putchar(' ');
	}
      i++;
    }
  return (0);
}

void			my_aff_underscor(t_eta *etat, int i, int size_colone)
{
  my_putstr_fd0("\033[4m");
  my_putstr_fd0(etat[i - 1].str);
  my_putstr_fd0("\033[0m");
  my_put_space(size_colone - my_strlen(etat[i - 1].str) + 1);
}

void			my_aff_select(t_eta *etat, int i, int size_colone)
{
  my_putstr_fd0("\033[7m");
  my_putstr_fd0(etat[i - 1].str);
  my_putstr_fd0("\033[0m");
  my_put_space(size_colone - my_strlen(etat[i - 1].str) + 1);
}

void			my_aff_under_select(t_eta *etat, int i, int size_colone)
{
  my_putstr_fd0("\033[4;7m");
  my_putstr_fd0(etat[i - 1].str);
  my_putstr_fd0("\033[0m");
  my_put_space(size_colone - my_strlen(etat[i - 1].str) + 1);
}

int			my_aff_fonc(int i, int colone, t_eta *etat, int size_colone)
{
  int			nb;

  nb = 0;
  while (nb < colone && i < etat[0].argc)
    {
      if (etat[i - 1].suppr_boole == 1)
      	{
      	  i++;
      	  nb++;
      	  continue;
      	}
      else if (etat[i - 1].cursor == 0 && etat[i - 1].select == 1)
	my_aff_select(etat, i, size_colone);
      else if (etat[i - 1].cursor == 1 && etat[i - 1].select == 1)
	my_aff_under_select(etat, i, size_colone);
      else if (etat[i - 1].cursor == 1 && etat[i - 1].select == 0)
	my_aff_underscor(etat, i, size_colone);
      else
	my_putstr_lime(etat[i - 1].str, size_colone);
      i++;
      nb++;
    }
  return (i);
}
