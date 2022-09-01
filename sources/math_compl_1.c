/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_compl_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 04:03:16 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/15 04:10:20 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_complex	ft_get_complex(char *s)
{
	t_complex	res;
	char		*img_part;

	res.r = ft_atof(s);
	if (s[0] == '-' || s[0] == '+')
		s++;
	img_part = ft_strchr(s, '+');
	if (img_part == NULL)
		img_part = ft_strchr(s, '-');
	res.i = ft_atof(img_part);
	return (res);
}

t_complex	ft_scale_by(double scale_factor, t_complex c)
{
	t_complex	res;

	res.r = scale_factor * c.r;
	res.i = scale_factor * c.i;
	return (res);
}

t_complex	ft_csum(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.r = c1.r + c2.r;
	res.i = c1.i + c2.i;
	return (res);
}

t_complex	ft_crest(t_complex c1, t_complex c2)
{
	t_complex	res;

	res = ft_csum(c1, ft_scale_by(-1, c2));
	return (res);
}

t_complex	ft_cmult(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.r = (c1.r * c2.r) - (c1.i * c2.i);
	res.i = (c1.r * c2.i) + (c1.i * c2.r);
	return (res);
}
