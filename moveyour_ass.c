/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveyour_ass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:47:33 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/27 14:47:35 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		move_up(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->origin_y -= 10;
	create_art(deez);
	return (0);
}

int		move_right(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->origin_x += 10;
	create_art(deez);
	return (0);
}

int		move_down(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->origin_y += 10;
	create_art(deez);
	return (0);
}

int		move_left(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->origin_x -= 10;
	create_art(deez);
	return (0);
}
