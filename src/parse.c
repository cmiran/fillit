/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/17 17:03:18 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Check if each '#' is adjacent to another.
** If there is 6 or 8 connections, the tetrimino is valid.
*/

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

/*
** Check the buf from read. For each chunk must contains a 4 * 5 bloc,
** with only 21 char : '.', five '\n' & four '#'.
*/

int	check_chunk(const char *str, const int ret, int *t)
{
	int	i;
	int	j;
	int	k;

	if (ret == 20)
		*t = 1;
	i = 0;
	k = 0;
	while (i < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i + j] != '.' && str[i + j] != '#')
				return (0);
			else if (str[i + j] == '#' && ++k > 4)
				return (0);
		}
		if (str[i + j] != '\n')
			return (0);
		i += j + 1;
	}
	if ((ret == 21 && str[i] != '\n') || !check_adja(str))
		return (0);
	return (1);
}

/*
** Assuming the input is valid, malloc a s_etris for each tetrimino,
** in a linked list.
*/

int	pull_list(const int fd, t_etris *gofirst, t_etris *tetri, t_etris *tmp)
{
	char		id;
	int			ret;
	char		buf[16];
	int			t;

	while ((ret = read(fd, buf, 21)) > 19)
	{
		if (!(check_chunk(buf, ret, &t)))
			return (0);
		if (!id && (tetri = ft_memalloc(sizeof(*tetri))))
		{
			write_tetri(buf, tetri, (id = 'A'));
			gofirst->next = tetri;
		}
		else if ((tetri = ft_memalloc(sizeof(*tetri))))
		{
			write_tetri(buf, tetri, ++id);
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = tetri;
		}
	}
	if (ret != 0 || t != 1)
		return (0);
	return (id - 'A');
}
