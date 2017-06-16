/*
** main.h for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:15:51 2016 romain pillot
** Last update Fri Jun 16 04:58:21 2017 romain pillot
*/

#ifndef PALINDROME_H_
# define PALINDROME_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

# define NONE		(-1)

# include <stdbool.h>

typedef struct	s_options
{
  int		i;
  void		(*mode)(struct s_options *options);
  int		base;
  int		min;
  int		max;
}		t_options;

t_options	*load_options(char **args);

bool		is_palindrome(int nbr, int base);

void		find_palindrome(t_options *options);

void		reverse_palindrome(t_options *options);

/* @Params: nbr >= 0 and 0 > base <= 10 */
char		*base10_convert(int nbr, int base);

/* Reverse */
int		convert_tobase10(char *nbr, int base);

#endif /** !PALINDROME_H_ **/
