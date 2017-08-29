/*
** my_putchar.c for my_putchar in /home/renard_e
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Oct  3 15:03:45 2015 gregoire renard
** Last update Fri Jan 22 04:16:38 2016 gregoire renard
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
