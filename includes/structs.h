/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:43:35 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/01 02:06:04 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_pixel
{
	unsigned int	color;
	int				c_ctrl;
	t_complex		c;
}	t_pixel;

typedef struct s_fractol
{
	unsigned int	*pallete;
	void			*mlx;
	void			*win;
	void			*img;
	char			**ag;
	char			*adr;
	unsigned int	col_ctr;
	int				bpp;
	int				llen;
	int				endi;
	int				iter;
	int				miniter;
	int				ctrl;
	int				ac;
	int				ite_f;
	int				zoom_f;
	double			cot_f;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			step_x;
	double			step_y;
	double			cota;
	double			inp_f;
	t_complex		ini_p;	
	t_pixel			**matrix;
}	t_fractol;

#endif
