/*
** my_putchar.c for my_putchar in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:21:31 2014 anthony geiger
** Last update Fri Dec 19 14:46:55 2014 anthony geiger
*/

#include <unistd.h>
#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_fd0(char c)
{
  write(0, &c, 1);
}

int	my_putc(int c)
{
  int   ret;

  ret = write(0, &c, 1);
  return (ret);
}
