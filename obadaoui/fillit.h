/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:36:47 by obadaoui          #+#    #+#             */
/*   Updated: 2017/12/06 16:01:58 by obadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

typedef	struct	s_list
{
	int	bloc_number;
	int x;
	int y;
}				coord_list;

int		bloc_checker(char *str);

#endif
