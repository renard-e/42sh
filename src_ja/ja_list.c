/*
** ja_list.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Thu Jun  2 17:57:26 2016 Jean-Adrien Domage
** Last update Sun Jun  5 02:04:07 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "domage.h"

t_alias		*add_to_list(t_alias *idx, char *str, char *tab)
{
  t_alias	*tmp;
  t_alias	*new;

  tmp = idx;
  if ((new = malloc(sizeof(t_alias))) == NULL)
    return (verror(MALLOC_ERROR));
  if (tmp == NULL)
    {
      new->alias = str;
      new->exec_line = tab;
      new->next = NULL;
      return (new);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  new->alias = str;
  new->exec_line = tab;
  new->next = tmp;
  return (new);
}
