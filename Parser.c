/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:26:20 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/06 13:36:33 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		bloc_checker(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 4)
		{
			if (str[i + j] != '.' || str[i + j] != '#')
				return (0);
			j++;
		}
		if (str [i + j] != '\n')
			return (0);
		else
		{
			i += j + 1;
			j = 0;
		}
	}
	if (str[i + j] == '\n')
		return (1);
	return (0);
}

int		tetri_checker
{
	
}
