/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:51:51 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/20 16:49:33 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

char	**init_map(char **map, unsigned int size)
{
	int	i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (map[i])
	{
		if (!(map[i] = ft_strcnew(size, '.')))
			return (0);
		i++;
	}
	return (map);
}
