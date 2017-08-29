/*
** pipe2.c for pipe2 in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Sun Jun  5 17:08:19 2016 rodrigue rene
** Last update Sun Jun  5 17:20:17 2016 rodrigue rene
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "domage.h"
#include "my.h"
#include "rene.h"

int	verif_command_pipe(char	***command_valid,
			   char	***tabbb,
			   int	x,
			   char	**env)
{
  int	i;

  i = 0;
  (*command_valid) = malloc(sizeof(char *) * (x + 1));
  (*command_valid)[x] = NULL;
  while (tabbb[i] != NULL)
    {
      if (((*command_valid)[i] = search_path(tabbb[i][0], env)) == NULL
	   || test_fct((*command_valid)[i]) == -1)
	return (merror(tabbb[i][0], -1));
      i++;
    }
}

void	init_tab_pipe(int ***p_tab, int x)
{
  int	i;

  i = 0;
  if (((*p_tab) = malloc(sizeof(int *) * x)) == NULL)
    exit(2);
  (*p_tab)[x - 1] = NULL;
  while (i < (x - 1))
    {
      (*p_tab)[i] = malloc(sizeof(int) * 2);
      if (pipe((*p_tab)[i]) == -1)
	exit(2);
      i++;
    }
}

void    loop_pipe(char **valid_com, char ***cmd, char **env, t_lo_pipe *pls)
{
  while (*cmd != NULL)
    {
      pipe(pls->p);
      if ((pls->pid = fork()) == -1)
	{
	  exit(EXIT_FAILURE);
	}
      else if (pls->pid == 0)
	{
	  dup2(pls->fd_in, 0);
	  if (*(cmd + 1) != NULL)
	    dup2(pls->p[1], 1);
	  close(pls->p[0]);
	  execve(*valid_com, *cmd, env);
	  exit(EXIT_FAILURE);
	}
      else
	{
	  wait(NULL);
	  close(pls->p[1]);
	  pls->fd_in = pls->p[0];
	  cmd += 1;
	  valid_com += 1;
	}
    }
}

int		pipe_part_two(char ***tabbb, int x, t_info *help)
{
  char		**command_valid;
  t_lo_pipe	pls;

  if (verif_command_pipe(&command_valid, tabbb, x, help->env) == -1)
    {
      my_putstr_error(": Command not found.\n");
      return (-1);
    }
  pls.fd_in = 0;
  loop_pipe(command_valid, tabbb, help->env, &pls);
  return (0);
}

int	pipe_part_one(t_info *help)
{
  int	*tab_i;
  int	x;
  char	***tabbb;
  int	*place_pipe;

  if ((tab_i = malloc(sizeof(int) * (x = my_strlen_tabb(TABBH)) + 1)) == NULL)
    exit(-1);
  place_pipe = malloc(sizeof(int) * (x + 1));
  remp_tabb_int(&tab_i, x - 1);
  remp_tabb_int(&place_pipe, x);
  remp_tabb_int_pipe(TABBH, &tab_i, &place_pipe);
  alloc_triple_tabb_pipe(&tab_i, &place_pipe, &tabbb, help);
  pipe_part_two(tabbb, my_strlen_tabbb(tabbb), help);
}
