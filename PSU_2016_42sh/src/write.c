/*
** write.c for write in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 11:46:37 2017 jeremy elkaim
** Last update Sun May 21 19:50:39 2017 Sridhar Vengadesan
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

int	display_prompt(char *str)
{
  int	i;
  int	o;

  o = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
        {
          o = o + 1;
        }
      i = i + 1;
    }
  i = 0;
  str3(str, i, o);
  my_putchar('>');
  return (0);
}

int	my_strlen(const char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    x++;
  return (x);
}

char	**strmalloc(char **av, int counter)
{
  int	i;

  i = 0;
  av = malloc(sizeof(char) * counter);
  while (av[i] != '\0')
    {
      av[i] = malloc(sizeof(char) * 200);
      i = i + 1;
    }
  return (av);
}
