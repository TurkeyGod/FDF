/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:20:23 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/15 21:20:25 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	visual_x(t_nuts *deez, t_point *lst)
{
	if (!deez)
		return (0);
	return ((double)(lst->x - lst->y) * deez->view_x + deez->origin_x);
}

double	visual_y(t_nuts *deez, t_point *lst)
{
	int		x;
	int		y;
	int		z;

	x = lst->x;
	y = lst->y;
	z = lst->z;
	if (!deez)
		return (0);
	return ((double)(x + y) * deez->view_y + deez->origin_y - z * deez->depth);
}

void	draw_line(t_nuts *deez, t_point *lst, t_point *point2)
{
	if (!lst || !point2)
		return ;
	if (visual_x(deez, lst) == visual_x(deez, point2))
	{
		if (visual_y(deez, point2) > visual_y(deez, lst))
			connect_vert(deez, lst, point2);
		else
			connect_vert(deez, point2, lst);
	}
	else
	{
		if (visual_x(deez, point2) > visual_x(deez, lst))
			connect_x(deez, lst, point2);
		else
			connect_x(deez, point2, lst);
		if (visual_y(deez, point2) > visual_y(deez, lst))
			connect_y(deez, lst, point2);
		else
			connect_y(deez, point2, lst);
	}
}
