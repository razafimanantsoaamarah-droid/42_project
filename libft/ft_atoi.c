/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 00:35:54 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/01 00:51:46 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[count]))
		count ++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count ++;
	}
	while (ft_isdigit(str[count]))
	{
		result = result * 10 + (str[count] - '0');
		count ++;
	}
	return (sign * result);
}
