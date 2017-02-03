/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:22:44 by mrobinso          #+#    #+#             */
/*   Updated: 2016/09/22 12:22:48 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	i = 0;
	s1cp = (unsigned char *)s1;
	s2cp = (unsigned char *)s2;
	while (s1cp[i] != '\0' && s2cp[i] != '\0' && s1cp[i] == s2cp[i])
		i++;
	return (s1cp[i] - s2cp[i]);
}
