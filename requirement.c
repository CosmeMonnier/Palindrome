/*
** requirement.c for  in /home/romain.pillot/projects/ADM_palindrome_2016
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 07:05:30 2017 romain pillot
** Last update Fri Jun 16 05:15:03 2017 romain pillot
*/

#include <stdlib.h>
#include <limits.h>

int	my_factrec_synthesis(int nb)
{
  return (nb < 0 ? 0 :
	  nb == 0 ? 1 :
	  nb * my_factrec_synthesis(nb - 1));
}

/*
** Binarys search algorithm, reducing interval / 2
*/
int		my_squareroot_synthesis(int nb)
{
  double	lo;
  double	hi;
  double	mid;
  int		i;

  lo = 0;
  hi = nb;
  i = -1;
  while (++i < 1000)
    {
      mid = (lo+hi)/2;
      if (((int)mid)*((int)mid) == nb)
	return (mid);
      if (mid*mid > nb)
	hi = mid;
      else
	lo = mid;
    }
  return (-1);
}
