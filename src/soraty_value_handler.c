/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty_value_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:00:00 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 11:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soraty.h"

// Détection automatique du type de la valeur
static char	detect_type(void *value)
{
	// Cette fonction est un défi car en C on ne peut pas détecter le type dynamiquement
	// Solution : utiliser un système de tags ou passer le type en paramètre
	// Pour l'instant, on va supposer que c'est une chaîne ou un entier selon le contexte
	// Dans une vraie implémentation, il faudrait que l'utilisateur spécifie le type
	return ('s'); // Par défaut, on traite comme string
}

int	print_value(t_soraty *data, void *value, char type)
{
	int	count;

	count = 0;
	// Si le type n'est pas spécifié, on essaie de le détecter
	if (type == 0)
		type = detect_type(value);
	
	if (type == 's')
		count += soraty_putstr((char *)value);
	else if (type == 'd' || type == 'i')
		count += soraty_putnbr(*(int *)value);
	else if (type == 'u')
		count += soraty_putnbr_unsigned(*(unsigned int *)value);
	else if (type == 'x')
		count += soraty_print_hex(*(unsigned int *)value, 0);
	else if (type == 'X')
		count += soraty_print_hex(*(unsigned int *)value, 1);
	else if (type == 'p')
		count += soraty_print_pointer(value);
	else if (type == 'c')
		count += soraty_putchar(*(char *)value);
	
	return (count);
}

// Version améliorée avec détection basée sur l'ordre des arguments
int	handle_expression_by_position(t_soraty *data, int arg_index)
{
	// Cette fonction suppose que les arguments sont passés dans l'ordre
	// et que le type est déterminé par le contexte d'utilisation
	
	// Pour l'instant, on va juste prendre l'argument suivant
	void *arg = va_arg(data->args, void *);
	
	// Dans une version plus avancée, on pourrait avoir un tableau de types
	// passé en paramètre ou utiliser des macros
	
	return (soraty_putstr("[")); // Délimiteur visuel temporaire
	// return (print_value(data, arg, 's')); // À décommenter quand la détection fonctionne
}