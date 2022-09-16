/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:30:51 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:14:45 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	screen_mj(t_fractol *fr)
{
	char	*re;
	char	*im;

	re = ft_ftoa(fr->ini_p.r);
	im = ft_ftoa(fr->ini_p.i);
	if (re != NULL && im != NULL)
	{
		mlx_string_put(fr->mlx, fr->win, 10, 75, WHT, "Init point(r) = ");
		mlx_string_put(fr->mlx, fr->win, 112, 75, WHT - 0x505000, re);
		mlx_string_put(fr->mlx, fr->win, 10, 90, WHT, "Init point(i) = ");
		mlx_string_put(fr->mlx, fr->win, 112, 90, WHT - 0x505000, im);
		free_scr_arg(re, im);
	}
	else
		free_scr_arg(re, im);
}

void	limits_image(t_fractol *fr)
{
	char	*minx;
	char	*maxx;
	char	*miny;
	char	*maxy;

	minx = ft_ftoa(fr->min_x);
	maxx = ft_ftoa(fr->max_x);
	miny = ft_ftoa(fr->min_y);
	maxy = ft_ftoa(fr->max_y);
	if (minx && miny && maxx && maxy)
	{
		mlx_string_put(fr->mlx, fr->win, 40, 280, WHT, "Min x = ");
		mlx_string_put(fr->mlx, fr->win, 42, 295, WHT - 0x505000, minx);
		mlx_string_put(fr->mlx, fr->win, 155, 280, WHT, "Max x = ");
		mlx_string_put(fr->mlx, fr->win, 157, 295, WHT - 0x505000, maxx);
		mlx_string_put(fr->mlx, fr->win, 96, 320, WHT, "Min y = ");
		mlx_string_put(fr->mlx, fr->win, 98, 335, WHT - 0x505000, miny);
		mlx_string_put(fr->mlx, fr->win, 96, 240, WHT, "Max y = ");
		mlx_string_put(fr->mlx, fr->win, 98, 255, WHT - 0x505000, maxy);
		free_lim_arg(minx, maxx, miny, maxy);
	}
	else
		free_lim_arg(minx, maxx, miny, maxy);
}

void	guide_image(t_fractol *fr)
{
	mlx_string_put(fr->mlx, fr->win, 96, 520, BLU + 0x505000, "CONTROLS");
	mlx_string_put(fr->mlx, fr->win, 26, 540, WHT, "Move image");
	mlx_string_put(fr->mlx, fr->win, 25, 555, WHT, "Iterations");
	mlx_string_put(fr->mlx, fr->win, 10, 570, WHT, "Init point(real)");
	mlx_string_put(fr->mlx, fr->win, 10, 585, WHT, "Init point(imag)");
	mlx_string_put(fr->mlx, fr->win, 26, 600, WHT, "Boundary");
	mlx_string_put(fr->mlx, fr->win, 35, 615, WHT, "Reset");
	mlx_string_put(fr->mlx, fr->win, 37, 630, WHT, "Zoom");
	mlx_string_put(fr->mlx, fr->win, 37, 645, WHT, "Color");
	mlx_string_put(fr->mlx, fr->win, 180, 540, WHT - 0x505000, "Arrows");
	mlx_string_put(fr->mlx, fr->win, 180, 555, WHT - 0x505000, "-/+");
	mlx_string_put(fr->mlx, fr->win, 180, 570, WHT - 0x505000, "F1/F2");
	mlx_string_put(fr->mlx, fr->win, 180, 585, WHT - 0x505000, "F3/F4");
	mlx_string_put(fr->mlx, fr->win, 180, 600, WHT - 0x505000, "F5/F6");
	mlx_string_put(fr->mlx, fr->win, 180, 615, WHT - 0x505000, "Space");
	mlx_string_put(fr->mlx, fr->win, 180, 630, WHT - 0x505000, "Scroll");
	mlx_string_put(fr->mlx, fr->win, 160, 645, WHT - 0x505000, "Mouse buttons");
}

void	my_mlx_pixel_put(t_fractol *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->adr + (y * fr->llen + x * (fr->bpp / 8));
	*(unsigned int *)dst = color;
}
