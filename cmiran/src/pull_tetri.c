/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:07:42 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/06 17:27:56 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	get_x(const char *s, char c)
{
	size_t	x;

	x = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			x++;
			i = 0;
			while (*s != c && *s != '\n' && *s)
			{
				i++;
				s++;
			}
			if (i > x)
				x = i;
		}
	}
	return (x);
}

static size_t	get_y(const char *s, char c)
{
	size_t	y;

	y = 0;
	while (*s)
	{
		if (*s != c)
			s++;
		if (*s)
			y++;
		while (*s != c && *s)
			i++;
	}
	return (y);
}

static char		*pull_tetri(const char *s, char c, size_t *i)
{
	char	*str;
	size_t	x;
	size_t	j;

	x = get_x(s, c);
	if (!(str = (char *)malloc(sizeof(*str) * x + 1)))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j++] = s[*i];
		*i += 1;
	}
	str[j] = '\0';
	return (str);
}

char			**make_tab(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s || !c)
		return (NULL);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(*tab) * (get_y(s, c) + 1))))
		return (NULL);
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (!(tab[j++] = pull_tetri(s, c, &i)))
			{
				ft_memfree((void **)tab);
				return (NULL);
			}
	}
	tab[j] = NULL;
	return (tab);
}
