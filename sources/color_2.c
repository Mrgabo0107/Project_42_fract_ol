/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:24:08 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 05:43:50 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

unsigned int	*get_pal(int c)
{
	int				ctrl;
	unsigned int	*pal;

	ctrl = c % 3;
	if (ctrl == 0)
		pal = pallete_0();
	else if (ctrl == 1)
		pal = pallete_1();
	else
		pal = pallete_2();
	return (pal);
}

unsigned int	*pallete_0(void)
{
	unsigned int	*palette;

	palette = (unsigned int *)malloc(sizeof(unsigned int) * 12);
	if (!palette)
		return (NULL);
	palette[0] = 0x040026;
	palette[1] = 0x00172E;
	palette[2] = 0x002623;
	palette[3] = 0x193B00;
	palette[4] = 0x465700;
	palette[5] = 0x857E00;
	palette[6] = 0xC4A600;
	palette[7] = 0xD19A00;
	palette[8] = 0xFF8C00;
	palette[9] = 0xFF4A00;
	palette[10] = 0xFF0700;
	palette[11] = 0x252525;
	return (palette);
}

unsigned int	*pallete_1(void)
{
	unsigned int	*palette;

	palette = (unsigned int *)malloc(sizeof(unsigned int) * 12);
	if (!palette)
		return (NULL);
	palette[0] = 0x1B1224;
	palette[1] = 0x231838;
	palette[2] = 0x24174D;
	palette[3] = 0x251B66;
	palette[4] = 0x1D1B75;
	palette[5] = 0x1C3BEB;
	palette[6] = 0x0051FF;
	palette[7] = 0x007BFF;
	palette[8] = 0x00A6FF;
	palette[9] = 0x1CC5EB;
	palette[10] = 0x00FBFF;
	palette[11] = 0xABFFFF;
	return (palette);
}

unsigned int	*pallete_2(void)
{
	unsigned int	*palette;

	palette = (unsigned int *)malloc(sizeof(unsigned int) * 12);
	if (!palette)
		return (NULL);
	palette[0] = 0xC0FF00;
	palette[1] = 0xFFD500;
	palette[2] = 0xFF9901;
	palette[3] = 0xF54100;
	palette[4] = 0xFF0041;
	palette[5] = 0xd60036;
	palette[6] = 0x9E007D;
	palette[7] = 0x6C0085;
	palette[8] = 0x2E0257;
	palette[9] = 0x0C0036;
	palette[10] = 0x090029;
	palette[11] = WHT;
	return (palette);
}
