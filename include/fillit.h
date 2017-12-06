/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:47:41 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/06 17:41:48 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int	size;
	char	**tab;
}		t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}		s_list;

typedef struct	s_etris
{
	char	**pos;
	int	width;
	int	height;
	char	value;

}		t_etris;

#endif
