/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:47:41 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/16 14:57:00 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef	struct	s_etris
{
	unsigned int	i;
	unsigned char	id;
	unsigned int	x[4];
	unsigned int	y[4];
	struct s_etris	*next;
}				t_etris;

typedef struct	s_var
{
	unsigned int	pos;
	unsigned int	x;
	unsigned int	y;
}				t_var;

typedef struct	s_map
{
	unsigned int	width;
	char			**map;
}				t_map;

int				pull_list(const int fd, t_etris *list,
		t_etris *tetri, t_etris *tmp);
void			write_tetri(const char *str, t_etris *tetri, char id);
t_map			*solve_map(t_etris *gofirst);
#endif
