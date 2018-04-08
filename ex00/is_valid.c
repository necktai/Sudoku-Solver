/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 09:56:01 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 20:29:04 by ntai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GOAL: check whether number passes the three constraint
**
**
** is_valid function checks row, col, and box constraint
** -helper function used to decrease lines for norm
** -input: row and col is current dot position. arr is sudoku chart or 2d arr
** -attempt is the current number to test (aka 1-9)
** -output: returns the whether it has the error or not (a number or 0)
** -block row and block col are used to start at the top left of the index
** for each block
**
** ex) row/col = 0 --> block_row/col = 0. Started at [0][0]
** row/col = 7 --> 7/3 = 2 --> 2 * 3 = 6 --> [6][6]
** so with the formula it positions would be made to start at
** [0][0] or [0][3] or [0][6]
** [3][0] or [6][3] or [6][3]
** [6][0] or [6][3] or [6][6]
** r and k used to fixed infinite while loop
*/

int		check_block(char **arr, int block_row, int block_col, char attempt)
{
	int r;
	int k;
	int error;

	error = 0;
	r = block_row;
	k = block_col;
	while (r < block_row + 3)
	{
		k = block_col;
		while (k < block_col + 3)
		{
			error += (attempt == arr[r][k]);
			k++;
		}
		r++;
	}
	return (error);
}

int		is_valid(char **arr, int row, int col, char attempt)
{
	int error;
	int k;
	int block_row;
	int block_col;

	error = 0;
	k = 0;
	while (k < 9)
	{
		error += (attempt == arr[row][k]);
		error += (attempt == arr[k][col]);
		k++;
	}
	block_row = 3 * (row / 3);
	block_col = 3 * (col / 3);
	error += check_block(arr, block_row, block_col, attempt);
	return (!error);
}
