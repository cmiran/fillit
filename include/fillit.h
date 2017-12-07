/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:47:41 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/07 17:17:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_map
{
	int	size;
	char	**tab;
}		t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct	s_etris
{
	char	**pos;
	int	width;
	int	height;
	char	value;

}		t_etris;

#endif
