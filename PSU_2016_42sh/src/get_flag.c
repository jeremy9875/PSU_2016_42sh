/*
** get_flag.c for get_flag in /home/VSridhar78/PSU/PSU_2016_42sh
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Wed May 17 10:58:20 2017 Sridhar Vengadesan
** Last update Sat May 20 16:55:04 2017 jeremy elkaim
*/

#include "my.h"

int	numb_of_flag(char *command)
{
  int	count;
  int	tmp;

  count = 0;
  tmp = 0;
  while (command[count] != '\0')
    {
      if (command[count] != ' ' && command[count] != '\t')
	{
	  while (command[count] != ' ' && command[count] != '\t' &&
		 command[count] != '\0')
	    ++count;
	  ++tmp;
	}
      ++count;
    }
  return (tmp);
}

int	flag_len(char *command, int flag, int count)
{
  int	tmp;
  int	len;

  tmp = 0;
  len = 0;
  while (tmp < flag)
    {
      while (command[count] == ' ' || command[count] == '\t')
	++count;
      ++tmp;
      if (tmp != flag)
	while (command[count] != ' ' && command[count] != '\t' &&
	       command[count] != '\0')
	  ++count;
    }
  while (command[count] != ' ' && command[count] != '\t' &&
	 command[count] != '\0')
    {
      ++count;
      ++len;
    }
  return (len);
}
