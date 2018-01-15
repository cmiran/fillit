int	pull_list(const int fd, t_control *gofirst)
{
	char	id;
	int		ret;
	char	buf[22];
	t_etris	*tetri;
	t_etris	*tmp;

	id = 'A';
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!(check_chunk(buf, ret)))
			return (0);
		if (id == 'A' && (tetri = ft_memalloc(sizeof(*tetri))))
		{
			write_tetri(buf, tetri, id++);
			gofirst->first = tetri;
			tmp = gofisrt;
		}
		else if ((tetri = ft_memalloc(sizeof(*new))))
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = tetri;
		}
	}
}
