/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_print_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:23:30 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 10:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

int	soraty_print_hex(unsigned int n, int maj)
{
	char	*base;
	int		len;

	len = 0;
	if (maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += soraty_print_hex(n / 16, maj);
	len += soraty_putchar(base[n % 16]);
	return (len);
}