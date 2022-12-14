/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:49:55 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/16 20:04:33 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	ft_check_complex(char *s)
{
	char	*sep;
	char	*imag_c;
	char	*re;
	char	*im;

	if (s[0] == '+' || s[0] == '-')
		s++;
	sep = search_sep(s);
	if (!sep)
		return (0);
	imag_c = ft_strchr(s, 'i');
	if (imag_c == NULL || (imag_c[0] == 'i' && imag_c[1] != '\0'))
		return (0);
	re = ft_substr(s, 0, sep - s);
	if (!re)
		return (error_7());
	im = ft_substr(sep, 1, imag_c - sep - 1);
	if (!im)
		return (error_7i(re));
	if ((ft_check_double(re) != 1 || ft_check_double(im) != 1)
		|| ft_strcmp(im, "") == 0)
		return (0);
	free(re);
	free(im);
	return (1);
}

char	*search_sep(char *s)
{
	char	*sep;

	sep = ft_strchr(s, '+');
	if (sep == NULL)
	{
		sep = ft_strchr(s, '-');
	}
	return (sep);
}

int	error_message(int i)
{
	if (i == 1)
		init_mesagge();
	else if (i == 2)
		ft_putstr_fd("Invalid double parameter.\n\n", 1);
	else if (i == 3)
	{
		ft_putstr_fd("Invalid complex parameter:\n\n", 1);
		ft_putstr_fd("The complex numbers have to by always typed in the\n", 1);
		ft_putstr_fd("format:\n", 1);
		ft_putstr_fd("\tdouble>+<double>i or <double>-<double>i\n\n", 1);
	}
	return (0);
}

void	init_mesagge(void)
{
	ft_putstr_fd("\t\t\t TO RUN FRACT'OL:\n", 1);
	ft_putstr_fd("The first paramether is the name of one of the ", 1);
	ft_putstr_fd("avalaible fractals.\n", 1);
	ft_putstr_fd("\tOptions:\n", 1);
	ft_putstr_fd("\t\t-> \"Mandelbrot\"\n", 1);
	ft_putstr_fd("\t\t-> \"Julia\"\n", 1);
	ft_putstr_fd("\t\t-> \"Newton\"\n", 1);
	ft_putstr_fd("\n", 1);
	init_mesagge_m();
	init_mesagge_j();
	init_mesagge_n();
	ft_putstr_fd("Already in the program you can also control: ", 1);
	ft_putstr_fd("the number of iterations, and\n", 1);
	ft_putstr_fd("the boundary that defines wheter or not a ", 1);
	ft_putstr_fd("point belongs to Mandelbrot\n", 1);
	ft_putstr_fd("or Julia sets, or the proximity of the ", 1);
	ft_putstr_fd("final iteration to a root in the \n", 1);
	ft_putstr_fd("Newton's fractal.\n", 1);
}

void	init_mesagge_m(void)
{
	ft_putstr_fd("-> For Mandelbrot:\n", 1);
	ft_putstr_fd("   Fract'ol shows the Mandelbrot set ", 1);
	ft_putstr_fd("iterating over the polynomial\n", 1);
	ft_putstr_fd("   \"C + Z^2\" by default, where C is a ", 1);
	ft_putstr_fd("complex number and Z_0 = 0+0i\n", 1);
	ft_putstr_fd("   is the initial point of iterations. ", 1);
	ft_putstr_fd("The initial point Z_0 can be\n", 1);
	ft_putstr_fd("   modified by the program's key controls, ", 1);
	ft_putstr_fd("and the polynomial Z^2\n", 1);
	ft_putstr_fd("   can be remplaced by any zero constant ", 1);
	ft_putstr_fd("polynomial starting the\n", 1);
	ft_putstr_fd("   program using the another executable's ", 1);
	ft_putstr_fd("parameters like a doubles\n", 1);
	ft_putstr_fd("   that will serve as coefficients of ", 1);
	ft_putstr_fd("another polynomial. For example,\n", 1);
	ft_putstr_fd("   starting fract'ol like this:\n", 1);
	ft_putstr_fd("   \t./fractol \"Mandelbrot\" \"0.2\" \"-0.1\" \"0\" \"2\" \"-3\"\n\n", 1);
	ft_putstr_fd("   will iterate in the same way on the:\n\n", 1);
	ft_putstr_fd("   \t\t C + 0.2*Z -0.1*Z^2 + 2*Z^4 - 3*Z^5\n\n", 1);
	ft_putstr_fd("   polynomial.\n\n", 1);
}
