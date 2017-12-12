/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:35:21 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/12 17:01:33 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Justify y to the top.
*/

void	go_y_up(int *y)
{
	int	i;
	int	y_check;

	i = 0;
	while (y[i])
	{
		y[i] -= 1;
		i++;
	}
	i = 0;
	while (y[i])
	{
		if (y[i] == 0)
			y_check = 1;
		i++;
	}
	if (y_check != 1)
		go_y_up(y);
}

/*
** Justify x to the left.
*/

void	go_x_left(int *x)
{
	int	i;
	int	x_check;

	i = 0;
	while (x[i])
	{
		x[i] -= 1;
		i++;
	}
	i = 0;
	while (x[i])
	{
		if (x[i] == 0)
			x_check = 1;
		i++;
	}
	if (x_check != 1)
		go_x_left(x);
}

/*
** Check if there is a least one '0' in string x & string y.
** If true, the tetrimino is margined.
*/

void	is_top_left(int *x, int *y)
{
	int	i;
	int	x_check;
	int	y_check;
	
	i = 0;
	while (x[i] && y[i])
	{
		if (x[i] == 0)
			x_check = 1;
		if (y[i] == 0)
			y_check = 1;
		if (x_check + y_check == 2)
			return ;
		i++;
	}
	if (x_check != 1)
		go_x_left(x);
	if (y_check != 1)
		go_y_up(y);
}

/*
** Get abscissa and ordinate for each '#'.
*/

void	get_pos(const char *str, int *x, int *y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j] == '#')
			{
				*x++ = j;
				*y++ = k;
			}
			j++;
		}
		i += j + 1;
		k++;
	}
}

/*
** Create a tetrimino with its id & coordinates on the chunk.
*/

void	write_tetri(const char *str, t_etris *tetri, char id)
{
	int	i;
	int	x[4];
	int	y[4];

	i = 0;
	get_pos(str, x, y);
	is_top_left(x, y);
	tetri->id = id;
	while (i < 4)
	{
		tetri->x[i] = x[i];
		tetri->y[i] = y[i];
		i++;
	}
	tetri->next = NULL;
}
