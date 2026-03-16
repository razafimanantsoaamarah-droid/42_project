/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:31:42 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 11:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

static int	manage_conversion(va_list args, char c)
{
	if (c == 'c')
		return (soraty_putchar(va_arg(args, int)));
	if (c == 's')
		return (soraty_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (soraty_print_pointer(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (soraty_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (soraty_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (soraty_print_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (soraty_print_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (soraty_putchar('%'));
	return (write(1, "%", 1) + write(1, &c, 1));
}

// Version classique avec % (pour compatibilité)
int	soraty_classic(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += manage_conversion(args, *format);
		}
		else
			count += soraty_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

// NOUVELLE VERSION : Template literal avec ${}
int	soraty(const char *format, ...)
{
	t_soraty	data;
	int			result;

	if (!format)
		return (0);
	
	va_start(data.args, format);
	data.format = format;
	data.count = 0;
	
	// Parser le format avec les template literals
	result = parse_template(&data);
	
	va_end(data.args);
	return (result);
}