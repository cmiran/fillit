/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/09 23:58:28 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int	kill(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_control	*gofirst;
	t_map			*map;
	
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		exit(EXIT_FAILURE);
	}
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill());
	if (!(fd = open(argv[1], O_RDONLY)))
	 return (kill());
	if((gofirst->i = pull_list(fd, gofirst)) == 0)
		return (kill());
	if ((map = solve_map(gofirst)))
	{
		ft_puttab((const char **)map->map);
		exit(EXIT_SUCCESS);
	}
	return (kill());
}
