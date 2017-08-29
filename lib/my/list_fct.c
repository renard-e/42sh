/*
** list_fct.c for list_fct in /home/renard_e/systeme_unix/PSU_2015_my_select
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Dec  7 12:19:36 2015 gregoire renard
** Last update Tue May 10 15:54:57 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

void		my_double(int ac, t_list **list)
{
  t_list	*list_ac;
  t_list	*list_prev;
  int		i;

  i = 0;
  list_ac = (*list)->next;
  list_prev = *list;
  while (i <= ac)
    {
      list_prev->next = list_ac;
      list_ac->prev = list_prev;
      list_ac = list_ac->next;
      list_prev = list_prev->next;
      i = i + 1;
    }
}

void		my_circu(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = *list;
}

void		my_free_list(t_list *list, int ac)
{
  t_list	*tempo;
  int		i;

  i = 1;
  while (i < ac)
    {
      tempo = list;
      list = list->next;
      free(tempo);
      i = i + 1;
    }
}

int		my_put_in_list(t_list **list, char *line)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->line = line;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list		*my_params_in_list(t_list *list, char *line)
{
  if ((my_put_in_list(&list, line)) == -1)
    return (NULL);
  return (list);
}
