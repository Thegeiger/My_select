/*
** my_move.c<2> for move in /home/geiger_a/rendu/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed Dec 17 00:02:50 2014 anthony geiger
** Last update Sat Dec 27 14:37:45 2014 anthony geiger
*/

#include "struct.h"
#include "my.h"

int	case_down(t_eta *etat)
{
  int	i;

  i = 0;
  while (etat[i].cursor != 1)
    i++;
  if (i == etat[0].argc - 2)
    {
      etat[0].cursor = 1;
      etat[i].cursor = 0;
    }
  else
    {
      etat[i].cursor = 0;
      etat[i + 1].cursor = 1;
    }
  return (0);
}

int	case_hight(t_eta *etat)
{
  int	i;

  i = 0;
  while (etat[i].cursor != 1)
    i++;
  if (i == 0)
    {
      etat[etat[0].argc - 2].cursor = 1;
      etat[i].cursor = 0;
    }
  else
    {
      etat[i].cursor = 0;
      etat[i - 1].cursor = 1;
    }
  return (0);
}

int	case_left(t_eta *etat)
{
  (void)etat;
  return (0);
}

int	case_right(t_eta *etat)
{
  (void)etat;
  return (0);
}
