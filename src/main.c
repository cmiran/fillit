/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/22 15:04:11 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	ultra_kill(char *str, t_etris *list, int fd)
{
	t_etris	*tmp;

	ft_putendl(str);
	close(fd);
	if (!list)
		exit(EXIT_FAILURE);
	while (list->next != NULL)
	{
		tmp = list;
		tmp->i = 0;
		tmp->id = 0;
		ft_bzero(tmp->x, 4);
		ft_bzero(tmp->y, 4);
		list = tmp->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&list);
	exit(EXIT_FAILURE);
}

int	success(t_etris *list, t_map *map, int fd)
{
	t_etris *tmp;

	close(fd);
	while (list->next != NULL)
	{
		tmp = list;
		tmp->i = 0;
		tmp->id = 0;
		ft_bzero(tmp->x, 4);
		ft_bzero(tmp->y, 4);
		list = tmp->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&list);
	map->width = 0;
	ft_freetab(&map->map);
	ft_memdel((void **)&map);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_etris	*gofirst;
	t_etris	*tetri;
	t_etris	*tmp;
	t_map	*map;

	if (argc != 2)
		kill("usage: ./fillit [input_file.fillit]");
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill("error"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ultra_kill("error", gofirst, fd));
	tetri = NULL;
	tmp = gofirst;
	if ((gofirst->i = pull_list(fd, gofirst, tetri, tmp)) < 1)
		return (ultra_kill("error", gofirst, fd));
	if ((map = solve_map(gofirst)))
	{
		ft_puttab((const char **)map->map);
		return (success(gofirst, map, fd));
	}
	return (ultra_kill("error", gofirst, fd));
}
