/*
** main.h for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:15:51 2016 romain pillot
** Last update Thu Jun 15 09:39:11 2017 romain pillot
*/

#ifndef PALINDROME_H_
# define PALINDROME_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

typedef enum	e_mode
{
  UNDEFINED = 0,
  TRANSFORM = 1,
  REVERSE = 2
}		t_mode;

typedef struct	s_options
{
  int		i;
  t_mode	mode;
  int		base;
  int		min;
  int		max;
}		t_options;

t_options	*load_options(char **args);

#endif /** !PALINDROME_H_ **/
