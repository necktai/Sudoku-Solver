/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:29:11 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/09 21:07:40 by ntai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

char	**arr_dup(char **given_arr);
int		find_first_dot(char **arr, int *i, int *j);
void	free_arr(char **arr);
int		is_valid(char **arr, int row, int col, char attempt);
int		solver(char **given_arr);
void	ft_printdoku(char **array);

#endif
