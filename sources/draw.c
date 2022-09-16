/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 05:59:58 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 03:59:59 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	ft_draw_fractol(t_fractol *fr)
{
	int		ac;
	char	**ag;

	ac = fr->ac;
	ag = fr->ag;
	fr->matrix = init_pixel_matrix();
	if (fr->matrix == NULL)
		error_5(fr);
	fr->matrix = ft_fill_matrix(fr, fr->matrix);
	ft_set_draw(fr, ac, ag);
	screen_controls(fr);
	ft_read_and_print(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img,
		((WX - IX) / 2) + BORDE, (WY - IY) / 2);
	free_pixel_matrix(fr->matrix);
}

void	ft_set_draw(t_fractol *fr, int ac, char **ag)
{
	if (fr->ctrl == 1)
	{
		fr->matrix = calcul(fr, ft_mandelbrot, ac, ag);
		fr->matrix = color_m_j(fr, fr->matrix);
	}
	else if (fr->ctrl == 2)
	{
		fr->matrix = calcul(fr, ft_julia, ac, ag);
		fr->matrix = color_m_j(fr, fr->matrix);
	}
	else if (fr->ctrl == 3)
	{
		fr->matrix = calcul(fr, ft_newton, ac, ag);
		fr->matrix = color_n(fr, fr->matrix, ac);
	}
}

void	screen_controls(t_fractol *fr)
{
	char	*iter;
	char	*cota;

	mlx_clear_window(fr->mlx, fr->win);
	mlx_string_put(fr->mlx, fr->win, 95, 20, BLU + 0x505000, "PARAMETERS");
	mlx_string_put(fr->mlx, fr->win, 10, 45, WHT, "Iterations = ");
	iter = ft_itoa(fr->iter);
	if (iter == NULL)
		error_6(fr);
	mlx_string_put(fr->mlx, fr->win, 95, 45, WHT - 0x505000, iter);
	mlx_string_put(fr->mlx, fr->win, 10, 60, WHT, "Boundary = ");
	cota = ft_ftoa(fr->cota);
	if (cota == NULL)
		error_6s2(fr, iter);
	mlx_string_put(fr->mlx, fr->win, 95, 60, WHT - 0x505000, cota);
	if (fr->ctrl == 2 || fr->ctrl == 1)
		screen_mj(fr);
	limits_image(fr);
	guide_image(fr);
	free(iter);
	free(cota);
}

void	ft_read_and_print(t_fractol *fr)
{
	int	i;
	int	j;

	i = 0;
	while (i < IX)
	{
		j = IY - 1;
		while (j > 0)
		{
			my_mlx_pixel_put(fr, i, IY - j, fr->matrix[i][j].color);
			j--;
		}
	i++;
	}
}

t_pixel	**calcul(t_fractol *fr,
	t_pixel (*f)(t_fractol*, t_pixel, int, char**), int ac, char **ag)
{
	t_pixel	**res;
	int		i;
	int		j;

	i = 0;
	res = fr->matrix;
	while (i < IX)
	{
		j = 0;
		while (j < IY)
		{
			res[i][j] = f(fr, fr->matrix[i][j], ac, ag);
			j++;
		}
		i++;
	}
	return (res);
}
