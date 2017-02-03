/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:15:22 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/30 17:15:23 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	s1cp = (unsigned char*)s1;
	s2cp = (unsigned char*)s2;
	while (n--)
	{
		if (*s1cp != *s2cp)
			return (*s1cp - *s2cp);
		s1cp++;
		s2cp++;
	}
	return (0);
}
