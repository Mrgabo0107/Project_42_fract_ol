/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 06:56:25 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/31 06:56:27 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	init_mesagge_j(void)
{
	ft_putstr_fd("-> For Julia:\n", 1);
	ft_putstr_fd("   Fract'ol shows the Julia set by using ", 1);
	ft_putstr_fd("a complex constant \"P\" passed\n", 1);
	ft_putstr_fd("   as the second executable's parameter, ", 1);
	ft_putstr_fd("this parameter has to by set\n", 1);
	ft_putstr_fd("   always in the format: <double>+<double>i ", 1);
	ft_putstr_fd("or <double>-<double>i, and\n", 1);
	ft_putstr_fd("   the program iterates over \"P + Z^2\" ", 1);
	ft_putstr_fd("by default, where P can by \n", 1);
	ft_putstr_fd("   modified by the program's key controls, ", 1);
	ft_putstr_fd("and the polynomial Z^2 can\n", 1);
	ft_putstr_fd("   be remplaced by any zero constant polynomial ", 1);
	ft_putstr_fd("using the following\n", 1);
	ft_putstr_fd("   parameters like a doubles that will serve as ", 1);
	ft_putstr_fd("coefficients of another\n", 1);
	ft_putstr_fd("   polynomial. For example, starting ", 1);
	ft_putstr_fd("fract'ol like this:\n\n", 1);
	ft_putstr_fd("   \t./fractol \"julia\" \"-0.4-0.6i\" ", 1);
	ft_putstr_fd("\"1\" \"-0.6\" \"3.2\" \"0\" \"-9.5\"\n\n", 1);
	ft_putstr_fd("   will iterate over a complex number Z ", 1);
	ft_putstr_fd("in the polynomial:\n\n", 1);
	ft_putstr_fd("   \t\t (-0.4-0.6i) + Z - 0.6*Z^2 + 3.2*Z^3 - 9.5*Z^5\n\n", 1);
}

void	init_mesagge_n(void)
{
	ft_putstr_fd("-> For Newton:\n", 1);
	ft_putstr_fd("   Fract'ol shows the Newton's fractal ", 1);
	ft_putstr_fd("given the complex roots to which\n", 1);
	ft_putstr_fd("   the method is intended to cenverge, ", 1);
	ft_putstr_fd("by default you have the fractal\n", 1);
	ft_putstr_fd("   which results from applying the method ", 1);
	ft_putstr_fd("on the polynomial of roots:\n", 1);
	ft_putstr_fd("   \"1+0i\", \"-0.5+0.866i\" and \"-0.5-0.866i\". ", 1);
	ft_putstr_fd("However you can set\n", 1);
	ft_putstr_fd("   another roots in the executable's parameters ", 1);
	ft_putstr_fd("typing any complex number\n", 1);
	ft_putstr_fd("   in the format: <double>+<double>i or ", 1);
	ft_putstr_fd("<double>-<double>i. For example,\n", 1);
	ft_putstr_fd("   try start fract'ol like this:\n\n", 1);
	ft_putstr_fd("./fractol \"Newton\" \"0.31+0.95i\" \"0.31-0.95i\" ", 1);
	ft_putstr_fd("\"-0.81+0.59i\" \"-0.81-0.59i\" \"1+0i\"\n\n", 1);
	ft_putstr_fd("   or with anothers complex numbers points.\n\n", 1);
	ft_putstr_fd("   Start with one parameter prints ", 1);
	ft_putstr_fd("the screen with one color.\n\n", 1);
}
