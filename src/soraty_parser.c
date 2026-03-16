/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:00:00 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 11:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

int	handle_expression(t_soraty *data)
{
	int		count;
	char	*var_name;
	int		expr_len;
	
	count = 0;
	var_name = extract_expression(data->format, &expr_len);
	
	if (var_name)
	{
		// On a trouvé une expression ${variable}
		// Avancer le format de la longueur de l'expression
		data->format += expr_len;
		
		// Récupérer la valeur depuis va_list
		// Note: On suppose que les valeurs sont passées dans l'ordre d'apparition
		void *value = va_arg(data->args, void *);
		
		// Pour l'instant, on va simplement afficher la valeur
		// Dans une version finale, il faudrait détecter le type
		count += soraty_putstr("[");
		count += soraty_putstr(var_name);
		count += soraty_putstr(": ");
		
		// Essayer de détecter le type (version simplifiée)
		// On regarde si ça ressemble à une chaîne ou un nombre
		char *str_value = (char *)value;
		int is_numeric = 1;
		int i = 0;
		
		if (str_value && *str_value)
		{
			while (str_value[i])
			{
				if (str_value[i] < '0' || str_value[i] > '9')
				{
					is_numeric = 0;
					break ;
				}
				i++;
			}
		}
		
		if (is_numeric && str_value && *str_value)
		{
			// C'est probablement un nombre
			int num = 0;
			i = 0;
			while (str_value[i])
			{
				num = num * 10 + (str_value[i] - '0');
				i++;
			}
			count += soraty_putnbr(num);
		}
		else
		{
			// C'est probablement une chaîne
			count += soraty_putstr((char *)value);
		}
		
		count += soraty_putstr("]");
		
		free(var_name);
	}
	else
	{
		// Ce n'est pas une expression valide, on affiche normalement
		count += soraty_putchar(*data->format);
		data->format++;
	}
	
	return (count);
}

int	parse_template(t_soraty *data)
{
	int	count;
	
	count = 0;
	while (*data->format)
	{
		if (*data->format == '$' && *(data->format + 1) == '{')
		{
			// On a trouvé le début d'une expression ${}
			count += handle_expression(data);
		}
		else
		{
			// Caractère normal
			count += soraty_putchar(*data->format);
			data->format++;
		}
	}
	return (count);
}