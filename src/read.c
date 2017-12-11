/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/11 17:56:15 by cmiran           ###   ########.fr       */
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

void	write_tetri(const char *str, t_etris *tetri, char id)
{
	int	i;
	int	x[4];
	int	y[4];
//	t_etris	*tetri;

	i = 0;
//	tetri = NULL;
	get_pos(str, x, y);
	while (i < 4)
	{
		tetri->x[i] = x[i];
		tetri->y[i] = y[i];
		i++;
	}
	tetri->id = id;
	tetri->next = NULL;
//	return (tetri);
}

int	check_adja(const char *str)
{
	int i;
	int j;

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
	return (j == 6 || j == 8);
}

int	check_chunk(const char *str, const int ret)
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
			if (str[i + j] != '.' && str[i + j] != '#')
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
	if (!check_adja(str))
		return (0);
	return (1);
}

int	pull_list(const int fd, t_control *gofirst)
{
	char		id;
	int			ret;
	char		buf[22];
	t_etris	*tetri;
	t_etris *new;

	id = 'A';
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		printf("1.1\n");
		if (!(check_chunk(buf, ret)))
			return (0);
//		if (!(tetri = ft_memalloc(sizeof(*tetri))))
//		{
//			printf("1.2\n");
//			return (0);
//		}
		printf("1.3\n");
		if (id == 'A')
		{
			printf("1.4\n");
			if(!(tetri = ft_memalloc(sizeof(*tetri))))
				return (0);
//			tetri = write_tetri(buf, id++);
			write_tetri(buf, tetri, id++);
			printf("1.5\n");
			gofirst->first = tetri;
			printf("1.6\n");
		}	
		else
		{
			printf("1.7\n");
			if(!(new = ft_memalloc(sizeof(*tetri))))
				return (0);
			write_tetri(buf, new, id++);
			new->next = gofirst->first;
			gofirst->first = new;
			printf("1.8\n");
//			if(!(tetri = ft_memalloc(sizeof(*tetri))))
//			return (0);
		}
	}
	gofirst->i = id - 'A';
	if (ret != 0)
		return (0);
	return (id - 'A');	
}
