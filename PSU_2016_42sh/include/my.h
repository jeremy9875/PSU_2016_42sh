/*
** my.h for my in /home/jeremy.elkaim/PSU_2016_42sh/include
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 11:45:47 2017 jeremy elkaim
<<<<<<< HEAD
** Last update Sun May 21 23:05:18 2017 Sridhar Vengadesan
=======
** Last update Sun May 21 20:44:34 2017 Arnaud DEMANGE
>>>>>>> 91b7be285f8be691f256246bc303a21edb6d28ff
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_

# define EXIT		"exit"
# define CD		"cd"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define ENV		"env"
# define ECHO		"echo"

typedef enum		e_id_command
{
  EXIT_0,
  CD_1,
  SETENV_2,
  UNSETENV_3,
  ENV_4,
  ECHO_5,
}			t_id_command;

typedef struct		s_command
{
  const char		*name;
  t_id_command		id;
}			t_command;

int	my_builtins_dispatch(char *av, int count, char *prev);
int	dispatch(char *av, char *prev);
int	prompt();
int	my_echo(char *s);
char	*my_cpy_line(char *src, char *dest, int tmp);
char	*my_strcpy(char *dest, char *src);
void	str3(char *str, int i, int o);
char	*my_cpy_line(char *src, char *dest, int tmp);
char	*command_path(char *line, char *command);
int	take_flag2(char *command, int count);
char	**take_flag(char **flag, char *command, int i);
int	my_command(char *line);
void	return_previous(char *previous);
int	built_cd(char *buffer, int wstatus, char previous[255]);
void	continue_cd(char **dest, char *final, int wstatus);
char	*get_previous(char *previous);
char	*command_strcpy(char *src, char *dest, int i);
int	str_is_numb(char *str);
int	my_getnbr(char *str);
int	cpy_return_value(char *str);
int	my_exit(char *command);
int	numb_of_flag(char *command);
int	flag_len(char *command, int flag, int count);
int	my_strline(char **str);
char	**cpy_in_2d(char *str, char **tab);
char	**malloc_2dtab(char **str);
int	my_setenv(char **envb, char *av);
int	my_unsetenv(char **envb, char *av);
int	parser(char *s, char **env);
int	my_strcmp(const char *cmp, char *str);
char	**strcpy_2nd(char *av, char **t);
void	my_putchar(char c);
void	my_putstr(const char *str);
int	display_prompt(char *str);
int	my_strlen(const char *str);
char	**strmalloc(char **av, int counter);

#endif /* !MY_H_ */
