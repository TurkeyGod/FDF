/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:01:38 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/30 17:01:40 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	c2;
	int		i;

	i = 0;
	c2 = (char)c;
	p = (char *)s;
	while (n--)
	{
		if (p[i] == c2)
			return (p + i);
		i++;
	}
	return (NULL);
}
