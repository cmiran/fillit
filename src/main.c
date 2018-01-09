/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/09 18:59:20 by cmiran           ###   ########.fr       */
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
	
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		exit(EXIT_FAILURE);
	}
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill());
	if (!(fd = open(argv[1], O_RDONLY)))
	 return (kill());
	if(!(pull_list(fd, gofirst)))
		return (kill());
//	print_list(gofirst);
	if (!solve_map(gofirst))
		return (kill());
	exit(EXIT_SUCCESS);
}
