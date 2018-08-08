/*
** my_strcpy_tab.c for my_strcpy_tab in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue May 16 10:35:36 2017 jeremy elkaim
** Last update Sat May 20 16:55:42 2017 jeremy elkaim
*/

#include "my.h"

int	my_strline(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    ++i;
  return (i);
}

char	**cpy_in_2d(char *str, char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != NULL)
    {
      while (str[i][j] != '\0')
        {
	  tab[i][j] = str[i][j];
	  ++j;
        }
      tab[i][j] = str[i][j];
      j = 0;
      ++i;
    }
  return (tab);
}

char	**malloc_2dtab(char **str)
{
  char	**tab;
  int	tmp;

  tmp = 0;
  if ((tab = malloc(sizeof(char *) * my_strline(str))) == NULL)
    return (NULL);
  while (tmp != (my_strline(str)))
    {
      if ((tab[tmp] = malloc(sizeof(char) * (strlen(str[tmp]) + 1)))
          == NULL)
	return (NULL);
      ++tmp;
    }
  tab = cpy_in_2d(str, tab);
  return (tab);
}
