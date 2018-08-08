/*
** promptsave.c for promptsave in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue May 16 09:20:34 2017 jeremy elkaim
** Last update Tue May 16 13:57:05 2017 jeremy elkaim
*/

#include <ncurses.h>

int	promptsave(int ch, char *av)
{
  if (ch == KEY_UP)
    {
      prompt(-1);
    }
  else if (ch == KEY_DOWN)
    {
      prompt(+1);
    }
  else if (ch == KEY_LEFT)
    {
      movecurse(+1);
    }
  else if (ch == KEY_RIGHT)
    {
      movecurse(-1);
    }
  return (0);
}
