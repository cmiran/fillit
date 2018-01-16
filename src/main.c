/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/16 15:25:27 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"
/*
void	free_tetri(t_etris *tetri)
{
	tetri->i = 0;
	tetri->id = 0;
	ft_bzero(tetri->x, sizeof(tetri->x));
	ft_memdel((void *)&tetri->x);
	ft_bzero(tetri->y, sizeof(tetri->y));
	ft_memdel((void *)&tetri->y);
}
*/
int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_etris	*gofirst;
	t_etris	*tetri;
	t_etris	*tmp;
	t_map		*map;

	if (argc != 2)
		kill("usage: ./fillit [input_file.fillit]");
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill("error"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (kill("error"));
	tetri = NULL;
	tmp = gofirst;
	if ((gofirst->i = pull_list(fd, gofirst, tetri, tmp)) < 1)
		return (kill("error"));
	close(fd);
	if ((map = solve_map(gofirst)))
	{
		ft_puttab((const char **)map->map);
//		ft_lstdel((void *)&gofirst, );
//		ft_lstdelone((void *)&map, );
		exit(EXIT_SUCCESS);
	}
	return (kill("error"));
}
