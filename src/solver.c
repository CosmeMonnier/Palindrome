/*
** solver.c for  in /home/romain.pillot/projects/ADM_palindrome_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 15:45:23 2017 romain pillot
** Last update Fri Jun 16 05:07:03 2017 romain pillot
*/

#include <string.h>
#include <stdio.h>
#include "palindrome.h"
#include "util.h"

bool     is_palindrome(int nbr, int base)
{
  char          *number;
  char          *reversed;
  bool          valid;

  number = base10_convert(nbr, base);
  reversed = str_reverse(strdup(number));
  valid = str_equals(number, reversed);
  FREE(number);
  FREE(reversed);
  return (valid);
}

static bool	find_palindrome_private(t_options *opt, int def, bool debug)
{
  int		count;
  bool		valid;
  char		*reversed;
  int		solved;
  int		nbr;

  count = 0;
  nbr = opt->i;
  while (!(valid = count >= opt->min &&
	   (def >= 0 ? def == nbr : true) &&
	   is_palindrome(nbr, opt->base)) &&
	 count < opt->max && ++count)
    {
      reversed = str_reverse(base10_convert(nbr, opt->base));
      nbr += convert_tobase10(reversed, opt->base);
      FREE(reversed);
    }
  if (valid)
    printf("%d leads to %d in %d iteration(s) in base %d\n",
	   opt->i, nbr, count, opt->base);
  else if (debug)
    printf("no solution\n");
  return (valid);
}

void    reverse_palindrome(t_options *opt)
{
  int	nbr;
  int	i;
  bool	found;

  nbr = opt->i;
  i = 0;
  found = false;
  while (++i <= nbr)
    {
      opt->i = i;
      found = find_palindrome_private(opt, nbr, false) || found;
    }
  if (!found)
    printf("no solution\n");
}

void    find_palindrome(t_options *opt)
{
  find_palindrome_private(opt, NONE, true);
}
