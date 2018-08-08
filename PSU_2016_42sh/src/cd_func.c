/*
** cd_func.c for cd_func in /home/arnaud.d/PSU_2016_42sh/src
** 
** Made by Arnaud DEMANGE
** Login   <arnaud.d@epitech.net>
** 
** Started on  Wed May 17 14:18:38 2017 Arnaud DEMANGE
** Last update Sun May 21 23:31:48 2017 Sridhar Vengadesan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"

void	return_previous(char *previous)
{
  pid_t	pid;

  my_putstr(previous);
  pid = fork();
  if (pid == 0)
    {
      if (chdir(previous) == -1)
	{
	  my_putstr(": No such file or directory.\n");
	}
    }
}

int	built_cd(char *buffer, int wstatus, char previous[255])
{
  int	i;
  char	**dest;
  char	*final;
  int	a;

  a = 0;
  final = malloc(sizeof(char) * 3000);
  dest = malloc(sizeof(char) * 3000);
  i = 3;
  if (buffer[3] == '-')
    {
      buffer = previous;
      i = 0;
    }
  while (buffer[i])
    {
      final[a] = buffer[i];
      i = i + 1;
      a = a + 1;
    }
  final[a] = '\0';
  continue_cd(dest, final, wstatus);
  return(0);
}

void	continue_cd(char **dest, char *final, int wstatus)
{
  pid_t	pid;
  int	i;
  char	current_dir[255];

  i = 0;
  dest[0] = final;
  dest[1] = NULL;
  pid = fork();
  if (pid == 0)
    {
      if (chdir(dest[0]) == -1)
	{
	  while (final[i])
	    {
	      my_putchar(final[i]);
	      i++;
	    }
	  my_putstr(": No such file or directory.\n");
	}
    }
  else
    wait(&wstatus);
}

char	*get_previous(char *previous)
{
  previous = malloc(sizeof(char) * 2500);
  getcwd(previous, 255);
  return (previous);
}
