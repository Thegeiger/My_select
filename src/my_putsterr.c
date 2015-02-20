/*
** my_putsterr.c<2> for err in /home/geiger_a/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Dec 19 20:27:08 2014 anthony geiger
** Last update Fri Dec 19 22:32:06 2014 anthony geiger
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void	my_puterr(char c)
{
  write(2, &c, 1);
}

void	my_putsterr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_puterr(str[i]);
      i++;
    }
}
