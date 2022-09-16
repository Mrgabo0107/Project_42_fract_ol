/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:43:21 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/16 19:57:13 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "structs.h"
# define WX 1000
# define WY 755
# define IX 750
# define IY 750
# define BORDE 122
# define BLK 0x0
# define WHT 0xFFFFFF
# define BLU 0x0000FF
# define K_ESC 65307
# define K_UP  65362
# define K_DWN 65364
# define K_LFT 65361
# define K_RGT 65363
# define K_INC 65451
# define K_DCR 65453
# define K_ONE 65470
# define K_TWO 65471
# define K_TRE 65472
# define K_FOR 65473
# define K_FIV 65474
# define K_SIX 65475

/*---------------parsing-------------*/
int				ft_check_ag(int ac, char **ag);
int				ft_check_m(int ac, char **ag);
int				ft_check_j(int ac, char **ag);
int				ft_check_n(int ac, char **ag);
int				ft_check_double(char *s);
int				ft_check_complex(char *s);
char			*search_sep(char *s);
int				error_message(int i);
void			init_mesagge(void);
void			init_mesagge_m(void);
void			init_mesagge_j(void);
void			init_mesagge_n(void);

/*----------------init----------------*/
void			ft_init_fractol(t_fractol *fr, int ctrl, int argc, char **argv);
char			**ft_get_coef(int argc, char **argv);
void			ft_init_mdbrot(t_fractol *fr);
void			ft_init_julia(t_fractol *fr, char **ag);
void			ft_init_newton(t_fractol *fr);

/*---------------matrix--------------*/
t_pixel			**init_pixel_matrix(void);
void			free_pixel_matrix(t_pixel **matrix);
t_pixel			**ft_fill_matrix(t_fractol *fr, t_pixel **matrix);

/*-----------------draw---------------*/
void			ft_draw_fractol(t_fractol *fr);
void			ft_set_draw(t_fractol *fr, int ac, char **ag);
void			screen_controls(t_fractol *fr);
void			ft_read_and_print(t_fractol *fr);
t_pixel			**calcul(t_fractol *fr,	t_pixel (*f)(t_fractol*,
						t_pixel, int, char**), int ac, char **ag);
t_pixel			**color_m_j(t_fractol *fr, t_pixel **matrix);
t_pixel			**color_n(t_fractol *fr, t_pixel **matrix, int n_root);
t_pixel			ft_alg_mj(t_fractol *fr, t_pixel p);
t_pixel			ft_alg_m(t_fractol *fr, t_pixel p);
t_pixel			ft_alg_j(t_fractol *fr, t_pixel p);
t_pixel			ft_alg_n(t_fractol *fr, t_pixel p, int n_root);
unsigned int	degrade_m(t_fractol *fr, t_pixel p);
unsigned int	degrade_j(t_fractol *fr, t_pixel p);
unsigned int	separate(t_fractol *fr, t_pixel p, int n_root);
unsigned int	res_sep(unsigned int *c1, unsigned int *c2, int ctr, int root);
void			screen_mj(t_fractol *fr);
void			limits_image(t_fractol *fr);
void			guide_image(t_fractol *fr);
void			my_mlx_pixel_put(t_fractol *fr, int x, int y, int color);

/*-------------fractals---------------*/
t_pixel			ft_mandelbrot(t_fractol *fr, t_pixel p, int ac, char **ag);
t_pixel			ft_julia(t_fractol *fr, t_pixel p, int ac, char **ag);
t_pixel			ft_newton(t_fractol *fr, t_pixel p, int ac, char **ag);
double			*get_coef(int ac, char **ag);
double			*stndr_coef(void);
int				ft_asign_root(t_fractol *fr, t_complex c,
					int nroot, t_complex *root);
t_complex		*get_cplx_cf(int ac, char **ag);
t_complex		*ft_stndr_roots(void);

/*-----------math_complements--------*/
t_complex		ft_get_complex(char *s);
t_complex		ft_scale_by(double scale_factor, t_complex c);
t_complex		ft_csum(t_complex c1, t_complex c2);
t_complex		ft_crest(t_complex c1, t_complex c2);
t_complex		ft_cmult(t_complex c1, t_complex c2);
t_complex		ft_cdiv(t_complex c1, t_complex c2);
t_complex		ft_cpow(t_complex bas, int pow);
t_complex		ft_poly_nc(t_complex c, double *coef, int numc);
t_complex		ft_mono_mult(t_complex c, t_complex *root, int numr);
t_complex		ft_deriv_mono(t_complex c, t_complex *root, int numr);
unsigned int	absolute_v_int(int n);
unsigned int	absolute_v_lint(long int n);
int				ten_pow(int c);
double			ft_cnorm_t_sqr(t_complex c);

/*---------------evets----------------*/
int				key_press(int key, t_fractol *fr);
void			ft_end(t_fractol *fr);
int				end(t_fractol *fr);
void			ft_arr_mov(int key, t_fractol *fr);
void			ft_mod_iter(int key, t_fractol *fr);
void			ft_mod_cota(int key, t_fractol *fr);
void			ft_mod_inip(int key, t_fractol *fr);
int				mouse_press(int button, int x, int y, t_fractol *fr);
int				mouse_in_img(int x, int y);
void			zoom(int button, int x, int y, t_fractol *fr);
void			zoom_set(t_fractol *fr, int button);
void			ch_color(int button, t_fractol *fr);
void			ft_reinit(t_fractol *fr);

/*---------------color-------------------*/
unsigned int	*ft_get_rgb(unsigned int int_rgb);
unsigned int	*rgb_sizeby(unsigned int *rgb, int c);
unsigned int	*rgb_sizeby_div(unsigned int *rgb, int c);
unsigned int	*rgb_rest(unsigned int *rgb1, unsigned int *rgb2);
unsigned int	rgb_to_int(unsigned int *rgb);
unsigned int	*get_pal(int c);
unsigned int	*pallete_0(void);
unsigned int	*pallete_1(void);
unsigned int	*pallete_2(void);

/*--------------errors-------------------*/
void			error_0(t_fractol *fr);
void			error_1(t_fractol *fr);
void			error_2(t_fractol *fr);
void			error_3(t_fractol *fr);
void			error_4(t_fractol *fr);
void			error_5(t_fractol *fr);
void			error_6(t_fractol *fr);
void			error_6s(t_fractol *fr, unsigned int *a);
void			error_6s2(t_fractol *fr, char *a);
int				error_7(void);
int				error_7i(char *re);
void			free_lim_arg(char *s1, char *s2, char *s3, char *s4);
void			free_scr_arg(char *s1, char *s2);

#endif
