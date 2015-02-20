/*
** my_strlen.c<2> for strlen in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 22:27:46 2014 anthony geiger
** Last update Fri Dec 19 22:28:44 2014 anthony geiger
*/

#include "my.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
