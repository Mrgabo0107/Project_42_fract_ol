/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:56:08 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/16 17:36:39 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	main(int ac, char **ag)
{
	t_fractol	*frtl;

	if (ft_check_ag(ac, ag) != 0)
	{
		frtl = (t_fractol *)malloc(sizeof(t_fractol));
		if (!frtl)
			return (0);
		ft_init_fractol(frtl, ft_check_ag(ac, ag), ac, ag);
		ft_draw_fractol(frtl);
		mlx_key_hook(frtl->win, &key_press, frtl);
		mlx_mouse_hook(frtl->win, &mouse_press, frtl);
		mlx_hook(frtl->win, 17, KeyPressMask, &end, frtl);
		mlx_loop(frtl->mlx);
	}
	else
		return (error_message(1));
	return (0);
}
