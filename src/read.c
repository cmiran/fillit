/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/10 20:44:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

void	get_pos(const char *str, int *x, int *y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j] == '#')
			{
				*x++ = j;
				*y++ = k;
			}
			j++;
		}
		i += j + 1;
		k++;
	}
}

t_etris	write_tetri(const char *str, char id)
{
	t_etris	tetri;
	int	i;
	int	x[4];
	int	y[4];

	i = 0;
	get_pos(str, x, y);
	while (i < 4)
	{
		tetri.x[i] = x[i];
		tetri.y[i] = y[i];
		i++;
	}
	tetri.id = id;
	tetri.next = NULL;
	return (tetri);
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
				return (0);
			else if(str[i + j] == '#' && ++k > 4)
				return (0);
			j++;
		}
		if (str [i + j] != '\n')
			return (0);
		i += j + 1;
	}
	if (ret == 21 && str[i] != '\n')
		return (0);
	if (!(check_adja(str)))
		return (0);
	return (1);
}

int	pull_list(const int fd, t_etris *list)
{
	char		buf[22];
	int			ret;
	char		id;
	int			i;

	id = 'A';
	i = 0;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!(check_chunk(buf, ret)))
			return (1);
		list[i] = write_tetri(buf, id++);
		list->next = &list[i + 1];
		i++;
	}
	if (ret > 0)
		return (0);
	return (id - 'A');	
}
