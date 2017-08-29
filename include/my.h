/*
** my.h for my.h in /home/renard_e/systeme_unix/PSU_2015_my_printf
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Fri Nov 13 14:28:11 2015 gregoire renard
<<<<<<< HEAD
** Last update Mon Feb  6 16:59:00 2017 Gregoire Renard
=======
** Last update Sun Jun  5 17:20:21 2016 rodrigue rene
>>>>>>> 5f0239904541398eb6a69c308816b48b9d53179b
*/

#ifndef MY_H_
# define MY_H_

# include <stdio.h> //A ENLEVER
# include "nez.h"
# include "domage.h"
# include "kopo.h"
# include "rene.h"

# define	READ_SIZE 1024
# define	LEN 4096
# define	TABB info->triple_tabb[info->command_num]
# define	TABBH help->triple_tabb[help->command_num]

typedef	struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef	struct	s_info
{
  t_share	share;
  char		**env;
  char		*pwd;
  char		*oldpwd;
  int		witness;
  int		wit_comm;
  int		*tabi;
  int		*sep_place;
  char		**tabb;
  int		nb_tabb;
  char		***triple_tabb;
  int		command_num;
  int		fill;
  int		all;
  char		**builtin_tab;
}		t_info;

typedef struct	s_list
{
  char		*line;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_all
{
  int		s;
  int		e;
  int		dif;
  int		remp;
  int		i;
  int		dimen;
  int		state;
}		t_all;

char	**my_str_to_wordtab_quotes(char *str);

int	my_strlen_tabb(char **tab);

void	free_tab(char **tab);

void	aff_tab(char **tab);

int	word_word(char *str1, char *str2);

int	new_front_add(t_list *elem, char *line);

t_list	*create_list(void);

void	epur_str(char **s, char *str, char c);

char	**my_str_to_word_tab(char *arg);

void	my_double(int ac, t_list **list);

void	my_circu(t_list **list);

t_list	*my_params_in_list(t_list *list, char *line);

int	my_tr(char **file);

char	*convert_in_char(int nb);

char	*get_next_line(const int fd);

void	my_putchar(char c);

void	my_isneg(int nb);

void	my_put_nbr(int nb);

int	my_swap(int *a, int *b);

void	my_putstr(char *str);

void	my_putstr_error(char *str);

int	my_strlen(char *str);

int	my_getnbr(char *str);

void	my_sort_int_tab(int *tab, int size);

int	my_power_rec(int nb, int power);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

char	*my_strcpy(char *dest, char *src);

char	*my_strncpy(char *dest, char *src, int nb);

char	*my_revstr(char *str);

char	*my_strstr(char *str, char *to_find);

int	my_strcmp(char *s1, char *s2);

int	my_strncmp(char *s1, char *s2, int nb);

char	*my_strupcase(char *str);

char	*my_strdup(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char *str);

int	my_str_isnum(char *str);

int	my_str_islower(char *str);

int	my_str_isupper(char *str);

int	my_str_isprintable(char *str);

int	my_showstr(char *str);

int	my_showmem(char *str, int size);

char	*my_strcat(char *dest, char *src);

char	*my_strncat(char *dest, char *src, int nb);

int	builtins(t_info *info);

int	distrib_command(t_info *help);

int	verif_separator(t_info *help);

int	verif_syntax(t_info *help);

int	word_word(char *str_one, char *str_two);

int	error_null_command(void);

int	my_strlen_command(int *tabi);

int	alloc_triple_tabb(t_info *help);

int	verif_syntax(t_info *help);

int	len(char *str);

void	voidable(void *argc, void *argv);

void	my_exit_malloc(void);

void	my_exit_sys(void);

void	my_realloc_inverse(char **suits, int i, char *str);

int	distrib_command(t_info *help);

void    epur_minishell1_str_test(char **s, char *str);

int	grep_word(char *str, char **tabb);

int	my_strlen_tabbb(char ***tabbb);

void	my_putstrd(char *str, int i);

int	pipe_part_one(t_info *help);

#endif /* !MY_H_ */
