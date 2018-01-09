/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2018/01/09 23:45:53 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Create the square that the algorithm will fill with tetriminos.
*/

int	init_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * map->width + 1)))
		return (0);
	while (i < map->width)
	{
		if (!(map->map[i] = ft_strcnew(map->width, '.')))
		{
			ft_freetab(map->map);
			return (0);
		}
		i++;
	}
	map->map[i] = NULL;
	return (1);
}

/*
** Fonction that put a tetrimino in the square at the position that
** have been sent by the backtracker.
*/

void	fill_map(t_map *pos, t_etris *curr, int x, int y, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		pos->map[y + curr->y[i]][x + curr->x[i]] = c;
		i++;
	}
}

/*
** Backtracking algorithm that call himself back to continue the filling
** or to go back and find another solution.
*/

int	 backtracker(t_map *map, t_etris *curr)
{
	unsigned int	pos;
	int						i;
	int						x;
	int						y;

	if (curr == NULL)
		return (1);
	pos = 0;
	while (pos < map->width * map->width)
	{
		i = 0;
		x = pos % map->width;
		y = pos / map->width;
		while (i < 4 && y + curr->y[i] < map->width	&& x + curr->x[i] < map->width
				&& map->map[y + curr->y[i]][x + curr->x[i]] == '.')
			i++;
		if (i == 4)
		{
			fill_map(map, curr, x, y, curr->id);
			if (backtracker(map, curr->next))
				return (1);
			fill_map(map, curr, x, y, '.');
		}
		pos++;
	}
	return (0);
}

/*
** Main fonction that calls others fonctions to create the matrix,
** fill it, and checks if everything's fine.
*/

t_map		*solve_map(t_control *gofirst)
{
	t_map	*map;
	int 	i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->width = 2;
	while ((map->width * map->width) < (gofirst->i) * 4)
		map->width++;
	if (!init_map(map))
	{
		ft_memdel((void **)map);
		return (0);
	}
	i = 0;
	while (!backtracker(map, gofirst->first))
	{
		ft_freetab(map->map);
		map->width++;
		if (!init_map(map))
		{
			ft_memdel((void **)map);
			return (0);
		}
		i++;
	}
	return (map);
}
