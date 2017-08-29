##
## Makefile for Makefile in /home/renard_e/Makefile_lib
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Nov  9 11:43:47 2015 gregoire renard
## Last update Sun Jun  5 21:29:51 2016 gregoire renard
##

CC	=	gcc -Iinclude/

RM	=	rm -fr

ECHO	= 	echo -e

SRCS	=	42sh.c\
		free_fct.c \
		distrib.c \
		builtins.c \
		src_nakach/my_str_to_wordatab_quotes.c \
		src_nakach/count_word_quotes.c \
		src_nez/my_exec_param.c \
		src_nez/search_path.c \
		src_nez/my_get_addr_env.c \
		src_nez/test_fct.c \
		src_nez/status_fct.c \
		src_nez/exit_fct.c \
		src_nez/unsetenv_fct.c \
		src_nez/setenv_fct.c \
		src_nez/add_env_without_param.c \
		src_nez/add_env_with_param.c \
		src_nez/new_add_param_env.c \
		src_nez/cd_fct.c \
		src_nez/cd_neg.c \
		src_nez/other_cd.c \
		src_nez/execute_cd_home.c \
		src_nez/concat_two_str_with_char.c \
		src_nez/change_all_star_pwd.c \
		src_nez/change_pwd.c \
		src_nez/change_old_pwd.c \
		src_ja/init_fct.c\
		src_ja/my_error.c\
		src_ja/color_fct.c\
		src_ja/get_function.c\
		src_ja/ja_list.c\
		src_ja/use_ful.c \
		src_rene/epur_test.c \
		src_rene/verif_separator.c \
		src_rene/error.c \
		src_rene/epur.c \
		src_rene/tabb_to_triple_tabb.c \
		src_rene/verif_syntax.c \
		src_rene/basics3.c \
		src_rene/free_tabb.c \
		src_rene/remp_tabb_int.c \
		src_rene/tripl_tabbb_pipe.c \
		src_rene/pipe.c \
		src_rene/pipe2.c \
		src_kopo/echo.c\
		src_ja/alias_built.c \
		src_nez/redirect_fct.c \
		src_nez/simple_redirect_g.c \
		src_nez/double_redirect_g.c \
		src_nez/simple_redirect_d.c \
		src_nez/double_redirect_d.c \
		src_nez/separate_redirect.c \


OBJS 	= $(SRCS:.c=.o)

GROUP	= " By rechou_a nakach_v renard_e rene_r domage_j"

DEFAULT	= "\033[00m"
GREEN	= "\033[0;32m"
TEAL	= "\033[1;36m"
RED	= "\033[0;31m"
PURP	= "\033[0;35m"

NAME	= 42sh

CFLAGS	= -Wall -Wextra -Werror -W

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C lib/my/
	@$(CC) -o $(NAME) $(OBJS) -L lib/ -lmy && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
	$(ECHO) $(RED) "[FAILED]" $(TEAL) $(NAME)
	@$(ECHO) $(RED)
	@$(ECHO) "         +++++          +++[>+>++>"
	@$(ECHO) "        +++>++        ++>+++++>+++++"
	@$(ECHO) "       +>+++++       ++>+        ++++"
	@$(ECHO) "      +++ >+++       ++++        ++>+"
	@$(ECHO) "     +++  ++++                   ++>+"
	@$(ECHO) "    +++   ++++                  +++>"
	@$(ECHO) "   +++    ++++                 ++++"
	@$(ECHO) "  +>+     ++++               ++++"
	@$(ECHO) " +++      +>++             ++++"
	@$(ECHO) "++++++++>+++++++++       ++++"
	@$(ECHO) "++>+++++++++++++++     +<<<"
	@$(ECHO) "          <<<<        <<<<"
	@$(ECHO) "          <<<<       <-]>"
	@$(ECHO) "          >>>>       >>----.++++<<<<<"
	@$(ECHO) "          <<>>       >>>>++.--<<<<<<.  SH"
	@$(ECHO) ""
	@$(ECHO) $(GROUP)
	@$(ECHO) $(DEFAULT)


clean:
	@$(RM) $(OBJS) && \
	$(ECHO) $(PURP) "[RM]" $(TEAL) "[OBJS]" $(DEFAULT)
	@make clean -C lib/my/

fclean: clean
	@$(RM) $(NAME) && \
	$(ECHO) $(PURP) "[RM]" $(TEAL) $(NAME) $(DEFAULT)
	@make fclean -C lib/my/

re: fclean all

.c.o:
	@$(CC) -c $< -L lib/ -lmy -o $@ && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	$(ECHO) $(RED) "[FAILED]" $(TEAL) $< $(NAME)

.PHONY: all re clean fclean
