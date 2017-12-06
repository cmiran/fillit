/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:01:19 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/06 16:08:02 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	(void)argc;
	if (bloc_checker(argv[1]))
		printf("Blocs OK.\n");
	else
		printf("Blocs KO.\n");
}
