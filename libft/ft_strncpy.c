/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:28:48 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/30 17:28:50 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	while (len > 0 && *src != '\0')
	{
		*s++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*s++ = '\0';
		--len;
	}
	return (dst);
}
