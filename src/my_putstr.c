/*
** my_putstr.c for my_putstr in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:33:53 2014 anthony geiger
** Last update Fri Dec 19 20:27:56 2014 anthony geiger
*/

#include <stdio.h>
#include "my.h"

void     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putstr_fd0(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar_fd0(str[i]);
      i++;
    }
}

void	my_putstr_lime(char *str, int lime)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar_fd0(str[i]);
      i++;
    }
  while (i < lime + 1)
    {
      my_putchar_fd0(' ');
      i++;
    }
}

void	my_put_space(int i)
{
  while (i != 0)
    {
      my_putchar_fd0(' ');
      i--;
    }
}
