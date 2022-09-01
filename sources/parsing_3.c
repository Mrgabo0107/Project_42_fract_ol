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
