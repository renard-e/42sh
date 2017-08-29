/*
** count_word_quotes.c for count_words in /home/nakach_v/PSU/PSU_2015_42sh/src_nakach
** 
** Made by vincent nakache
** Login   <nakach_v@epitech.net>
** 
** Started on  Fri Jun  3 18:39:22 2016 vincent nakache
** Last update Sun Jun  5 20:57:14 2016 vincent nakache
*/

#include <stdio.h>

int		get_quotes(int idx, char *str)
{
  if (str[idx] == '"')
    {
      idx++;
      while (str[idx] != '\"')
	idx++;
    }
  else if (str[idx] == '\'')
    {
      idx++;
      while (str[idx] != '\'')
	idx++;
    }
  else if (str[idx] == '`')
    {
      idx++;
      while (str[idx] != '`')
	idx++;
    }
  return (idx);
}

int		cut_space(int idx, char *str)
{
  while (str[idx] == ' ' || str[idx] == '\t' && str[idx] != '\0')
    idx++;
  return (idx);
}

void		count_opti(char *str, int *idx, int *nb_words, int *state)
{
  if (str[(*idx)] == '\"' || str[(*idx)] == '\'' || str[(*idx)] == '`')
    {
      if ((*idx) != 0 && str[(*idx) - 1] != ' ' && nb_words == 0)
	(*nb_words)++;
      (*idx) = get_quotes((*idx), str);
      if (str[(*idx) + 1] != ' ' && str[(*idx) + 1] != '\0')
	(*nb_words)++;
      (*nb_words)++;
      (*state) = 1;
    }
  (*idx)++;
}

int		count_words_quotes(char *str)
{
  int		idx;
  int		nb_words;
  int		state;

  idx = 0;
  nb_words = 0;
  while (str[idx] != '\0')
    {
      state = 0;
      while (str[idx] != ' ' && str[idx] && '\t')
	count_opti(str, &idx, &nb_words, &state);
      if (state == 0)
	nb_words++;
      idx = cut_space(idx, str);
    }
  if (str[0] == ' ')
    nb_words--;
  return (nb_words);
}
