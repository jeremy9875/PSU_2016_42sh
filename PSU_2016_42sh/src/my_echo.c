/*
** my_echo.c for my_echo in /home/VSridhar78/PSU/PSU_2016_42sh
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Sun May 21 10:45:53 2017 Sridhar Vengadesan
** Last update Sun May 21 15:22:23 2017 Sridhar Vengadesan
*/

#include "my.h"

int	my_echo(char *s)
{
  int	i;

  i = 4;
  while (s[i] != '\0')
    {
      if (s[i] != ' ' && s[i] != '\t')
	{
	  while (s[i] != '\0')
	    {
	      my_putchar(s[i]);
	      ++i;
	    }
	  my_putchar('\n');
	  return (0);
	}
      ++i;
    }
  my_putchar('\n');
  return (0);
}
