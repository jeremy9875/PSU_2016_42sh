/*
** 42sh.c for 42sh in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 15:29:14 2017 jeremy elkaim
** Last update Sun May 21 23:32:40 2017 Sridhar Vengadesan
*/

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"

static	t_command g_command[] =
{
  {EXIT, EXIT_0},
  {CD, CD_1},
  {SETENV, SETENV_2},
  {UNSETENV, UNSETENV_3},
  {ENV, ENV_4},
  {ECHO, ECHO_5}
};

int	my_builtins_dispatch(char *av, int count, char *prev)
{
  int	wstatus;
  char	buffer[1000];

  if (count == 1)
    {
      if (built_cd(av, wstatus, prev) == 0)
	{
	  my_putstr("Directory: ");
	  my_putstr(getcwd(buffer, 1000));
	  my_putstr("\n");
	}
    }
  if (count == 0)
    {
      my_putstr("exit\n");
      my_exit(av);
    }
  if (count == 5)
    my_echo(av);
  return (0);
}

int	dispatch(char *av, char *prev)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (av[i] != '\0')
    {
      if (av[i] == '|' || av[i] == '&' || av[i] == ';' || av[i] == '<' ||
	  av[i] == '>')
	return (0);
      ++i;
    }
  while (count < (sizeof(g_command) / sizeof(t_command)))
    {
      if (my_strcmp(g_command[count].name, av) == 0)
	return (my_builtins_dispatch(av, count, prev));
      else
	++count;
      if (count >= (sizeof(g_command) / sizeof(t_command)))
	return (my_command(av));
    }
  return (0);
}

void	show_prompt()
{
  my_putstr("\n$>");
}

int	main()
{
  char	*s;
  char	*prev;

  signal(SIGINT, show_prompt);
  my_putstr("$>");
  while (1)
    {
      if (prev == NULL)
	prev = getcwd(prev, 255);
      if ((s = get_next_line(0)) == NULL)
	{
	  my_putstr("exit\n");
	  return (0);
	}
      if (dispatch(s, prev) == 84)
	return (84);
      my_putstr("$>");
      free(s);
    }
  return (0);
}
