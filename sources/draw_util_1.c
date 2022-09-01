/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:03:29 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:02:16 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_pixel	**color_m_j(t_fractol *fr, t_pixel **matrix)
{
	t_pixel	**res;
	int		i;
	int		j;

	i = 0;
	res = matrix;
	while (i < IX)
	{
		j = 0;
		while (j < IY)
		{
			res[i][j] = ft_alg_mj(fr, res[i][j]);
			j++;
		}
		i++;
	}
	return (res);
}

t_pixel	**color_n(t_fractol *fr, t_pixel **matrix, int ac)
{
	t_pixel	**res;
	int		i;
	int		j;
	int		n_root;

	i = 0;
	res = matrix;
	n_root = ac - 2;
	if (ac < 3)
		n_root = 3;
	while (i < IX)
	{
		j = 0;
		while (j < IY)
		{
			res[i][j] = ft_alg_n(fr, res[i][j], n_root);
			j++;
		}
		i++;
	}
	return (res);
}

t_pixel	ft_alg_mj(t_fractol *fr, t_pixel p)
{
	t_pixel	res;

	res = p;
	if (fr->ctrl == 1)
		res = ft_alg_m(fr, res);
	else if (fr->ctrl == 2)
		res = ft_alg_j(fr, res);
	return (res);
}

t_pixel	ft_alg_m(t_fractol *fr, t_pixel p)
{
	t_pixel	cpy;

	cpy = p;
	if (cpy.c_ctrl == fr->iter)
		cpy.color = fr->pallete[11];
	else
		cpy.color = degrade_m(fr, p);
	return (cpy);
}

t_pixel	ft_alg_j(t_fractol *fr, t_pixel p)
{
	t_pixel	cpy;

	cpy = p;
	if (cpy.c_ctrl == fr->iter)
		cpy.color = fr->pallete[11];
	else
		cpy.color = degrade_j(fr, p);
	return (cpy);
}
