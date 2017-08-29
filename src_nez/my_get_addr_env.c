/*
** my_get_addr.c for my_get_addr_env in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue May 24 10:37:10 2016 gregoire renard
** Last update Fri Jun  3 12:00:30 2016 gregoire renard
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		my_get_addr_env(char **env, char *name)
{
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  while (env[pos.y] != NULL)
    {
      if (env[pos.y] != NULL && name[pos.x] == '\0'
	  && env[pos.y][pos.x] == '=')
	return (pos.y);
      if (env[pos.y][pos.x] != name[pos.x])
	{
	  pos.y++;
	  pos.x = 0;
	}
      else
	pos.x++;
    }
  return (-1);
}
