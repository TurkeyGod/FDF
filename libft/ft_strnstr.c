/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:53:16 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/26 22:53:18 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char*)big);
	i = 0;
	while (*big && len)
	{
		if (*big == little[i])
			i++;
		else
		{
			big = big - i;
			len = len + i;
			i = 0;
		}
		if (little[i] == '\0')
			return ((char*)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
