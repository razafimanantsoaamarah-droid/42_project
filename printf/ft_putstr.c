/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:42:40 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/02 10:45:46 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	if (*str == '\0')
		return (0);
	ft_putchar(*str);
	return (1 + ft_putstr(str + 1));
}
