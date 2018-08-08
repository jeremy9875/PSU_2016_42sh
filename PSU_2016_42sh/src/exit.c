/*
** exit.c for exit in /home/VSridhar78/PSU/PSU_2016_42sh
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Thu May 18 11:30:22 2017 Sridhar Vengadesan
** Last update Sat May 20 16:54:25 2017 jeremy elkaim
*/

#include <stdlib.h>
#include "my.h"

int	str_is_numb(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    ++i;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  if (str[i] == '-')
    ++i;
  while (str[i] != '\0')
    {
      if (str[i] > '9' || str[i] < '0')
	return (1);
      ++i;
    }
  return (0);
}

int	cpy_return_value(char *str)
{
  int	i;
  int	tmp;
  char	*str_value;

  i = 0;
  tmp = 0;
  str_value = NULL;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    ++i;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  if ((str_value = malloc(sizeof(char) * (my_strlen(str) - i))) == NULL)
    return (0);
  while (str[i] != '\0')
    {
      str_value[tmp] = str[i];
      ++i;
      ++tmp;
    }
  if (str_value == NULL)
    return (0);
  str_value[i] = '\0';
  tmp = atoi(str_value);
  return (tmp);
}

int	my_exit(char *command)
{
  int	return_value;

  if (str_is_numb(command) == 1)
    return (84);
  return_value = cpy_return_value(command);
  exit (return_value);
}
