/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_util_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:43:53 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 05:19:59 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	ft_mod_cota(int key, t_fractol *fr)
{
	if (key == K_FIV && fr->cota - fr->cot_f >= 0)
		fr->cota -= fr->cot_f;
	if (key == K_SIX)
		fr->cota += fr->cot_f;
}

void	ft_mod_inip(int key, t_fractol *fr)
{
	if (key == K_ONE)
		fr->ini_p.r -= fr->inp_f;
	if (key == K_TWO)
		fr->ini_p.r += fr->inp_f;
	if (key == K_TRE)
		fr->ini_p.i -= fr->inp_f;
	if (key == K_FOR)
		fr->ini_p.i += fr->inp_f;
}

void	ft_reinit(t_fractol *fr)
{
	if (fr->ctrl == 1)
		ft_init_mdbrot(fr);
	else if (fr->ctrl == 2)
		ft_init_julia(fr, fr->ag);
	else if (fr->ctrl == 3)
		ft_init_newton(fr);
}

void	zoom(int button, int x, int y, t_fractol *fr)
{
	double	x_rat;
	double	y_rat;

	x_rat = (double)(x - (2 * BORDE)) / IX;
	y_rat = (double)y / IY;
	if (button == 4 && mouse_in_img(x, y) == 1)
	{
		fr->min_x += (fr->step_x * 70) * x_rat;
		fr->max_x -= (fr->step_x * 70) * (1 - x_rat);
		fr->min_y += (fr->step_y * 70) * (1 - y_rat);
		fr->max_y -= (fr->step_y * 70) * y_rat;
		fr->zoom_f++;
	}
	else if (button == 5 && mouse_in_img(x, y) == 1)
	{
		fr->min_x -= (fr->step_x * 70) * x_rat;
		fr->max_x += (fr->step_x * 70) * (1 - x_rat);
		fr->min_y -= (fr->step_y * 70) * (1 - y_rat);
		fr->max_y += (fr->step_y * 70) * y_rat;
		fr->zoom_f--;
	}
	fr->step_x = (fr->max_x - fr->min_x) / (double)IX;
	fr->step_y = (fr->max_y - fr->min_y) / (double)IY;
	zoom_set(fr, button);
}

void	ch_color(int button, t_fractol *fr)
{
	if (button == 1)
		fr->col_ctr++;
	else if (button == 3)
		fr->col_ctr--;
	free(fr->pallete);
	if (fr->col_ctr == 0)
		fr->col_ctr = 3;
	fr->pallete = get_pal(fr->col_ctr);
}
