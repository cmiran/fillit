/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/10 19:55:58 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	kill(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_control	*gofirst;
	t_map			*map;

	if (argc != 2)
		kill("usage: ./fillit [input_file.fillit]");
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill("error: a memory allocation failed"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	 return (kill("error: failed to open file"));
	if((gofirst->i = pull_list(fd, gofirst)) < 1)
		return (kill("error: empty file"));
	close(fd);
	if ((map = solve_map(gofirst)))
	{
		ft_puttab((const char **)map->map);
//		ft_lstdel(gofirst,);
//		ft_lstdelone(map, );
		exit(EXIT_SUCCESS);
	}
	return (kill("error: crash"));
}
