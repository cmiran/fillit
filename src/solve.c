/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/20 19:29:22 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Create the square that our algorithm will fill with the tetriminos.
*/

char	**square_creator(int width, char *debut)
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
	debut = &square[0][0];
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
	current = current->next;
}

/*
** Backtracking algorithm that call himself back to continue the filling
** or to go back and find another solution.
*/

int		backtracker(char **position, int track, t_etris *curr, t_control *gofirst,
		char *debut)
{
	int	i;

	i = 0;
	if (curr == NULL)
		return (1);
	while (position[curr->x[i]][curr->y[i]] &&
			position[curr->x[i]][curr->y[i]] == '.' && i < 4)
		i++;
	if (i == 4)
		copy_cat(position, curr);
	if (position[0][1])
		*position = &position[0][1];
	else if (position[1][-track])
		*position = &position[0][-track];
	if (!position[0][1] && !position[1][0])
		return (backtracker(debut, 0, ...)
	else
		return (i = 4 ? backtracker(debut, 0, curr) : backtracker(position, track++, curr);
}

/*
** Main fonction that call others fonctions to create the solution square,
** fill it, and checks if everything's fine.
*/

int		solve(t_control *gofirst)
{
	int		width;
	char	**square;
	int		track;
	char	*debut;

	width = 2;
	track = 0;
	while (width * width < (gofirst->i) * 4)
		width++;
	square = square_creator(width, debut);
	while (!backtracker(square, track, gofirst->first))
	{
		square = square_creator(++width, debut);
	}
	print_solution(square);
	return (1);
}
