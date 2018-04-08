/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:51:45 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 21:17:12 by pebraun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

/*
** strlen. finds the string length, don't complicate it.
*/

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/*
** dot_number_checker
**
** Returns: an int > 0 if there is an error, i.e. if array is not only
** 		numbers 1-9 and dots. If no error, returns 0.
** Description:
** 	Iterates through the array and ensures all characters are allowed.
*/

int		dot_number_checker(char **array)
{
	int i;
	int j;
	int error;

	error = 0;
	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (array[i][j] != '.' && (array[i][j] > 58 || array[i][j] < 47))
				error += 1;
			j++;
		}
		i++;
	}
	return (error);
}

/*
** main
**
** Input Args:
** 	Takes nine strings of length nine made up of numbers 1-9 and dots, and
** 	prints the solution to the puzzle.
**
** 	Returns: Prints error message if input args are the wrong size or do not
** 		contain allowable characters.
*/

int		main(int argc, char *argv[])
{
	int error;
	int k;

	argv++;
	error = (argc != 10);
	k = 0;
	while (k < 9 && !error)
	{
		error += (ft_strlen(argv[k]) != 9);
		k++;
	}
	error += dot_number_checker(argv);
	if (!error)
		error = !solver(argv);
	if (error)
		write(1, "Error\n", 6);
	return (0);
}
