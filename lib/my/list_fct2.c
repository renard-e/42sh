/*
** list_fct2.c for list_fct2 in /home/renard_e/poubelle_test/CPE_2015_Lemin/src_nez
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Wed Apr 20 15:28:13 2016 gregoire renard
** Last update Mon Apr 25 08:58:23 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

t_list		*create_list(void)
{
  t_list	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->next = root;
  root->prev = root;
  return (root);
}

int		new_front_add(t_list *elem, char *line)
{
  t_list	*new_elem;

  (void)line;
  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (-1);
  new_elem->prev = elem->prev;
  new_elem->next = elem;
  elem->prev->next = new_elem;
  elem->prev = new_elem;
  return (0);
}

int		new_behind_add(t_list *elem, char *line)
{
  t_list	*new_elem;

  (void)line;
  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (-1);
  new_elem->prev = elem;
  new_elem->next = elem->next;
  elem->next->prev = new_elem;
  elem->next = new_elem;
  return (0);
}
