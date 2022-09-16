/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 05:34:14 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/08 19:20:17 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	error_0(t_fractol *fr)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	free(fr);
	exit(1);
}

void	error_1(t_fractol *fr)
{
	ft_putstr_fd("Error: init mlx\n", 1);
	free(fr->ag);
	free(fr);
	exit(1);
}

void	error_2(t_fractol *fr)
{
	ft_putstr_fd("Error: init mlx window\n", 1);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	free(fr->ag);
	free(fr);
	exit(1);
}

void	error_3(t_fractol *fr)
{
	ft_putstr_fd("Error: init mlx image\n", 1);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	free(fr->ag);
	free(fr);
	exit(1);
}

void	error_4(t_fractol *fr)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	free(fr->ag);
	free(fr);
	exit(1);
}
