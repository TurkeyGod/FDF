/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:48:09 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/28 14:48:11 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_nuts	*reset(t_nuts *deez)
{
	deez->view_x = 32;
	deez->view_y = 18;
	deez->origin_x = 350;
	deez->origin_y = 190;
	deez->depth = 3;
	return (deez);
}

int		reset_and_draw(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez = reset(deez);
	create_art(deez);
	return (0);
}
