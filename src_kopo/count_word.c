/*
** count_word.c for bonjour, ici nous comptons les les mots a mettre dans le str to wordtab "bonjour      ahahahh" c'est un mot in /home/rechou_a/rendu/PSU/PSU_2015_42sh/src_kopo
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Fri Jun  3 17:35:52 2016 Benjamin RECHOU
** Last update Fri Jun  3 18:37:41 2016 Benjamin RECHOU
*/

#include <stdio.h>

int			quote_check(char *str, int i)
{
  while (str[i] && str[i] != '\"')
    i++;
  return (i);
}

int			count_word(char *str)
{
  int			i;
  int			cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i])
        i = i + 1;
      if (str[i] == '\"')
	i = quote_check(str, i);
      cpt = cpt + 1;
      while (str[i] && str[i] != ' ' && str[i] != '\t')
        i = i + 1;
    }
  return (cpt);
}

int			main(int argc, char **argv)
{
  printf("cpt = %i", count_word(argv[1]));
  return (0);
}
