/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2018/01/19 06:31:55 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int		die(t_var *var)
{
	var->pos = 0;
	var->x = 0;
	var->y = 0;
	free(var);
	var = NULL;
	return (0);
}

/*
** Create the square that the algorithm will fill with tetriminos.
*/

int		init_map(t_map *map)
{
	unsigned int	i;

	if (!(map->map = (char **)malloc(sizeof(char *) * map->width + 1)))
	{
		ft_memdel((void **)&map);
		return (0);
	}
	i = -1;
	while (++i < map->width)
		if (!(map->map[i] = ft_strcnew(map->width, '.')))
		{
			ft_freetab(&map->map);
			return (0);
		}
	map->map[i] = NULL;
	return (1);
}

/*
** Place a piece in the matrix with the coodinates sent by backtracker.
*/

void	fill_map(t_map *pos, t_etris *curr, t_var *var, char c)
{
	int	i;

	i = -1;
	while (++i < 4)
		pos->map[var->y + curr->y[i]][var->x + curr->x[i]] = c;
}

/*
** Algorithm seaching if the spot exist, and if it is empty or full,
** for the current piece and the nexts. If somewhere false, return 0 to
** enlarge the map.
*/

int		backtracker(t_map *map, t_etris *curr)
{
	t_var	*var;
	int		i;

	if (curr == NULL)
		return (1);
	var = (t_var *)malloc(sizeof(t_var));
	var->pos = -1;
	while (++(var->pos) < map->width * map->width)
	{
		i = 0;
		var->x = var->pos % map->width;
		var->y = var->pos / map->width;
		while (i < 4 && var->y + curr->y[i] < map->width
				&& var->x + curr->x[i] < map->width
				&& map->map[var->y + curr->y[i]][var->x + curr->x[i]] == '.')
			i++;
		if (i == 4)
		{
			fill_map(map, curr, var, curr->id);
			if (backtracker(map, curr->next))
				return (1);
			fill_map(map, curr, var, '.');
		}
	}
	return (die(var));
}

/*
** Malloc the map and search for its lowest size.
*/

t_map	*solve_map(t_etris *gofirst)
{
	t_map	*map;

	if ((!(map = (t_map *)malloc(sizeof(t_map)))))
		return (0);
	map->width = 2;
	while ((map->width * map->width) < (gofirst->i) * 4)
		map->width++;
	if (!init_map(map))
		return (0);
	while (!backtracker(map, gofirst->next))
	{
		ft_freetab(&map->map);
		map->width++;
		if (!init_map(map))
			return (0);
	}
	return (map);
}
