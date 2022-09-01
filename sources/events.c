/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:23:55 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 05:13:01 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	key_press(int key, t_fractol *fr)
{
	if (key == K_ESC)
		ft_end(fr);
	else if (K_LFT <= key && key <= K_DWN)
		ft_arr_mov(key, fr);
	else if (key == K_INC || key == K_DCR)
		ft_mod_iter(key, fr);
	else if (key == K_FIV || key == K_SIX)
		ft_mod_cota(key, fr);
	else if (key >= K_ONE && key <= K_FOR)
		ft_mod_inip(key, fr);
	else if (key == 32)
		ft_reinit(fr);
	else
		return (0);
	ft_draw_fractol(fr);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *fr)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, fr);
	else if ((button == 1 || button == 3) && mouse_in_img(x, y) == 1)
		ch_color(button, fr);
	else
		return (0);
	ft_draw_fractol(fr);
	return (0);
}

void	ft_end(t_fractol *fr)
{
	mlx_clear_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	free(fr->pallete);
	free(fr->ag);
	free(fr);
	exit(0);
}

void	ft_arr_mov(int key, t_fractol *fr)
{
	if (key == K_LFT)
	{
		fr->min_x -= fr->step_x * 25;
		fr->max_x -= fr->step_x * 25;
	}
	if (key == K_RGT)
	{
		fr->min_x += fr->step_x * 25;
		fr->max_x += fr->step_x * 25;
	}
	if (key == K_DWN)
	{
		fr->min_y -= fr->step_y * 25;
		fr->max_y -= fr->step_y * 25;
	}
	if (key == K_UP)
	{
		fr->min_y += fr->step_y * 25;
		fr->max_y += fr->step_y * 25;
	}
	fr->step_x = (fr->max_x - fr->min_x) / (double)IX;
	fr->step_y = (fr->max_y - fr->min_y) / (double)IY;
}

void	ft_mod_iter(int key, t_fractol *fr)
{
	int	i;

	i = ten_pow(fr->iter);
	if (fr->ctrl == 3)
		i = 1;
	if (key == K_INC)
		fr->iter += i * fr->ite_f;
	if (key == K_DCR && fr->iter > fr->miniter)
	{
		if (fr->iter - (i * fr->ite_f) >= fr->miniter)
			fr->iter -= i * fr->ite_f;
		else
		{
			while (fr->iter - (i * fr->ite_f) < fr->miniter && i > 0)
				i /= 10;
			fr->iter -= i * fr->ite_f;
		}
	}
}
