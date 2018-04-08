/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:26:27 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 20:28:25 by pebraun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
** Function: solver
** Input Args:
** 	char **given_arr	- sudoku array, may be partially complete
**
** Returns: Whether able to solve given_arr
**
** Description:
** Takes a sudoku array, and tries to solve it using backtracking
** 1) Duplicate the array so all changes to array are local
** 2) Find the first dot (empty place) in the array. Return the row and column
** 		indices in i and j respectively. IF NO DOT FOUND, array has been solved
** 3) Now attempt to place a char in the array, 1 - 9
** 		- if character is a valid addition (does not conflict w/ other chars),
** 			insert it into our array, and attempt to solve modified array
** 		- if solver fails to solve, try each char up to 9.
** 		- if solver succeeds, end while loop and return solved
** 4) Attempts are finished, with either success or failure. Now FREE the
** 		array since we are done with it.
*/

int		solver(char **given_arr)
{
	int		i;
	int		j;
	char	attempt;
	int		solved;
	char	**arr;

	arr = arr_dup(given_arr);
	solved = 0;
	solved = !find_first_dot(arr, &i, &j);
	if (solved)
		ft_printdoku(arr);
	attempt = '1';
	while (attempt <= '9' && !solved)
	{
		if (is_valid(arr, i, j, attempt))
		{
			arr[i][j] = attempt;
			solved = solver(arr);
		}
		attempt++;
	}
	free_arr(arr);
	return (solved);
}
