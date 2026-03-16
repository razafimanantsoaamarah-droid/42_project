/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:23:41 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 10:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

static int	putnbr_base(unsigned long number)
{
	int				count;
	unsigned long	digit;

	count = 0;
	digit = number;
	if (number >= 0)
	{
		if (number >= 10)
			count += putnbr_base(number / 10);
		count += soraty_putchar((char)(digit % 10 + '0'));
	}
	return (count);
}

int	soraty_putnbr(int nb)
{
	int		count;
	long	n;

	count = 0;
	n = nb;
	if (n == 0)
		return (soraty_putchar('0'));
	if (n < 0)
	{
		count += soraty_putchar('-');
		n = -n;
	}
	count += putnbr_base((unsigned long)n);
	return (count);
}

int	soraty_putnbr_unsigned(unsigned int nb)
{
	if (nb == 0)
		return (soraty_putchar('0'));
	return (putnbr_base((unsigned long)nb));
}