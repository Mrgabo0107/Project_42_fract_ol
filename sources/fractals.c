/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:21:39 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:33:42 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_pixel	ft_mandelbrot(t_fractol *fr, t_pixel p, int ac, char **ag)
{
	t_pixel		res;
	t_complex	temp;
	double		*coef;
	int			i;
	int			n_coef;

	i = 0;
	res = p;
	coef = get_coef(ac, ag);
	n_coef = ac - 2;
	if (ac < 3)
		n_coef = 2;
	temp = fr->ini_p;
	while (i < fr->iter && ft_cnorm_t_sqr(temp) < pow(fr->cota, 2))
	{
		temp = ft_csum(ft_poly_nc(temp, coef, n_coef), res.c);
		i++;
	}
	free(coef);
	res.c_ctrl = i;
	return (res);
}

t_pixel	ft_julia(t_fractol *fr, t_pixel p, int ac, char **ag)
{
	t_pixel		res;
	t_complex	temp;
	double		*coef;
	int			i;
	int			n_coef;

	i = 0;
	res = p;
	coef = get_coef(ac, ag);
	n_coef = ac - 3;
	if (ac < 4)
		n_coef = 2;
	temp = res.c;
	while (i < fr->iter && ft_cnorm_t_sqr(temp) < pow(fr->cota, 2))
	{
		temp = ft_csum(ft_poly_nc(temp, coef, n_coef), fr->ini_p);
		i++;
	}
	free(coef);
	res.c_ctrl = i;
	return (res);
}

t_pixel	ft_newton(t_fractol *fr, t_pixel p, int ac, char **ag)
{
	t_pixel		res;
	t_complex	temp;
	t_complex	*roots;
	int			i;
	int			n_root;

	i = 0;
	res = p;
	roots = get_cplx_cf(ac, ag);
	n_root = ac - 2;
	if (ac < 3)
		n_root = 3;
	temp = res.c;
	while (i < fr->iter)
	{
		temp = ft_crest(temp, ft_cdiv(ft_mono_mult(temp,
						roots, n_root), ft_deriv_mono(temp, roots, n_root)));
		i++;
	}
	res.c_ctrl = ft_asign_root(fr, temp, n_root, roots);
	free(roots);
	return (res);
}
