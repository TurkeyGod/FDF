/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getshit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:38:54 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/25 19:38:56 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		getmax_z(t_point *lst)
{
	int		hi_z;

	hi_z = lst->z;
	while (lst->next)
	{
		hi_z = (lst->next->z > hi_z) ? lst->next->z : hi_z;
		lst = lst->next;
	}
	return (hi_z);
}

int		getmin_z(t_point *lst)
{
	int		lowest_z;

	lowest_z = lst->z;
	while (lst->next)
	{
		lowest_z = (lst->next->z < lowest_z) ? lst->next->z : lowest_z;
		lst = lst->next;
	}
	return (lowest_z);
}
