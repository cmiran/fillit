/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:35 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/13 02:36:50 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../include/libft.h"

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
		printf("#  id ->  %c		#\n", current->id);
		printf("#   X ->  ");
		while (i < 4)
			printf("%d  ", current->x[i++]);
		i = 0;
		printf("	#\n#   Y ->  ");
		while (i < 4)
			printf("%d  ", current->y[i++]);
		printf("	#\n");
		printf("#########################\n");
		current = current->next;
	}
}

int	kill(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_control	*gofirst;
	
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		exit(EXIT_FAILURE);
	}
	if (!(gofirst = ft_memalloc(sizeof(*gofirst))))
		return (kill());
	if (!(fd = open(argv[1], O_RDONLY)))
	 return (kill());
	if(!(pull_list(fd, gofirst)))
		return (kill());
	print_list(gofirst);
	return (0);
}
