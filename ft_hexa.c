/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
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

int	ft_puthexa_min(unsigned int nbr)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	return (ft_puthexa_base(nbr, "0123456789abcdef"));
}

int	ft_puthexa_maj(unsigned int nbr)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	return (ft_puthexa_base(nbr, "0123456789ABCDEF"));
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long long)ptr;
	count = ft_putstr("0x");
	count += ft_puthexa_base(addr, "0123456789abcdef");
	return (count);
}
