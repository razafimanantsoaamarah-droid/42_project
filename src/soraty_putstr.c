/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:42:40 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 10:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

int	soraty_putstr(char *str)
{
	if (!str)
	{
		return (soraty_putstr("(null)"));
	}
	if (*str == '\0')
		return (0);
	soraty_putchar(*str);
	return (1 + soraty_putstr(str + 1));
}