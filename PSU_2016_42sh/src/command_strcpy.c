/*
** command_strcpy.c for command_strcpy in /home/VSridhar78/PSU/PSU_2016_42sh
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Tue May 16 13:27:45 2017 Sridhar Vengadesan
** Last update Thu May 18 09:24:55 2017 jeremy elkaim
*/

#include "my.h"

char	*command_strcpy(char *src, char *dest, int i)
{
  int	j;

  j = 0;
  while (src[j] != '\0')
    {
      my_putchar(dest[i]);
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  return (dest);
}
