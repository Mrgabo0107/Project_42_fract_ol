/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:48:29 by gamoreno          #+#    #+#             */
/*   Updated: 2022/08/13 07:36:09 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parametros:	-Dos cadenas de caracteres punteadas respectivamente por 's1' y 
 * 		's2'.
 *
 * Esta funcion compara caracter a caracter las cadenas 's1' y 's2'.
 *
 * Devuelve: la resta del valor ascii correspondiente al primer caracter en el
 * que difieran 's1' y 's2', o cero si las cadenas son iguales. */

#include "../includes/libft.h"

int	ft_strcmp(const char *ptr1, const char *ptr2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
