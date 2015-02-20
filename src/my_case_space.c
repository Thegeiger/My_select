/*
** select.c for select in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Thu Dec 18 14:48:39 2014 anthony geiger
** Last update Fri Dec 19 14:21:08 2014 anthony geiger
*/

#include "struct.h"
#include "my.h"

int	case_space(t_eta *etat)
{
  int	i;

  i = 0;
  while (etat[i].cursor != 1)
    i++;
  if (i == etat[0].argc - 1)
    return (0);
  else if (etat[i].select == 1)
    etat[i].select = 0;
  else
    {
      etat[i].select = 1;
      etat[i].cursor = 0;
      if (i + 1 == etat[0].argc - 1)
	{
	  etat[0].cursor = 1;
	}
      else
	etat[i + 1].cursor = 1;
    }
  return (0);
}
