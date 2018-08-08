/*
** 42sh2.c for 42sh2 in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 15:28:59 2017 jeremy elkaim
** Last update Fri May 19 18:59:50 2017 jeremy elkaim
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      my_putchar(src[i]);
      i = i + 1;
    }
  dest[i] = src[i];
  return (dest);
}

void	str3(char *str, int i, int o)
{
  int	p;

  p = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
        {
          p = p + 1;
        }
      if (p == o || p == o - 1)
        {
          my_putchar(str[i+1]);
        }
      i = i + 1;
    }
}
