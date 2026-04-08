/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:45:12 by maherraz          #+#    #+#             */
/*   Updated: 2026/02/28 00:31:17 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_fill(char *str, long num, int len)
{
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = n;
	len = ft_numlen(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (num < 0)
		num = -num;
	ft_fill(str, num, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
