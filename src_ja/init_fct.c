/*
** init_fct.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Tue May 31 14:30:53 2016 Jean-Adrien Domage
** Last update Sat Jun  4 22:23:12 2016 Jean-Adrien Domage
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "domage.h"
#include "color.h"

void	free_init_fct(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
}

char	**init_fct(void)
{
  char	**fct_tab;

  if ((fct_tab = malloc(sizeof(char*) * 4)) == NULL)
    return (verror(MALLOC_ERROR));
  fct_tab[0] = my_strdup(ALIAS);
  fct_tab[1] = my_strdup(SET_ENV);
  fct_tab[2] = my_strdup(PROMPT);
  fct_tab[3] = NULL;
  fct_init[0] = &get_alias;
  fct_init[1] = &get_env_var;
  fct_init[2] = &get_prompt_var;
  fct_init[3] = NULL;
  return (fct_tab);
}

int	pars_data(t_info *env, char **fct_tab, char *str)
{
  int	i;
  char	**tab;
  char	*alias;
  char	*commande;

  i = 0;
  epur_str(&str, str, '=');
  epur_str(&str, str, '\'');
  tab = my_str_to_word_tab(str);
  while (fct_tab[i])
    {
      if (word_word(tab[0], fct_tab[i]) == 1)
	if ((fct_init[i])(env, tab) == -1)
	  return (-1);
	else
	  return (0);
      i += 1;
    }
  parser_lexer(env, str);
  free(tab);
  return (0);
}

int	init_color(t_info *env)
{
  char	**tab_name;

  if ((env->share.color_name = malloc(sizeof(char*) * 7)) == NULL)
    return (merror(MALLOC_ERROR, -1));
  if ((env->share.color = malloc(sizeof(char*) * 7)) == NULL)
    return (merror(MALLOC_ERROR, -1));
  env->share.color_name[0] = my_strdup(N_WHITE);
  env->share.color_name[1] = my_strdup(N_RED);
  env->share.color_name[2] = my_strdup(N_GREEN);
  env->share.color_name[3] = my_strdup(N_PINK);
  env->share.color_name[4] = my_strdup(N_BLUE);
  env->share.color_name[5] = my_strdup(N_YELLOW);
  env->share.color_name[6] = NULL;
  env->share.color[0] = my_strdup(WHITE);
  env->share.color[1] = my_strdup(RED);
  env->share.color[2] = my_strdup(GREEN);
  env->share.color[3] = my_strdup(PINK);
  env->share.color[4] = my_strdup(BLUE);
  env->share.color[5] = my_strdup(YELLOW);
  env->share.color[6] = NULL;
}

int		init_function(t_info *env)
{
  char		**fct_tab;
  char		*str;
  int		fd;

  if ((fct_tab = init_fct()) == NULL)
    return (-1);
  if ((g_prompt = my_strdup(SAMPLE_PROMPT)) == NULL)
    exit (1);
  if (init_color(env) == -1)
    exit(1);
  env->share.idx = NULL;
  if ((fd = open(PATH_RC, O_RDONLY)) == -1)
    return (merror(OPEN_ERROR, -1));
  while ((str = get_next_line(fd)) != NULL)
    {
      pars_data(env, fct_tab, str);
      free(str);
    }
  free_init_fct(fct_tab);
  close(fd);
  return (0);
}
