/*
** domage.h for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/include
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Tue May 31 14:32:38 2016 Jean-Adrien Domage
** Last update Sun Jun  5 16:52:07 2016 Jean-Adrien Domage
*/

#ifndef DOMAGE_H_
# define DOMAGE_H_

# include "nez.h"

# define ENV_LEN env->env[pos] + STRLEN
# define COLOR_TAB tab[i]
# define C_T tab[i + 1]
# define STRLEN my_strlen(p_tab[i + 1]) + 1
# define FCT_TAB info.builtin_tab

# define PATH_RC ".42rc"
# define EXIT_STRING "exit\n"

# define ALIAS_ERROR "An error occured while parsing alias.\n"
# define OPEN_ERROR "Open fail, please if you want to use a 42rc,\
run it in the current directorie!\n"
# define MALLOC_ERROR "Fail on malloc!\n"
# define EXIT_ERROR "Error : exit expression Syntax.\n"
# define USETENV_ERROR1 "unsetenv: Too few arguments.\n"
# define USETENV_ERROR2 "Error : malloc failure\n"
# define SETENV_ERROR "setenv: Too many arguments.\n"
# define SETENV_MALLOC_ERROR "Error : malloc failure\n"
# define CD_ERROR "cd: Too many arguments.\n"
# define CD_MALLOC_ERROR "Error : malloc failure\n"

# define ALIAS "alias"
# define SET_ENV "setenv"
# define PROMPT "prompt"

# define EXIT "exit"
# define UNSETENV "unsetenv"
# define SETENV "setenv"
# define CD "cd"
# define ECHO "echo"

typedef struct	s_alias
{
  char			*alias;
  char			*exec_line;
  struct s_alias	*next;
}		t_alias;

typedef struct	s_share
{
  t_alias	*idx;
  char		**color;
  char		**color_name;
}		t_share;

int	(*fct_init[4])(t_info *, char **);
t_alias	*add_to_list(t_alias *idx, char *str, char *tab);
int	init_function(t_info *env);
int	get_env_var(t_info *env, char **tab);
int	get_alias(t_info *env, char **tab);
int	merror(char *str, int ret);
void	*verror(char *str);
char	*my_nstrcpy(char *dest, char *src, int n);
int	parser_lexer(t_info *help, char *s);
int	get_prompt_var(t_info *env, char **tab);
char	*parse_prompt(t_info *env, char **p_tab);
char	*get_commande_line(char **tab);
int	alias_commande(t_info *env, char **modif,char *str);

/*
**  Pointeur sur fonction pour builtins.c
*/

int	(*builtin_fct[6])(t_info *, char **);
char	**init_builtin_fct(char **tab);
void	free_builtin_tab(char **tab);

#endif	/* !DOMAGE_H_ */
