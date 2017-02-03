/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:19:10 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/28 14:19:13 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	size_t			n;

	i = 0;
	j = 0;
	k = 0;
	n = size;
	while (dst[i] != '\0')
		i++;
	while (src[k] != '\0')
		k++;
	if (size <= i)
		return (k + size);
	size = size - i;
	while (src[j] != '\0' && (j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k + i);
}
