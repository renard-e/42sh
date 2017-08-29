/*
** rene.h for rene in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/include
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Thu Jun  2 18:39:45 2016 rodrigue rene
** Last update Sun Jun  5 17:04:03 2016 rodrigue rene
*/

#ifndef RENE_H_
# define RENE_H_

#include "nez.h"
# include <stdio.h> //A ENLEVER

typedef struct	s_lo_pipe
{
  int		p[2];
  int		pid;
  int		fd_in;
}		t_lo_pipe;

void	free_triple_tabb(char ***tabbb);

void	free_tabb(char **tabb);

void	voidable(void *argc, void *argv);

void	my_exit_sys(void);

void	my_realloc_inverse(char **suits, int i, char *str);

void	initfour_value_to_zero(int *value, int *value_bis, int *third_value, int *fourth_value);

int	error_null_command(void);

int	error_missing(void);

void	error_command_not(t_info *info);

void	remp_tabb_int_pipe(char **tabb, int **tabi, int **separ_place);

void	remp_tabb_int_two(char **tabb, int **tabi, int **separ_place, int i);

void	fill_triple_tabb(t_info *help, int i, int *nb_arg, int nb_tabb);

int	alloc_triple_tabb_pipe(int **tabi, int **place_pipe, char ****tabb, t_info *help);

void	aff_triple_tabb(char ***tabbb);

void	remp_tabb_int(int **tabb, int x);

int	pipe_function(t_info *help);

void	delete_char(int i, char **str);

void	fill_epur_twice_test(char **s, char *str, char c);

#endif /* !RENE_H_ */
