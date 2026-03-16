/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_template.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:00:00 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 11:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static int	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

char	*extract_expression(const char *format, int *len)
{
	int		i;
	char	*expr;

	i = 0;
	*len = 0;
	// Vérifier le début de l'expression ${}
	if (format[i] == '$' && format[i + 1] == '{')
	{
		i += 2; // Passer ${
		// Trouver la fin de l'expression
		while (format[i] && format[i] != '}')
		{
			if (!ft_isalnum(format[i]) && format[i] != '_')
				return (NULL); // Caractère invalide dans le nom de variable
			i++;
		}
		if (format[i] == '}')
		{
			*len = i + 1; // Longueur totale incluant ${}
			expr = ft_strndup(format + 2, i - 2); // Extraire le nom sans ${}
			return (expr);
		}
	}
	return (NULL);
}