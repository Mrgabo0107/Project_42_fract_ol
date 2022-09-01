/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:03:33 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:43:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

double	*get_coef(int ac, char **ag)
{
	double	*coef;
	int		i;
	int		ctrl;

	ctrl = 0;
	if (ft_strcmp(ag[1], "Mandelbrot") == 0)
		ctrl = 2;
	else if (ft_strcmp(ag[1], "Julia") == 0)
		ctrl = 3;
	if (ac > ctrl)
	{
		coef = (double *)malloc(sizeof(double) * (ac - ctrl));
		if (!coef)
			return (NULL);
		i = ctrl;
		while (i < ac)
		{
			coef[i - ctrl] = ft_atof(ag[i]);
			i++;
		}
	}
	else
		return (stndr_coef());
	return (coef);
}

double	*stndr_coef(void)
{
	double	*coef;

	coef = (double *)malloc(sizeof(double) * 2);
	if (!coef)
		return (NULL);
	coef[0] = 0.0;
	coef[1] = 1.0;
	return (coef);
}

int	ft_asign_root(t_fractol *fr, t_complex c, int nroot, t_complex *root)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < nroot)
	{
		if (ft_cnorm_t_sqr(ft_crest(c, root[i])) < pow(fr->cota, 2))
			res = i + 1;
		i++;
	}
	return (res);
}

t_complex	*ft_stndr_roots(void)
{
	t_complex	*root;

	root = (t_complex *)malloc(sizeof(t_complex) * 3);
	if (!root)
		return (NULL);
	root[0] = ft_get_complex("1+0i");
	root[1] = ft_get_complex("-0.5+0.866025i");
	root[2] = ft_get_complex("-0.5-0.866025i");
	return (root);
}
