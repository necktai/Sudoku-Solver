/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:22:02 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 20:47:18 by pebraun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** free_arr
**
** Input Args:
** 	char***arr	- given sudoku array
**
** Returns: void
**
** Description: Frees memory used by each string (row), and then
** 	the memory used by the array of char*
*/

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 9)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
