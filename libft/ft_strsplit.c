/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:04:44 by mrobinso          #+#    #+#             */
/*   Updated: 2016/10/14 19:04:45 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsub(const char *s, char c)
{
	int	count;
	int	isub;

	isub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (isub == 1 && *s == c)
			isub = 0;
		if (isub == 0 && *s != c)
		{
			isub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int		ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countsub(s, c);
	array = (char **)malloc(sizeof(*array) * (words + 1));
	if (array == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (array[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
