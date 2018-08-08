/*
** cpy_command_line.c for cpy_command_line in /home/VSridhar78/PSU/PSU_2016_42sh
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Sat May 20 23:57:35 2017 Sridhar Vengadesan
** Last update Sat May 20 23:58:24 2017 Sridhar Vengadesan
*/

#include "my.h"

char	*my_cpy_line(char *src, char *dest, int tmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (tmp == 1)
    while (src[i] == ' ' || src[i] == '\t')
      i++;
  while (src[i] != ' ' && src[i] != '\0' && src[i] != '\t')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
