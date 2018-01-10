/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:29:45 by cmiran            #+#    #+#             */
/*   Updated: 2018/01/10 15:16:48 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_list(t_control *gofirst)
{
	t_etris	*current;
	int			i;

	printf("#########################\n");
	printf("#  nbr tetriminos : %d  #\n", gofirst->i);
	printf("#########################\n");
	current = gofirst->first;
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
