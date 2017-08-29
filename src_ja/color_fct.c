/*
** color_fct.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Wed Jun  1 10:39:42 2016 Jean-Adrien Domage
** Last update Sun Jun  5 16:13:39 2016 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include "nez.h"
#include "domage.h"
#include "color.h"
#include "my.h"

char	**set_prompt_color(t_info *env, char **tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (COLOR_TAB)
    {
      if (C_T && COLOR_TAB[0] == '!')
	while (env->share.color_name[j])
	  {
	    if (word_word(C_T, env->share.color_name[j]) == 1)
	      {
		free(C_T);
		if (!(C_T = my_strdup(env->share.color[j])))
		  exit (1);
		i += 1;
	      }
	    j += 1;
	  }
      j = 0;
      i += 1;
    }
  return (tab);
}

int		set_color(char *type, char *font, char *back)
{
  char		*new;

  if (!(new = concat_two_str_with_char(COLOR_FORMAT, type, STOP_CHAR)))
    return (-1);
  if (!(new = concat_two_str_with_char(new, font, STOP_CHAR)))
    return (-1);
  if (!(new = concat_two_str_with_char(new, back, STOP_CHAR)))
    return (-1);
  if (!(new = concat_two_str_with_char(new, END_CHAR, STOP_CHAR)))
    return (-1);
  if (write(1, new, my_strlen(new)) != my_strlen(new))
    return (-1);
  free(new);
}

int	write_prompt(t_info *env)
{
  char	**p_tab;
  char	*tmp;
  int	i;

  i = 0;
  my_putstr(DEFAULT);
  if (!(tmp = my_strdup(g_prompt)) && isatty(0) != 1 && isatty(1) != 1)
    return (-1);
  epur_str(&tmp, tmp, '%');
  epur_str(&tmp, tmp, '!');
  p_tab = my_str_to_word_tab(tmp);
  free(tmp);
  p_tab = set_prompt_color(env, p_tab);
  if (!(tmp = parse_prompt(env, p_tab)))
    return (-1);
  if (write(1, tmp, my_strlen(tmp)) != my_strlen(tmp))
    return (-1);
  free(tmp);
  while (p_tab[i])
    {
      free(p_tab[i]);
      i += 1;
    }
  free(p_tab);
  return (0);
}
