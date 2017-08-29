/*
** my_error.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Tue May 31 14:49:58 2016 Jean-Adrien Domage
** Last update Wed Jun  1 15:52:48 2016 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	merror(char *str, int ret)
{
  write(2, str, my_strlen(str));
  return (ret);
}

void	*verror(char *str)
{
  write(2, str, my_strlen(str));
  return (NULL);
}
