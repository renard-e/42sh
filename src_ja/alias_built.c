/*
** alias_built.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Sun Jun  5 00:07:50 2016 Jean-Adrien Domage
** Last update Sun Jun  5 16:50:25 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "color.h"
#include "nez.h"
#include "domage.h"

char	*get_commande_line(char **tab)
{
  int	i;
  char	*str;

  i = 0;
  if (!(str = malloc(1)))
    exit(merror(MALLOC_ERROR, 1));
  str[0] = '\0';
  while (tab[i])
    {
      if (!(str = concat_two_str_with_char(str, tab[i], STOP_CHAR)))
	exit(1);
      if (tab[i + 1])
	if (!(str = concat_two_str_with_char(str, " ", STOP_CHAR)))
	  exit(1);
      i += 1;
    }
  return (str);
}

int		alias_commande(t_info *env, char **modif, char *str)
{
  t_alias	*tmp;
  char		**tab;
  int		i;

  i = 0;
  epur_minishell1_str_test(&str, str);
  tab = my_str_to_word_tab(str);
  while (tab[i])
    {
      tmp = env->share.idx;
      while (tmp != NULL)
	{
	  if (word_word(tab[i], tmp->alias) == 1)
	    {
	      free(*modif);
	      (*modif) = my_strdup(tmp->exec_line);
	    }
	  tmp = tmp->next;
	}
      free(tab[i]);
      i += 1;
    }
  free(tab);
  return (0);
}
