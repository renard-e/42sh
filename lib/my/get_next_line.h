/*
** get_next_line.h for get_next_line in /home/renard_e/CPE_2015_getnextline
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jan  4 14:20:53 2016 gregoire renard
** Last update Wed Jan 20 09:28:43 2016 gregoire renard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE 3456776
# endif /* !READ_SIZE_ */

typedef struct	s_gnl
{
  int		ret;
  char		*save;
  int		len;
}		t_gnl;

char		*get_next_line(const int fd);
char		*buffer_analysis(char *buffer, int *cpt_buf);
char		*my_realloc(char *line, int new);

#endif /* !GET_NEXT_LINE_H_ */
