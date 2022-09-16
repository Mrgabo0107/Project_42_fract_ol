/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:13:42 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/16 20:03:13 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	error_7i(char *re)
{
	free(re);
	ft_putstr_fd("Error: memory no allocated\n", 1);
	return (0);
}

void	free_lim_arg(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}

void	free_scr_arg(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
