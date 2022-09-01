/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_compl_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:01:04 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:53:51 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_complex	*get_cplx_cf(int ac, char **ag)
{
	t_complex	*coef;
	int			i;

	i = 0;
	if (ac > 2)
	{
		coef = (t_complex *)malloc(sizeof(t_complex) * (ac - 2));
		if (!coef)
			return (NULL);
		while (i < ac - 2)
		{
			coef[i] = ft_get_complex(ag[i + 2]);
			i++;
		}
	}
	else
		return (ft_stndr_roots());
	return (coef);
}

unsigned int	absolute_v_int(int n)
{
	int	res;

	if (n < 0)
		res = -1 * n;
	else
		res = n;
	return ((unsigned int)res);
}

unsigned int	absolute_v_lint(long int n)
{
	long int	res;

	if (n < 0)
		res = -1 * n;
	else
		res = n;
	return ((unsigned int)res);
}

int	ten_pow(int c)
{
	int			i;

	i = 0;
	while (c / (int)pow(10, i) > 0)
		i++;
	return ((int)pow(10, i - 1));
}

double	ft_cnorm_t_sqr(t_complex c)
{
	double	res;

	res = pow(c.r, 2) + pow(c.i, 2);
	return (res);
}
