/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_compl_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 04:09:21 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/15 15:21:21 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_complex	ft_cdiv(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.r = ((c1.r * c2.r) + (c1.i * c2.i)) / (pow(c2.r, 2) + pow(c2.i, 2));
	res.i = ((c1.i * c2.r) - (c1.r * c2.i)) / (pow(c2.r, 2) + pow(c2.i, 2));
	return (res);
}

t_complex	ft_cpow(t_complex bas, int pow)
{
	t_complex	res;
	int			i;

	res.r = 1;
	res.i = 0;
	i = 0;
	while (i < pow)
	{
		res = ft_cmult(res, bas);
		i++;
	}
	return (res);
}

t_complex	ft_poly_nc(t_complex c, double *coef, int numc)
{
	t_complex	res;
	int			i;

	i = 0;
	res.r = 0;
	res.i = 0;
	while (i < numc)
	{
		res = ft_csum(res, ft_scale_by(coef[i], ft_cpow(c, i + 1)));
		i++;
	}
	return (res);
}

t_complex	ft_mono_mult(t_complex c, t_complex *root, int numr)
{
	t_complex	res;
	int			i;

	i = 0;
	res.r = 1;
	res.i = 1;
	while (i < numr)
	{
		res = ft_cmult(res, ft_crest(c, root[i]));
		i++;
	}
	return (res);
}

t_complex	ft_deriv_mono(t_complex c, t_complex *root, int numr)
{
	t_complex	res;
	t_complex	temp;
	int			i;
	int			j;

	i = 0;
	res.r = 0;
	res.i = 0;
	temp.r = 1;
	temp.i = 1;
	while (i < numr)
	{
		j = 0;
		temp.r = 1;
		temp.i = 1;
		while (j < numr)
		{
			if (j != i)
				temp = ft_cmult(temp, ft_crest(c, root[i]));
			j++;
		}
		res = ft_csum(res, temp);
		i++;
	}
	return (res);
}
