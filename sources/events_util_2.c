/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_util_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:44:32 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 05:24:42 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	end(t_fractol *fr)
{
	ft_end(fr);
	return (0);
}

int	mouse_in_img(int x, int y)
{
	if (((WX - IX) / 2) + BORDE <= x && x <= WX - ((WX - IX) / 2) + BORDE
		&& (WY - IY) / 2 <= y && y <= WY - (WY - IY) / 2)
		return (1);
	return (0);
}

void	zoom_set(t_fractol *fr, int button)
{
	int	zoom;

	zoom = fr->zoom_f;
	if (zoom < 0)
		zoom *= -1;
	if (button == 4 && fr->iter >= fr->miniter)
	{
		if (fr->ctrl == 1 || fr->ctrl == 2)
			fr->iter = fr->iter + (int)ceil(fr->ite_f * zoom * 0.05);
		if (fr->ctrl == 3)
			fr->iter = fr->iter + (int)ceil(fr->ite_f * zoom * 0.001);
	}
	if (button == 5 && fr->iter > fr->miniter)
	{
		if (fr->ctrl == 1 || fr->ctrl == 2)
			fr->iter = fr->iter - (int)ceil(fr->ite_f * (zoom + 1) * 0.005);
		if (fr->ctrl == 3)
			fr->iter = fr->iter - (int)ceil(fr->ite_f * (zoom + 1) * 0.000005);
	}
}
