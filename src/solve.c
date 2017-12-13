/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/13 18:56:45 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Create the square that our algorithm will fill with the tetriminos.
*/

char	**square_creator(int width)
{
	char	**square;
	int		i;
	int		j;

	i = 0;
	square = (char**)malloc(sizeof(char*) * width);
	*square = (char*)malloc(sizeof(char) * width + 1);
	while (j <= width)
	{
		while (i <= width)
			square[j][i++] = '.';
		square[j][i] = '\n';
		j++;
	}
	return (square);
}

/*
** Fonction that fill the tetrimino in the square in the position that
** have been sent by the backtracker.
*/

int		copy_cat(char id, char *pos)
{
}

/*
** Backtracking algorithm that call himself back to continue the filling
** or to go back and find another solution.
*/

int	backtracker(char *position, t_etris *current)
{
}

/*
** Main fonction that call others fonctions to create the solution square,
** fill it, and checks if everything's fine.
*/

int		solve(t_control *gofirst)
{
	int		width;
	char	**square;

	width = 2;
	while (width * width < (gofirst->i) * 4)
		width++;
	square = square_creator(width);
	if (backtracker(&square[0][0], gofirst->first))
	{
		print_solution(square);
		return (1);
	}
}
