/*
** math.c for  in /home/romain.pillot/projects/ADM_palindrome_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 11:44:25 2017 romain pillot
** Last update Fri Jun 16 03:17:28 2017 romain pillot
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "palindrome.h"
#include "util.h"

/* @Params: convert nbr from any base to base10 */
int	convert_tobase10(char *nbr, int base)
{
  int	result;
  int	k;
  int	len;
  int	i;
  int	j;

  len = strlen(nbr);
  result = (j = 0);
  while (--len >= 0 && ++j)
    {
      k = 1;
      i = -1;
      while (++i < j - 1)
	k *= base;
      result += k * (nbr[len] - '0');
    }
  return (result);
}

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
