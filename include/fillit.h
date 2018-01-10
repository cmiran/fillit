/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:47:41 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/10 12:33:46 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_etris
{
	unsigned char	id;
	unsigned int	x[4];
	unsigned int	y[4];
	struct s_etris	*next;
}		t_etris;

typedef struct	s_control
{
	unsigned int	i;
	struct s_etris	*first;
}		t_control;

typedef struct	s_map
{
	unsigned int	width;
	char		**map;
}		t_map;

int		pull_list(const int fd, t_control *list);
void		write_tetri(const char *str, t_etris *tetri, char id);
t_map		*solve_map(t_control *gofirst);
#endif
