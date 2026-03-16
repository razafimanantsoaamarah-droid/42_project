/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soraty.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:31:42 by maherraz          #+#    #+#             */
/*   Updated: 2026/03/16 11:00:00 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORATY_H
# define SORATY_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define BUFFER_SIZE 4096

typedef struct s_soraty
{
    va_list     args;
    int         count;
    const char  *format;
    char        *buffer;
    int         buf_index;
}   t_soraty;

// Fonctions principales
int		soraty(const char *format, ...);

// Fonctions d'affichage de base
int		soraty_putchar(char c);
int		soraty_putstr(char *str);
int		soraty_putnbr(int number);
int		soraty_putnbr_unsigned(unsigned int nb);
int		soraty_print_hex(unsigned int n, int maj);
int		soraty_print_pointer(void *ptr);

// Nouvelles fonctions pour le template literal
int		parse_template(t_soraty *data);
int		handle_expression(t_soraty *data);
int		print_value(t_soraty *data, void *value, char type);
char	*extract_expression(const char *format, int *len);

#endif