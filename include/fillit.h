/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:47:41 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/08 19:29:46 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRI 26

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_etris
{
	unsigned char	id;
	size_t		*x;
	size_t 		*y;
	struct s_etris	*next;

}		t_etris;
int		pull_list(const int fd, t_etris *list);
#endif
