/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/07 20:32:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

int		adja_check(const char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 20)
	{
		if (str[j] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				i++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				i++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				i++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				i++;
		}
		j++;
	}
	return (i == 6 || i == 8);
}

int		bloc_check(const char *str, const int ret)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j] != '.' || str[i + j] != '#')
				return (0);
			j++;
		}
		if (str [i + j] != '\n')
			return (0);
		else
			i += j + 1;
	}
	if (ret == 21 && str[20] != '\n')
			return (0);
	if (!(adja_check(str)))
		return (0);
	return (1);
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
