/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 22:57:13 by mrobinso          #+#    #+#             */
/*   Updated: 2016/10/14 22:57:15 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	nlen;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = ft_intlen(n);
	if (!(new = (char *)malloc(sizeof(char) * nlen + 1)))
		return (NULL);
	neg = 1;
	if (n < 0)
	{
		n = -n;
		neg = -neg;
	}
	new[nlen] = '\0';
	while (--nlen > 0 && n > 9)
	{
		new[nlen] = (char)((n % 10) + '0');
		n = n / 10;
	}
	new[nlen] = (char)(n + '0');
	if (neg == -1)
		new[0] = '-';
	return (new);
}
