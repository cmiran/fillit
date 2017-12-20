/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/20 20:00:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Create the square that our algorithm will fill with the tetriminos.
*/

char	**init_map(char **map, char **debut, unsigned int width)
{
	int	i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * width)))
		return (0);
	while (map[i])
	{
		if (!(map[i] = ft_strcnew(width, '.')))
			return (0);
		i++;
	}
	*debut = &map[0][0];
	return (map);
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
	char	**map;
	int		track;
	char	*debut;

	width = 2;
	track = 0;
	while ((size_t)(width * width) < (gofirst->i) * 4)
		width++;
	init_map(map, &debut, width);
	while (!backtracker(map, track, gofirst->first))
	{
		init_map(map, &debut, ++width);
	}
	print_solution(map);
	return (1);
}
