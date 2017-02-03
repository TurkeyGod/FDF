/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_thecrap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:31:05 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/23 13:31:06 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_x(t_nuts *deez, double cur, t_point *lst, t_point *p2)
{
	double	start;
	double	end;
	double	percent;

	if (lst->z == deez->min_z && p2->z == deez->min_z)
		return (WHITE);
	if (lst->z == deez->max_z && p2->z == deez->max_z)
		return (PURPLE);
	start = visual_x(deez, lst);
	end = visual_x(deez, p2);
	if (start == end)
		return (PURPLE);
	percent = (cur - start) / (end - start);
	return (percent * GREEN + (1 - percent) * PURPLE);
}

int		color_y(t_nuts *deez, double cur, t_point *lst, t_point *p2)
{
	double	start;
	double	end;
	double	percent;

	if (lst->z == 0 && p2->z == 0)
		return (WHITE);
	if (lst->z == deez->max_z && p2->z == deez->max_z)
		return (PURPLE);
	start = visual_y(deez, lst);
	end = visual_y(deez, p2);
	if (start == end)
		return (PURPLE);
	percent = (cur - start) / (end - start);
	return (percent * GREEN + (1 - percent) * PURPLE);
}

void	connect_vert(t_nuts *deez, t_point *lst, t_point *p2)
{
	double	x;
	double	y1;
	double	y2;

	x = visual_x(deez, lst);
	y1 = visual_y(deez, lst);
	y2 = visual_y(deez, p2);
	while (y1 != y2)
	{
		mlx_pixel_put(deez->mlx, deez->win, x, y1, color_y(deez, y1, lst, p2));
		++y1;
	}
	mlx_pixel_put(deez->mlx, deez->win, x, y1, color_y(deez, y1, lst, p2));
}

void	connect_x(t_nuts *deez, t_point *lst, t_point *p2)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	slope;

	x1 = visual_x(deez, lst);
	x2 = visual_x(deez, p2);
	y1 = visual_y(deez, lst);
	y2 = visual_y(deez, p2);
	slope = (y2 - y1) / (x2 - x1);
	while (x1 != x2)
	{
		mlx_pixel_put(deez->mlx, deez->win, x1, y1, color_x(deez, x1, lst, p2));
		y1 += slope;
		++x1;
	}
	mlx_pixel_put(deez->mlx, deez->win, x1, y1, color_x(deez, x1, lst, p2));
}

void	connect_y(t_nuts *deez, t_point *lst, t_point *p2)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	slope;

	x1 = visual_x(deez, lst);
	x2 = visual_x(deez, p2);
	y1 = visual_y(deez, lst);
	y2 = visual_y(deez, p2);
	slope = (x2 - x1) / (y2 - y1);
	while (y1 != y2)
	{
		mlx_pixel_put(deez->mlx, deez->win, x1, y1, color_y(deez, y1, lst, p2));
		x1 += slope;
		++y1;
	}
	mlx_pixel_put(deez->mlx, deez->win, x1, y1, color_y(deez, y1, lst, p2));
}
