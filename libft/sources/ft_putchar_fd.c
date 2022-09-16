/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:23:19 by gamoreno          #+#    #+#             */
/*   Updated: 2022/06/20 11:55:55 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parametros:	-Un char 'c' que va a ser escrito en un archivo.
 * 		-Un file descriptor 'fd' que define donde se escribir el 
 * 		 caracter 'c'.
 * Esta funcion escribe el caracter 'c' en el archivo descrito por el file
 * descriptor 'fd'.
 *
 * Devuelve: n/a es tipo void. */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
