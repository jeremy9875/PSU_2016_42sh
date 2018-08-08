/*
** strcmp.c for strcmp in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon May 15 10:30:54 2017 jeremy elkaim
** Last update Sun May 21 23:04:05 2017 Sridhar Vengadesan
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	my_strcmp(const char *cmp, char *str)
{
  int	i;

  i = 0;
  while (cmp[i] != '\0')
    {
      if (cmp[i] != str[i])
	return (1);
      i = i + 1;
    }
  if (str[i] != '\0' && str[i] != ' ')
      return (1);
  return (0);
}

char	**strcpy_2nd(char *av, char **t)
{
  int	i;
  int	o;

  i = strlen(av);
  i = i - 5;
  o = 0;
  if ((t = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  while (o != i)
    {
      if ((t[o] = malloc(sizeof(char) * o)) == NULL)
	return (NULL);
      o = o + 1;
    }
  o = 0;
  while (av[o] != '\0' || i != o)
    {
      if (av[o] >= '0' && av[o] <= '9')
	{
	  av[o] = t[1][o];
	  o = o - 1;
	}
      else
	o = o - 1;
    }
  return (t);
}
