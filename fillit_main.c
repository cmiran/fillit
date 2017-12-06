/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:44:30 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/06 14:28:06 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file");
		exit(EXIT_FAILURE);
	}
	open();
	if (!bloc_checker(argv[1]))
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
	if (solver())
	{
		printer;
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
