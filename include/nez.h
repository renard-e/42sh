/*
** nez.h for nez.h in /home/renard_e/systeme_unix/PSU_2015_42sh/include
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue May 24 10:04:56 2016 gregoire renard
** Last update Sun Jun  5 20:04:19 2016 gregoire renard
*/

#ifndef NEZ_H_
# define NEZ_H_

typedef struct	s_info t_info;

typedef	struct	s_pos t_pos;

typedef	struct	s_redi
{
  char		*fct;
  char		**fct_arg;
  char		*file;
  int		pid;
  int		fd;
  int		status;
}		t_redi;

typedef	struct	s_cpt
{
  int		start;
  int		dif;
  int		end;
}		t_cpt;

int	simple_redirect_g(t_info *info, int cpt_w);

int	double_redirect_g(t_info *info, int cpt_w);

int	simple_redirect_d(t_info *info, int cpt_w);

int	double_redirect_d(t_info *info, int cpt_w);

int	redirect_fct(t_info *info);

int	cd_neg(t_info *info);

int	back_fct(t_info *info);

int	return_error_cd(char *str);

int	other_cd(t_info *info, char *directory);

int	change_pwd(t_info *info, char *directory);

int	change_old_pwd(t_info *info);

int	change_all_star_pwd(char *directory, t_info *info);

char	*concat_two_str_with_char(char *first, char *second, char car);

int	execute_cd_home(t_info *info);

int	cd_fct(t_info *info, char **param);

int	concat_two_param(char **new_env, int i, char **param);

int	new_add_param_env(t_info *info, char **param);

int	add_env_with_param(t_info *info, char **param);

int	add_env_without_param(t_info *info, char **param);

int	setenv_fct(t_info *info, char **param);

int	unsetenv_fct(t_info *info, char **param);

int	exit_fct(t_info *info, char **param);

void	status_fct(int status);

int	test_fct(char *fct);

int	my_get_addr_env(char **env, char *name);

char	*search_path(char *param0, char **env);

int	my_exec_param(char **param, t_info *info);

#endif /* !NEZ_H_ */
