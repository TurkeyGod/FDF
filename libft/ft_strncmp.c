/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:20:41 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/24 17:20:42 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	s1cp = (unsigned char*)s1;
	s2cp = (unsigned char*)s2;
	while (n > 0)
	{
		if (*s1cp != *s2cp)
		{
			return (*s1cp - *s2cp);
		}
		else if (*s1cp == '\0')
			return (0);
		s1cp++;
		s2cp++;
		n--;
	}
	return (0);
}
