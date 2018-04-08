/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:16:30 by ntai              #+#    #+#             */
/*   Updated: 2017/07/09 20:32:49 by ntai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GOAL:find the first dot and changes i and j to dot position
**
**
** - i is the row and j is the column
** - success is needed because it checks if we have a dot or not
** - success tells you if found dot or not  (0 means no dot)
** - (1 means found dot)
*/

int	find_first_dot(char **arr, int *i, int *j)
{
	int row;
	int col;
	int success;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (arr[row][col] == '.')
			{
				*i = row;
				*j = col;
				return (success = 1);
			}
			col++;
		}
		row++;
	}
	return (success = 0);
}
