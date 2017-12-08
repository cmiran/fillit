/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/08 19:29:41 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

size_t	**get_pos(const char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
	size_t 				pos[2][4];

	i = 0;
	k = 0;
	l = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j] == '#')
			{
				pos[0][k] = j;
				pos[1][k] = l;
				k++;
			}
			j++;
		}
		l++;
	}
	return (pos);
}

int	pull_bloc(const char *str, t_etris *list, char id)
{
	size_t	i;

	i = 0;
	pos = get_pos(str);

	return (0);
}

int	check_adja(const char *str)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				j++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				j++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				j++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				j++;
		}
		i++;
	}
	return (i == 6 || i == 8);
}

int	check_chunk(const char *str, const int ret)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j] != '.' || str[i + j] != '#')
				return (1);
			else if(str[i + j] == '#' && ++k > 4)
				return (1);
			j++;
		}
		if (str [i + j] != '\n')
			return (1);
		i += j + 1;
	}
	if (!(check_adja(str)))
		return (1);
	return (0);
}

int	pull_list(const int fd, t_etris *list)
{
	char		buf[22];
	int			ret;
	char		id;

	id = 'A';
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!(check_chunk(buf, ret)))
			return (1);

	}
	return (0);	
}
