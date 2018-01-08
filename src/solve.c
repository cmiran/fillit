/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:28:01 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/31 11:58:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

/*
** Create the square that our algorithm will fill with tetriminos.
*/

int	init_map(t_map *map)
{
	int	i;

	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * map->width)))
		return (0);
	while (map->map[i])
	{
		if (!(map->map[i] = ft_strcnew(map->width, '.')))
		{
			ft_freetab(map->map);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** Fonction that put a tetrimino in the square at the position that
** have been sent by the backtracker.
*/

void	fill_map(t_map *pos, t_etris *curr, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		pos->map[x + curr->x[i]][y + curr->y[i]] = curr->id;
		i++;
	}
	//curr = curr->next;
}
/*
int		check_pos(t_map *pos, t_etris *curr)
{
	int	i;
	int	x;
	int	y;
	
	if (curr = NULL)
		return (1);
	y = 0;
	while (pos->map[y + curr->y[i]])
	{
		x = 0;
		i = 0;
		while (pos->map[y + curr->y[i]][x + curr->x[i]] &&
			pos->map[y + curr->y[i]][x + curr->x[i]] == '.')
		{
			i++;
			if (i == 4)
				fill_map(pos, curr, x, y);

}
*/
/*
** Backtracking algorithm that call himself back to continue the filling
** or to go back and find another solution.
*/

int		backtracker(t_map *pos, t_etris *curr, int x, int y)
{
	int	i;

	ft_putendl("4.1.1");
	if (curr == NULL)
		return (1);
	i = 0;
	ft_putendl("4.1.2");
	while (pos->map[y + curr->y[i]][x + curr->x[i]] &&
			pos->map[y + curr->y[i]][x + curr->x[i]] == '.' && i < 4)
	{
		i++;
		ft_putendl("4.1.2.1");
	}
	ft_putendl("4.1.3");
	if (i == 4)
	{
		ft_putendl("4.1.3.1");
		fill_map(pos, curr, x, y);
		ft_putendl("4.1.3.2");
		return (backtracker(pos, curr->next, x++, y));
	}
	ft_putendl("4.1.4");
	if (pos->map[y][x] == '\0')
	{
		ft_putendl("4.1.4.1");
		return (backtracker(pos, curr, x = 0, y++));
	}
	else if (!pos->map[y])
	{
		ft_putendl("4.1.5.1");
		return (0);
	}
	ft_putendl("4.1.6");
	return (backtracker(pos, curr, x++, y) || (0));
}

/*
** Main fonction that call others fonctions to create the solution square,
** fill it, and checks if everything's fine.
*/

int		solve(t_control *gofirst)
{
	t_map	*map;
	int		x;
	int		y;

	ft_putendl("1");
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->width = 2;
	ft_putendl("2");
	while ((map->width * map->width) < (gofirst->i) * 4)
	{
		printf("width = %d\n", map->width);
		ft_putendl("2.1");
		map->width++;
		printf("width = %d\n", map->width);
	}
	ft_putendl("3");
	if (!init_map(map))
	{
		ft_putendl("3.1");
		ft_memdel((void **)map);
		return (0);
	}
	ft_putendl("4");
	while (!backtracker(map, gofirst->first, x = 0, y = 0))
	{
		ft_putendl("4.1");
		ft_freetab(map->map);
		map->width++;
		ft_putendl("4.2");
		printf("width = %d\n", map->width);
		if (!init_map(map))
		{
			ft_memdel((void **)map);
			return (0);
		}
		ft_putendl("4.3");
	}
	ft_puttab((const char **)map->map);
	return (1);
}
