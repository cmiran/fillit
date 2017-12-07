/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/07 17:35:13 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	
	if (argc != 2 || !(list = pull_tetri(open(argv[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
