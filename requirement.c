/*
** requirement.c for  in /home/romain.pillot/projects/ADM_palindrome_2016
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 07:05:30 2017 romain pillot
** Last update Thu Jun 15 08:07:06 2017 romain pillot
*/

#include <stdlib.h>
#include <limits.h>

int	my_factrec_synthesis(int nb)
{
  return (nb < 0 ? 0 :
	  nb == 0 ? 1 :
	  nb * my_factrec_synthesis(nb - 1));
}

int		my_squareroot_synthesis(int nb)
{
  long long	mid;
  long long	result;

  if (nb > INT_MAX || nb < 0)
    return (-1);
  mid = nb / 2 + (!(nb % 2) ? 0 : 1);
  while ((result = mid * mid) != nb)
    if (result < nb)
      return (-1);
    else
      mid--;
  return (mid);
}
