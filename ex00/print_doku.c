/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:30:32 by ntai              #+#    #+#             */
/*   Updated: 2017/07/09 21:06:04 by ntai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in the finished array
** puts spaces after every number except the last number
** new line after every row
** goes from 0 to 8
** we did argv++ so we skipped the name and start the array
** after the name
**
** arr[0] is argv[1]. Offset starts after the name.
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printdoku(char **array)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(array[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
