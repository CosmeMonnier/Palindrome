/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Fri Jun 16 04:58:05 2017 romain pillot
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
  options->mode(options);
  free(options);
  return (_EXIT_SUCCESS);
}
