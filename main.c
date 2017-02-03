/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:19:12 by mrobinso          #+#    #+#             */
/*   Updated: 2016/12/08 14:19:14 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	remove_last(t_point *lst)
{
	while (lst)
	{
		if (lst->next && lst->next->next == NULL)
		{
			free(lst->next);
			lst->next = NULL;
			return ;
		}
		lst = lst->next;
	}
}

t_point	*store_coordinate(t_point *lst, int z, int y, int x)
{
	lst->x = x;
	lst->y = y;
	lst->z = z;
	lst->next = (t_point *)malloc(sizeof(t_point));
	if (!lst)
		return (NULL);
	return (lst->next);
}

t_point	*read_file(int fd, int x)
{
	char	*buf;
	t_point	*lst;
	t_point	*lst_copy;
	char	**split_array;
	int		row;

	row = 0;
	lst = (t_point *)malloc(sizeof(t_point));
	if (!lst)
		return (NULL);
	lst_copy = lst;
	while (get_next_line(fd, &buf) != 0)
	{
		split_array = ft_split(buf);
		x = 0;
		while (split_array[x])
		{
			lst = store_coordinate(lst, ft_atoi(split_array[x]), row, x);
			++x;
		}
		++row;
		free(buf);
	}
	remove_last(lst_copy);
	return (lst_copy);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_point	*lst;

	if (argc != 2)
		ft_putstr("usage: ./fdf file_name");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() error");
			return (1);
		}
		lst = read_file(fd, 0);
		window_init(lst);
		fd = close(fd);
		if (fd == -1)
		{
			ft_putstr("close() error");
			return (1);
		}
	}
	return (0);
}
