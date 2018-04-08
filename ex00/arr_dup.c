/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:05:39 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 20:35:35 by pebraun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** arr_dup
**
** Input Args:
** 	char **given_arr	- provided sudoku array
**
** Returns: duplicate of the given array
**
** Description:
** Uses malloc to first allocate space for an array of 9 pointers,
** then uses malloc to allocate space for each row (string), and copies
** the corresponding row (string) over from the given array.
*/

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**arr_dup(char **given_arr)
{
	char	**dup;
	int		k;

	dup = malloc(sizeof(char *) * 9);
	k = 0;
	while (k < 9)
	{
		dup[k] = malloc(sizeof(char) * 10);
		ft_strcpy(dup[k], given_arr[k]);
		k++;
	}
	return (dup);
}
