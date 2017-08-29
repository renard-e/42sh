##
## Makefile for library in /home/renard_e/Makefile/
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Oct 12 09:42:55 2015 gregoire renard
## Last update Thu Jun  2 12:06:05 2016 vincent nakache
##

NAME	= libmy.a

SRCS	= my_putchar.c \
	  my_putstr.c \
	  my_isneg.c \
	  my_put_nbr.c \
	  my_revstr.c \
	  my_strcat.c \
	  my_strcpy.c \
	  my_strlen.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_swap.c \
	  my_getnbr.c \
	  my_sort_int_tab.c \
	  my_power_rec.c \
	  my_square_root.c \
	  my_is_prime.c \
	  my_strcmp.c \
	  my_strupcase.c \
	  my_strlowcase.c \
	  my_strcapitalize.c \
	  my_str_isalpha.c \
	  my_str_isnum.c \
	  my_str_islower.c \
	  my_str_isupper.c \
	  my_str_isprintable.c \
	  get_next_line.c \
	  my_strdup.c \
	  convert_in_char.c \
	  my_tr.c \
	  list_fct.c \
	  list_fct2.c \
	  my_str_to_word_tab.c \
	  my_str_to_word_tab_with_quotes.c \
	  remp_before_quotes.c \
	  aff_tab.c \
	  my_putstr_error.c \
	  word_word.c \
	  my_strlen_tabb.c \
	  epur.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Werror -Wall -Wextra

CC	= gcc -I../../include/

ECHO	= echo -e

DEFAULT	= "\033[00m"
GREEN	= "\033[0;32m"
TEAL	= "\033[1;36m"
RED	= "\033[0;31m"
PURP	= "\033[0;35m"

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) && \
	$(ECHO) $(GREEN) "[LIB] [OK]" $(TEAL) $(NAME) $(DEFAULT) || \
	$(ECHO) $(RED) "[LIB] [FAILED]" $(TEAL) $(NAME)
	ranlib $(NAME)
	cp -r libmy.a ../

clean:
	@$(RM) $(OBJS) && \
	$(ECHO) $(PURP) "[RM]" $(TEAL) "[OBJS]" $(DEFAULT)

fclean:	clean
	@$(RM) $(NAME) && \
	$(ECHO) $(PURP) "[RM]" $(TEAL) $(NAME) $(DEFAULT)

re: fclean all

.c.o:
	@$(CC) -g3 -c $< -o $@ && \
	$(ECHO) $(GREEN) "[LIB] [OK]" $(TEAL) $< $(DEFAULT) || \
	$(ECHO) $(RED) "[LIB] [FAILED]" $(TEAL) $< $(NAME)

.PHONY : all re clean fclean

