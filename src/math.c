/*
** math.c for  in /home/romain.pillot/projects/ADM_palindrome_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 11:44:25 2017 romain pillot
** Last update Thu Jun 15 14:22:33 2017 romain pillot
*/

#include <stdlib.h>
#include "palindrome.h"

/* @Params: nbr >= 0 and 1 > base <= 10 */
char	*base10_convert(int nbr, int base)
{
  char	*result;
  int	cpy;
  int	len;

  cpy = nbr;
  len = 0;
  while (++len && (cpy /= base));
  if (!(result = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  if (!nbr)
    result[0] = '0';
  result[len] = 0;
  while (nbr)
    {
      result[--len] = nbr % base + '0';
      nbr /= base;
    }
  return (result);
}
