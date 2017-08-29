/*
** 42sh.c for 42sh in /home/renard_e/systeme_unix/PSU_2015_42sh
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue May 24 09:43:02 2016 gregoire renard
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sun Jun  5 20:23:25 2016 gregoire renard
=======
** Last update Sun Jun  5 15:54:00 2016 Jean-Adrien Domage
>>>>>>> 6bd70651c1469ea8fc73f879ef939522a2cffa1c
=======
** Last update Sun Jun  5 21:12:55 2016 vincent nakache
>>>>>>> a017d096b4c2053d77be4b9986cff0053986fa07
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "color.h"
#include "domage.h"

int	parser_lexer(t_info *help, char *s)
{
  if (check_nb_quote(s) == 0)
    return (0);
  epur_minishell1_str_test(&s, s);
  help->tabb = my_str_to_wordtab_quotes(s);
  help->nb_tabb = my_strlen_tabb(help->tabb);
  if (verif_separator(help) != -1)
    {
      alloc_triple_tabb(help);
      if (verif_syntax(help) == -1)
	{
	  my_putstr_error("Error_syntax !!!\n");
	    return (1);
	}
      distrib_command(help);
    }
  return (1);
}

void	free_all(t_info *info, char **line)
{
  free((*line));
  free_tabb(info->tabb);
  free(info->triple_tabb);
  free(info->sep_place);
  free(info->tabi);
}

int	all(char **ae)
{
  t_info	info;
  char		*line;
  char		**param;
  int		indic;

  info.env = ae;
  signal(SIGINT, SIG_IGN);
  if ((FCT_TAB = init_builtin_fct(FCT_TAB)) == NULL
      || init_function(&info) == -1)
    return (merror(MALLOC_ERROR, -1));
  write_prompt(&info);
  set_color(NORMAL, FONT_WHITE, BACK_BLACK);
  while ((line = get_next_line(0)) != NULL)
    {
      set_color(NORMAL, FONT_WHITE, BACK_BLACK);
      alias_commande(&info, &line, line);
      if (parser_lexer(&info, line) != 0)
	free_all(&info, &line);
      if (line != NULL)
	write_prompt(&info);
    }
  free_builtin_tab(info.builtin_tab);
  my_putstr("exit\n");
  return (info.wit_comm);
}

int		main(int argc, char **argv, char **ae)
{
  voidable(&argc, argv);
  if (all(ae) == -1)
    return (1);
  return (0);
}
