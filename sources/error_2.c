/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:13:32 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/16 20:05:02 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	error_5(t_fractol *fr)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	free(fr->ag);
	free(fr->pallete);
	free(fr);
	exit(1);
}

void	error_6(t_fractol *fr)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free_pixel_matrix(fr->matrix);
	free(fr->mlx);
	free(fr->ag);
	free(fr->pallete);
	free(fr);
	exit(1);
}

void	error_6s(t_fractol *fr, unsigned int *a)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free_pixel_matrix(fr->matrix);
	free(a);
	free(fr->mlx);
	free(fr->ag);
	free(fr->pallete);
	free(fr);
	exit(1);
}

void	error_6s2(t_fractol *fr, char *a)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_display(fr->mlx);
	free_pixel_matrix(fr->matrix);
	free(a);
	free(fr->mlx);
	free(fr->ag);
	free(fr->pallete);
	free(fr);
	exit(1);
}

int	error_7(void)
{
	ft_putstr_fd("Error: memory no allocated\n", 1);
	return (0);
}
