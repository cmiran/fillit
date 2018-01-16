/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:29:45 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/16 12:25:35 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

void	print_list(t_etris *gofirst)
{
	t_etris	*current;
	int			i;

	printf("#########################\n");
	printf("#  nbr tetriminos : %d  #\n", gofirst->i);
	printf("#########################\n");
	current = gofirst->next;
	while (current != NULL)
	{
		i = 0;
		printf("#########################\n");
		printf("#  id  ->  %c		#\n", current->id);
		printf("#   X  ->  ");
		while (i < 4)
			printf("%d  ", current->x[i++]);
		i = 0;
		printf("	#\n#   Y  ->  ");
		while (i < 4)
			printf("%d  ", current->y[i++]);
		printf("	#\n");
		printf("#########################\n");
		current = current->next;
	}
}
