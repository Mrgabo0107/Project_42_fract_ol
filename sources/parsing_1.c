/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 07:02:56 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/16 17:36:12 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	ft_check_ag(int ac, char **ag)
{
	int	frac_ctr;

	frac_ctr = 0;
	if (ac > 1 && ft_strcmp(ag[1], "Mandelbrot") == 0)
		frac_ctr = ft_check_m(ac, ag);
	else if (ac > 2 && ft_strcmp(ag[1], "Julia") == 0)
		frac_ctr = ft_check_j(ac, ag);
	else if (ac > 1 && ft_strcmp(ag[1], "Newton") == 0)
		frac_ctr = ft_check_n(ac, ag);
	return (frac_ctr);
}

int	ft_check_m(int ac, char **ag)
{
	int		i;
	char	*cont;

	cont = NULL;
	i = 2;
	while (i < ac)
	{
		if (ft_check_double(ag[i]) != 1)
		{
			cont = ft_itoa(i);
			ft_putstr_fd("Error in argument ", 1);
			ft_putstr_fd(cont, 1);
			ft_putstr_fd(":\n", 1);
			free(cont);
			return (error_message(2));
		}
		i++;
	}
	return (1);
}

int	ft_check_j(int ac, char **ag)
{
	int		i;
	char	*cont;

	cont = NULL;
	if (ft_check_complex(ag[2]) != 1)
	{
		ft_putstr_fd("Error in argument 2:\n", 1);
		return (error_message(3));
	}
	i = 3;
	while (i < ac)
	{
		if (ft_check_double(ag[i]) != 1)
		{
			cont = ft_itoa(i);
			ft_putstr_fd("Error in argument ", 1);
			ft_putstr_fd(cont, 1);
			ft_putstr_fd(":\n", 1);
			free(cont);
			return (error_message(2));
		}
		i++;
	}
	return (2);
}

int	ft_check_n(int ac, char **ag)
{
	int		i;
	char	*cont;

	i = 2;
	cont = NULL;
	while (i < ac)
	{
		if (ft_check_complex(ag[i]) != 1)
		{
			cont = ft_itoa(i);
			ft_putstr_fd("Error in argument ", 1);
			ft_putstr_fd(cont, 1);
			ft_putstr_fd(":\n", 1);
			free(cont);
			return (error_message(3));
		}
		i++;
	}
	return (3);
}

int	ft_check_double(char *s)
{
	int	i;
	int	p_ctl;

	i = 0;
	p_ctl = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i])
	{
		if (p_ctl > 1 || (ft_isdigit(s[i]) == 0 && !(s[i] == '.')))
			return (0);
		if (s[i] == '.')
		{
			p_ctl++;
			i++;
		}
		i++;
	}
	return (1);
}
