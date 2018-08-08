/*
** tab.c for tab in /home/jeremy.elkaim/PSU_2016_42sh/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue May 16 09:19:21 2017 jeremy elkaim
** Last update Sat May 20 16:52:52 2017 jeremy elkaim
*/

#include <ncurses.h>

int	tab(int ch, char *av)
{
  if (ch == '\t')
    {
      possibility(av);
    }
  else
    return (1);
  return (0);
}
