/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:33:22 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 05:36:42 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

unsigned int	*ft_get_rgb(unsigned int int_rgb)
{
	unsigned int	*rgb;
	unsigned int	curr;

	curr = int_rgb;
	rgb = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	if (!rgb)
		return (NULL);
	rgb[0] = curr % 256;
	curr = (curr - (curr % 256)) / 256;
	rgb[1] = curr % 256;
	curr = (curr - (curr % 256)) / 256;
	rgb[2] = curr % 256;
	return (rgb);
}

unsigned int	*rgb_sizeby(unsigned int *rgb, int c)
{
	unsigned int	*rgbc;
	int				i;

	i = 0;
	rgbc = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	if (!rgbc)
		return (NULL);
	while (i < 3)
	{
		rgbc[i] = (absolute_v_int(c) * rgb[i]) % 256;
		i++;
	}
	return (rgbc);
}

unsigned int	*rgb_sizeby_div(unsigned int *rgb, int c)
{
	unsigned int	*rgbc;
	int				i;

	i = 0;
	rgbc = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	if (!rgbc)
		return (NULL);
	while (i < 3)
	{
		rgbc[i] = rgb[i] / absolute_v_int(c);
		i++;
	}
	return (rgbc);
}

unsigned int	*rgb_rest(unsigned int *rgb1, unsigned int *rgb2)
{
	unsigned int	*rgb;
	int				i;

	i = 0;
	rgb = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	if (!rgb)
		return (NULL);
	while (i < 3)
	{
		rgb[i] = absolute_v_lint((long int)rgb1[i] - (long int)rgb2[i]);
		i++;
	}
	return (rgb);
}

unsigned int	rgb_to_int(unsigned int *rgb)
{
	unsigned int	color;
	int				i;

	i = 0;
	color = 0;
	while (i < 3)
	{
		color += rgb[i] * (unsigned int)pow(256, i);
		i++;
	}
	return (color);
}
