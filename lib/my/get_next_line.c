/*
** get_next_line.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/lib/my
**
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
**
** Started on  Thu Jun  2 16:40:02 2016 Jean-Adrien Domage
** Last update Thu Jun  2 17:37:58 2016 rodrigue rene
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	str_len(char *str)
{
  int	i;
  i = 0;
  while (str[i] != 0)
    i = i + 1;
  return (i);
}

int	put_buf_to_line(char *line, char *buf, char *save)
{
  int	i;
  int	j;

  j = 0;
  i = str_len(line);
  while (buf[j])
    {
      if (buf[j] == '\n' || i == LEN)
	{
	  line[i] = 0;
	  if (buf[j] == '\n')
	    j = j + 1;
	  save = my_strcpy(save, buf + j);
	  return (1);
	}
      line[i++] = buf[j++];
    }
  save[0] = 0;
  line[i] = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	save[READ_SIZE];
  char		buf[READ_SIZE + 1];
  char		*line;
  int		len;

  if ((line = malloc(sizeof(char) * LEN)) == 0)
    return (NULL);
  line[0] = 0;
  if (put_buf_to_line(line, save, save) == 1)
    return (line);
  while ((len = read(fd, buf, READ_SIZE)) > 0 && LEN > 0)
    {
      buf[len] = 0;
      if (put_buf_to_line(line, buf, save) == 1)
	return (line);
    }
  if (line && line[0] != 0)
    return (line);
  return (NULL);
}
