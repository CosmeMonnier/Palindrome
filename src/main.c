/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Thu Jun 15 15:09:54 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"
#include "util.h"

int		main(int ac, char **args)
{
  t_options	*options;

  if (!(options = load_options(args)))
    {
      fprintf(stderr, "invalid argument\n");
      return (_EXIT_FAILURE);
    }
  if (options->mode == REVERSE)
    reverse_palindrome(options);
  else
    find_palindrome(options);
  free(options);
  return (_EXIT_SUCCESS);
}
