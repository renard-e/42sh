/*
** get_function.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Thu Jun  2 15:29:41 2016 Jean-Adrien Domage
** Last update Sun Jun  5 16:52:06 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "my.h"
#include "nez.h"
#include "color.h"
#include "domage.h"

char	**malloc_exec_tab(char **tab, char **cpy, int size)
{
  int	len;
  int	i;

  i = 0;
  len = 0;
  if ((tab = malloc(sizeof(char*) * (size + 1))) == NULL)
    return (verror(MALLOC_ERROR));
  tab[size] = NULL;
  while (cpy[i + 3])
    {
      len = my_strlen(cpy[i + 3]);
      if ((tab[i] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (verror(MALLOC_ERROR));
      tab[i][len] = '\0';
      tab[i] = my_strcpy(tab[i], cpy[i + 3]);
      i += 1;
    }
  return (tab);
}

int	get_alias(t_info *env,  char **tab)
{
  char	*alias;
  char	*commande;
  char	**exec_tab;
  int	i;
  int	len;

  i = 0;
  if (tab[1] == NULL)
    return (-1);
  alias = my_strdup(tab[1]);
  if (tab[2][0] != '=')
    return (merror(ALIAS_ERROR, -1));
  len = my_strlen_tabb(tab);
  if ((exec_tab = malloc_exec_tab(exec_tab, tab, len - 3)) == NULL)
    return (-1);
  commande = get_commande_line(exec_tab);
  if ((env->share.idx = add_to_list(env->share.idx, alias, commande)) == NULL)
    return (-1);
  return (0);
}

int	get_env_var(t_info *env, char **tab)
{
  if (setenv_fct(env, tab) == -1)
    return (-1);
  return (0);
}

char	*parse_prompt(t_info *env, char **p_tab)
{
  char	*tmp;
  int	i;
  int	pos;

  i = 0;
  if (!(tmp = malloc(1)))
    return (NULL);
  tmp[0] = '\0';
  while (p_tab[i])
    {
      if (p_tab[i + 1] && p_tab[i][0] == '%'
	  && (pos = my_get_addr_env(env->env, p_tab[i + 1])) != -1)
	{
	  if (!(tmp = concat_two_str_with_char(tmp, ENV_LEN, STOP_CHAR)))
	    return (NULL);
	  i += 1;
	}
      else if (p_tab[i] && p_tab[i][0] != '%' && p_tab[i][0] != '!'
	       && p_tab[i][0] != '\0')
	if (!(tmp = concat_two_str_with_char(tmp, p_tab[i], STOP_CHAR)))
	  return (NULL);
      i += 1;
    }
  return (tmp);
}

int	get_prompt_var(t_info *env, char **tab)
{
  char	*tmp;

  (void)env;
  if (tab[1] == NULL)
    return (-1);
  if (!(tmp = my_strdup(tab[1])))
    return (-1);
  g_prompt = tmp;
}
