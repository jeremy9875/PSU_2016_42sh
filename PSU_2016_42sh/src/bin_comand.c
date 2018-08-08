/*
** bin_comand.c for bin_command in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon May 15 10:10:43 2017 jeremy elkaim
** Last update Sun May 21 23:06:53 2017 Sridhar Vengadesan
*/

#include "my.h"
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

char		*command_path(char *line, char *command)
{
  int		i;
  char		*tmp;
  char		*new_line;
  char		*new_command;

  i = my_strlen(line);
  if ((tmp = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  tmp = my_cpy_line (line, tmp, 1);
  i = my_strlen(tmp);
  if ((new_line = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  new_line = my_cpy_line(tmp, new_line, 0);
  i = my_strlen(new_line);
  if ((new_command = malloc(sizeof(char) * (i + 6))) == NULL)
    return (NULL);
  command = "/bin/";
  new_command = my_cpy_line(command, new_command, 0);
  new_command = command_strcpy(new_line, new_command, 5);
  free(new_line);
  return (new_command);
}

int		take_flag2(char *command, int count)
{
  while (command[count] == ' ' || command[count] == '\t')
    count++;
  while (command[count] != ' ' && command[count] != '\t')
    {
      if (command[count] == '\0')
	return (84);
      count++;
    }
  while (command[count] == ' ' || command[count] == '\t')
    count++;
  return (count);
}

char		**take_flag(char **flag, char *command, int i)
{
  int		count;
  int		tmp;

  count = 0;
  tmp = 0;
  if ((count = take_flag2(command, count)) == 84)
    return (flag);
  if ((flag[1] = malloc(sizeof(char) * 10000)) == NULL)
    return (NULL);
  while (command[count] != '\0')
    {
      flag[i][tmp] = command[count];
      count++;
      tmp++;
      if (command[count] == ' ' || command[count] == '\t')
	{
	  i++;
	  tmp = 0;
	  while (command[count] == ' ' || command[count] == '\t')
	    ++count;
	  if ((flag[i] = malloc(sizeof(char) * 10000)) == NULL)
	    return (NULL);
	}
    }
  return (flag);
}

int		free_command(char *line, char *command, char **zone)
{
  if (execve(command, zone, NULL) == -1)
    {
      if (my_strlen(command) != 5)
	{
	  my_putstr(line);
	  my_putstr(": Command not found.\n");
	}
      free(command);
      free(zone);
      free(line);
      return (84);
    }
  else
    wait(NULL);
  return (0);
}

int		my_command(char *line)
{
  char		*command;
  char		**zone;
  pid_t		child;

  child = fork();
  if (child == -1)
    return (84);
  if (child < 0)
    return (84);
  if ((command = command_path(line, command)) == NULL)
    return (84);
  if ((zone = malloc(sizeof(char *) * 1000)) == NULL)
    return (84);
  zone[0] = ".";
  zone[1] = NULL;
  if ((take_flag(zone, line, 1)) == NULL)
    return (84);
  if (child == 0)
    if ((free_command(line, command, zone)) == 84)
      return (84);
  wait(NULL);
  free(command);
  free(zone);
  kill(child, SIGKILL);
  return (0);
}
