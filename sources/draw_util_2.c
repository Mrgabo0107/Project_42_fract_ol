/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 07:56:23 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:12:57 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_pixel	ft_alg_n(t_fractol *fr, t_pixel p, int n_root)
{
	t_pixel	res;

	res = p;
	if (res.c_ctrl == 0)
		res.color = BLK;
	else
		res.color = separate(fr, res, n_root);
	return (res);
}

unsigned int	degrade_m(t_fractol *fr, t_pixel p)
{
	unsigned int	res;

	if (p.c_ctrl < fr->iter / 43)
		res = fr->pallete[0];
	else if (fr->iter / 43 < fr->iter && p.c_ctrl < fr->iter / 33)
		res = fr->pallete[1];
	else if (fr->iter / 33 < fr->iter && p.c_ctrl < fr->iter / 26)
		res = fr->pallete[2];
	else if (fr->iter / 26 < fr->iter && p.c_ctrl < fr->iter / 20)
		res = fr->pallete[3];
	else if (fr->iter / 20 < fr->iter && p.c_ctrl < fr->iter / 15)
		res = fr->pallete[4];
	else if (fr->iter / 15 < fr->iter && p.c_ctrl < fr->iter / 12)
		res = fr->pallete[5];
	else if (fr->iter / 12 < fr->iter && p.c_ctrl < fr->iter / 9)
		res = fr->pallete[6];
	else if (fr->iter / 9 < fr->iter && p.c_ctrl < fr->iter / 6)
		res = fr->pallete[7];
	else if (fr->iter / 6 < fr->iter && p.c_ctrl < fr->iter / 4)
		res = fr->pallete[8];
	else if (fr->iter / 4 < fr->iter && p.c_ctrl < fr->iter / 2)
		res = fr->pallete[9];
	else
		res = fr->pallete[10];
	return (res);
}

unsigned int	degrade_j(t_fractol *fr, t_pixel p)
{
	unsigned int	res;

	if (p.c_ctrl < fr->iter / 43)
		res = fr->pallete[9];
	else if (fr->iter / 43 < fr->iter && p.c_ctrl < fr->iter / 33)
		res = fr->pallete[9];
	else if (fr->iter / 33 < fr->iter && p.c_ctrl < fr->iter / 26)
		res = fr->pallete[8];
	else if (fr->iter / 26 < fr->iter && p.c_ctrl < fr->iter / 20)
		res = fr->pallete[7];
	else if (fr->iter / 20 < fr->iter && p.c_ctrl < fr->iter / 15)
		res = fr->pallete[6];
	else if (fr->iter / 15 < fr->iter && p.c_ctrl < fr->iter / 12)
		res = fr->pallete[5];
	else if (fr->iter / 12 < fr->iter && p.c_ctrl < fr->iter / 9)
		res = fr->pallete[4];
	else if (fr->iter / 9 < fr->iter && p.c_ctrl < fr->iter / 6)
		res = fr->pallete[3];
	else if (fr->iter / 6 < fr->iter && p.c_ctrl < fr->iter / 4)
		res = fr->pallete[2];
	else if (fr->iter / 4 < fr->iter && p.c_ctrl < fr->iter / 2)
		res = fr->pallete[1];
	else
		res = fr->pallete[0];
	return (res);
}

unsigned int	separate(t_fractol *fr, t_pixel p, int n_root)
{
	unsigned int	*curr1;
	unsigned int	*curr2;
	unsigned int	res;

	if (n_root > 1)
	{
		curr1 = ft_get_rgb(fr->pallete[4]);
		curr2 = ft_get_rgb(fr->pallete[11]);
		res = res_sep(curr1, curr2, p.c_ctrl, n_root);
		free(curr1);
		free(curr2);
	}
	else
		res = fr->pallete[3];
	return (res);
}

unsigned int	res_sep(unsigned int *c1, unsigned int *c2, int ctr, int root)
{
	unsigned int	*dif;
	unsigned int	*div;
	unsigned int	*op;
	unsigned int	*sum;
	unsigned int	res;

	dif = rgb_rest(c1, c2);
	div = rgb_sizeby_div(dif, root - 1);
	op = rgb_sizeby(div, ctr - 1);
	sum = rgb_rest(c1, op);
	res = rgb_to_int(sum);
	free(dif);
	free(div);
	free(op);
	free(sum);
	return (res);
}
