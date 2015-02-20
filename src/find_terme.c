/*
** find_therme.c<2> for find therù in /home/geiger_a/rendu/PSU_2014_my_select/src
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Thu Jan  8 11:02:42 2015 Anthony Geiger
** Last update Thu Jan  8 11:49:05 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

char	*find_term(char **env)
{
  int	i;

  i = 0;
  while (env[i] != '\0' && my_strncmp(env[i], "TERM", 4) == 1)
    {
      i++;
    }
  if (env[i] == '\0')
    {
      my_putstr("I can't find the TERM\n");
      exit (1);
    }
  return (my_strnsdup(env[i], 5));
}
