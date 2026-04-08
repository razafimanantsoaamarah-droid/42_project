/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:23:30 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/02 10:36:31 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa_base(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthexa_base(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_puthexa_base(n, base));
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long long)ptr;
	return (ft_putstr("0x") + ft_puthexa_base(addr, "0123456789abcdef"));
}
