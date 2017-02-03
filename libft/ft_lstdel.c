/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:04:05 by mrobinso          #+#    #+#             */
/*   Updated: 2016/10/18 17:04:07 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *link;
	t_list *nxt;

	if (!alst || !*alst || !del)
		return ;
	link = *alst;
	while (link)
	{
		nxt = link->next;
		del(link->content, link->content_size);
		free(link);
		link = nxt;
	}
	*alst = NULL;
}
