/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:59:54 by mrobinso          #+#    #+#             */
/*   Updated: 2016/11/10 14:59:59 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999

typedef struct	s_gnl
{
	char	*buf;
	int		count;
	int		i;
	int		nl;
	int		fd;
}				t_gnl;
int				get_next_line(const int fd, char **line);
#endif
