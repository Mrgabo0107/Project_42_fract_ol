/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 05:58:31 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 03:49:56 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	ft_init_fractol(t_fractol *fr, int ctrl, int argc, char **argv)
{
	fr->ac = argc;
	fr->ag = ft_get_coef(argc, argv);
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, WX, WY, "fract'ol");
	fr->img = mlx_new_image(fr->mlx, IX, IY);
	fr->adr = mlx_get_data_addr(fr->img, &fr->bpp, &fr->llen, &fr->endi);
	fr->ctrl = ctrl;
	if (ctrl == 1)
		ft_init_mdbrot(fr);
	else if (ctrl == 2)
		ft_init_julia(fr, fr->ag);
	else if (ctrl == 3)
		ft_init_newton(fr);
}

char	**ft_get_coef(int argc, char **argv)
{
	char	**ag;
	int		i;

	i = 0;
	ag = (char **)malloc(sizeof(char *) * argc);
	if (!ag)
		return (NULL);
	while (i < argc)
	{
		ag[i] = argv[i];
		i++;
	}
	return (ag);
}

void	ft_init_mdbrot(t_fractol *fr)
{
	fr->col_ctr = 1;
	fr->pallete = get_pal(fr->col_ctr);
	fr->iter = 70;
	fr->miniter = 30;
	fr->min_x = -2;
	fr->max_x = 2;
	fr->min_y = -2;
	fr->max_y = 2;
	fr->step_x = (fr->max_x - fr->min_x) / (double)IX;
	fr->step_y = (fr->max_y - fr->min_y) / (double)IY;
	fr->ite_f = 2;
	fr->cot_f = 0.15;
	fr->inp_f = 0.2;
	fr->cota = 2;
	fr->zoom_f = 0;
	fr->ini_p = ft_get_complex("0.0+0.0i");
}

void	ft_init_julia(t_fractol *fr, char **ag)
{
	fr->col_ctr = 1;
	fr->pallete = get_pal(fr->col_ctr);
	fr->iter = 60;
	fr->miniter = 30;
	fr->min_x = -2;
	fr->max_x = 2;
	fr->min_y = -2;
	fr->max_y = 2;
	fr->step_x = (fr->max_x - fr->min_x) / (double)IX;
	fr->step_y = (fr->max_y - fr->min_y) / (double)IY;
	fr->ite_f = 2;
	fr->cot_f = 0.15;
	fr->inp_f = 0.02;
	fr->cota = 2;
	fr->zoom_f = 0;
	fr->ini_p = ft_get_complex(ag[2]);
}

void	ft_init_newton(t_fractol *fr)
{
	fr->col_ctr = 2;
	fr->pallete = get_pal(fr->col_ctr);
	fr->iter = 17;
	fr->miniter = 4;
	fr->min_x = -4;
	fr->max_x = 4;
	fr->min_y = -4;
	fr->max_y = 4;
	fr->step_x = (fr->max_x - fr->min_x) / (double)IX;
	fr->step_y = (fr->max_y - fr->min_y) / (double)IY;
	fr->ite_f = 1;
	fr->cot_f = 0.02;
	fr->cota = 1.5;
	fr->zoom_f = 0;
}
