/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Thu Jun 15 14:21:43 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"
#include "util.h"

int		main(int ac, char **args)
{
  t_options	*options;

  printf("(%s)\n", base10_convert(atoi(args[1]), atoi(args[2])));
  if (!(options = load_options(args)))
    {
      printf("%s: invalid options.\n", *args);
      return (_EXIT_FAILURE);
    }
  return (_EXIT_SUCCESS);
}
