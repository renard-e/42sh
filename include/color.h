/*
** color.h for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/include
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Wed Jun  1 09:20:43 2016 Jean-Adrien Domage
** Last update Sun Jun  5 00:59:20 2016 Jean-Adrien Domage
*/

#ifndef COLOR_H_
# define COLOR_H_

#include "my.h"

# define SAMPLE_PROMPT "\033[0;32;40m$>\033[m"

/*
** This is predefine color for sample usage
*/

# define	DEFAULT "\033[m"

# define	N_WHITE "WHITE"
# define	N_RED "RED"
# define	N_GREEN "GREEN"
# define	N_PINK "PINK"
# define	N_BLUE "BLUE"
# define	N_YELLOW "YELLOW"

# define	WHITE "\033[37m"
# define	RED "\033[31m"
# define	GREEN "\033[32m"
# define	PINK "\033[35m"
# define	BLUE "\033[34m"
# define	YELLOW "\033[33m"

/*
** This is COLOR for set_color() function
*/

# define	NORMAL "0"
# define	FAT "1"
# define	UNDERLINE "4"
# define	INVERS "7"

# define	FONT_BLACK ";30"
# define	FONT_RED ";31"
# define	FONT_GREEN ";32"
# define	FONT_YELLOW ";33"
# define	FONT_BLUE ";34"
# define	FONT_PINK ";35"
# define	FONT_CYAN ";36"
# define	FONT_WHITE ";37"

# define	BACK_BLACK ""
# define	BACK_RED ";41"
# define	BACK_GREEN ";42"
# define	BACK_YELLOW ";43"
# define	BACK_BLUE ";44"
# define	BACK_PINK ";45"
# define	BACK_CYAN ";46"
# define	BACK_WHITE ";47"

/*
**  End of global usful define
*/

# define	COLOR_FORMAT "\033["
# define	END_CHAR "m"
# define	STOP_CHAR '\0'

char	*g_prompt;

/*
** set_color function allow you too set a color result in
** the terminal. The usage are:
** [TYPE][COLOR_FONT][COLOR_BACK]
** if there is no argument give with set_color
** it will set the DEFAULT
*/

int	set_color(char *type, char *font, char *back);

/*
** This is the function for printing prompt and color
** set_prompt_color, have the same usage as set_color.
** but il will modify g_prompt
*/

int	write_prompt(t_info *env);
char	**set_prompt_color(t_info *env, char **tab);

#endif	/* !COLOR_H_ */
