/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:45:23 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/28 14:45:25 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_up(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->view_x += 1;
	deez->view_y -= 1;
	create_art(deez);
	return (0);
}

int	rotate_right(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->view_x -= 1;
	deez->view_y -= 1;
	create_art(deez);
	return (0);
}

int	rotate_left(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->view_x += 1;
	deez->view_y += 1;
	create_art(deez);
	return (0);
}

int	rotate_down(t_nuts *deez)
{
	mlx_clear_window(deez->mlx, deez->win);
	deez->view_x -= 1;
	deez->view_y += 1;
	create_art(deez);
	return (0);
}
