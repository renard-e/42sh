/*
** nakach.h for nakach in /home/nakach_v/PSU_2015_42sh/include
** 
** Made by vincent nakache
** Login   <nakach_v@epitech.net>
** 
** Started on  Tue May 31 14:17:35 2016 vincent nakache
** Last update Sun Jun  5 18:24:49 2016 vincent nakache
*/

#ifndef _NAKACH_H_
# define _NAKACH_H_

typedef struct	s_all	t_all;

int		count_words_quotes(char *str);

char		**my_str_to_word_tab_quotes(char *arg);

int		check_nb_quote(char *str);

int		echo(t_info *data, char **tab);

int		quotes_fct(t_all *all, char **cmd, char *arg);

int		remp_quotes(char *arg, char **cmd, t_all *all);

void		end_backslash(char *str);

#endif /* !_NAKACH_H_ */
