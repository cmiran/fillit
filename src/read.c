/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/08 13:24:45 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int		adja_check(const char *str)
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

int		bloc_check(const char *str, const int ret)
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
			else if(str[i + j] == '#' && ++k != 4)
				return (1);
			j++;
		}
		if (str [i + j] != '\n')
			return (1);
		i += j + 1;
	}
	if (ret == 21 && str[20] != '\n')
			return (1);
	if (!(adja_check(str)))
		return (1);
	return (0);
}

t_list	pull_tetri(const int fd)
{
	char		buf[22];
	t_list	list;
	int			ret;

	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!(bloc_check(buf, ret)))
		
	}
	return (list);	
}
