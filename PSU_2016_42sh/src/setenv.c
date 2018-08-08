/*
** setenv.c for setenv in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue May 16 09:45:56 2017 jeremy elkaim
** Last update Thu May 18 09:32:24 2017 jeremy elkaim
*/

#include "my.h"
#include <stdlib.h>

int	my_setenv(char **envb, char *av)
{
  char	**env;
  int	i;
  int	index;
  int	u;

  u = 0;
  malloc_2dtab(env);
  while (env[i] != NULL)
    {
      if (strcmp(av, env[i]) == 0)
	  return (84);
      else if (env[i + 1][0] == '\0')
	{
	  env[i][index] == av[u];
	  index = index + 1;
	  u = u + 1;
	}
      else if (env[i][index] == '\0')
	{
	  i = i + 1;
	  index = 0;
	}
      else
	index = index + 1;
    }
  return (0);
}

int	my_unsetenv(char **envb, char *av)
{
  char	**env;
  int	i;
  int	index;

  malloc_2dtab(env);
  while (env[i] != NULL)
    {
      if (strcmp(av, env[i]) == 0)
	{
	  env[i] = '\0';
	}
      else if (env[i][index] == '\0')
	{
	  i = i + 1;
	  index = 0;
	}
      else
	index = index + 1;
    }
  return (0);
}

int	parser(char *s, char **env)
{
  int	count;

  count = 0;
  while (s[count] != '\0')
    {
      if (s[count] == '|' || s[count] == '&' || s[count] == ';')
        return (1);
      ++count;
    }
  if (dispatch(s, env) == 84)
    return (84);
  return (0);
}
