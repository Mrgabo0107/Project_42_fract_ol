/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 07:57:07 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 04:57:08 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_pixel	**init_pixel_matrix(void)
{
	t_pixel	**out;
	int		i;

	out = (t_pixel **)malloc(sizeof(t_pixel *) * (IY + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < IY)
	{
		out[i] = (t_pixel *)malloc(sizeof(t_pixel) * IX);
		if (!out[i])
		{
			free(out);
			return (NULL);
		}
		i++;
	}
	out[IY] = NULL;
	return (out);
}

void	free_pixel_matrix(t_pixel **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_pixel	**ft_fill_matrix(t_fractol *fr, t_pixel **matrix)
{
	t_pixel	**mat;
	int		i;
	int		j;

	i = 0;
	mat = matrix;
	while (i < IX)
	{
		j = IY - 1;
		while (j >= 0)
		{
			mat[i][j].c.r = fr->min_x + (fr->step_x * (double)i);
			mat[i][j].c.i = fr->min_y + (fr->step_y * (double)j);
			j--;
		}
		i++;
	}
	return (mat);
}
