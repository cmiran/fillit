/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/19 19:19:10 by obadaoui         ###   ########.fr       */
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

void	copy_cat(char **position, t_etris *current)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		position[current->x[i]][current->y[i]] = current->id;
		i++;
	}
}

/*
** Backtracking algorithm that call himself back to continue the filling
** or to go back and find another solution.
*/

int	backtracker(char **position, t_etris *current)
{
	int	i;

	i = 0;
	if (current == NULL)
		return (1);
	while (position[current->x[i]][current->y[i]] &&
			position[current->x[i]][current->y[i]] == '.' && i < 4)
		i++;
	if (i == 4)
	{
		copy_cat(position, current);
		backtracker(position, current->next);
	}
	else if (!position[current->x[i]][current->y[i]])
	{
		...
	}
}

/*
** Main fonction that call others fonctions to create the solution square,
** fill it, and checks if everything's fine.
*/

int		solve(t_control *gofirst)
{
	int		width;
	char **square;

	width = 2;
	while (width * width < (gofirst->i) * 4)
		width++;
	square = square_creator(width);
	while (!backtracker(square, gofirst->first))
		square = square_creator(++width);
...
	print_solution(square);
	return (1);
}
