/*
** option.c for  in /home/romain.pillot/projects/ADM_palindrome_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 08:21:32 2017 romain pillot
** Last update Thu Jun 15 09:57:13 2017 romain pillot
*/

#include <stdlib.h>
#include "palindrome.h"
#include "util.h"

static bool	loop_content(t_options *options, char **args, int *i)
{
  if ((str_equals(args[(*i)], "-n") && (options->mode = TRANSFORM)) ||
      (str_equals(args[(*i)], "-p") && (options->mode = REVERSE)))
    if (options->i >= 0 || !args[++(*i)])
      return (false);
    else
      options->i = atoi(args[(*i)]);
  else if (str_equals(args[(*i)], "-b"))
    if (options->base != -1 || !args[++(*i)])
      return (false);
    else
      options->base = atoi(args[(*i)]);
  else if (str_equals(args[(*i)], "-imin"))
    if (options->min != -1 || !args[++(*i)])
      return (false);
    else
      options->min = atoi(args[(*i)]);
  else if (str_equals(args[(*i)], "-imax"))
    if (options->max != -1 || !args[++(*i)])
      return (false);
    else
      options->max= atoi(args[(*i)]);
  else
    return (false);
  return (true);
}

static bool	parse_options(t_options *options, char **args)
{
  int		i;
  bool		reverse;

  i = 0;
  while (args[++i])
    if (!loop_content(options, args, &i))
      return (false);
  return (true);
}

static bool	valid_options(t_options *options)
{
  if (options->base == -1)
    options->base = 10;
  if (options->min == -1)
    options->min = 0;
  if (options->max == -1)
    options->max = 100;
  return (options->mode != UNDEFINED &&
	  options->i >= 0 &&
	  options->min >= 0 && options->max >= 0 &&
	  options->min <= options->max &&
	  options->base > 0 && options->base <= 10);
}

t_options	*load_options(char **args)
{
  t_options	*options;

  if (!(options = malloc(sizeof(t_options))))
    return (NULL);
  options->i = -1;
  options->mode = UNDEFINED;
  options->base = -1;
  options->min = -1;
  options->max = -1;
  if (!parse_options(options, args) || !valid_options(options))
    {
      FREE(options);
      return (NULL);
    }
  return (options);
}
