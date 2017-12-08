/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/08 16:39:49 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int	kill(void)
{
	ft_putendl("error");
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_etris	list[27];
	
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		return (1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	 return (kill());	
	if(!(pull_list(fd, list)))
		return (kill());
	return (0);
}
