/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:23:41 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/02 10:36:53 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_base(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	return (count + ft_putnbr_base(n));
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	return (ft_putnbr_base((unsigned long)nb));
}
