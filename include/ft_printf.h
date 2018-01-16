/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:42:49 by jjourne           #+#    #+#             */
/*   Updated: 2018/01/16 23:21:30 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"


#define SPECIFIER “sSpdDioOuUxXcC”
#define FLAG “0123456789 -+#”
#define MODIFIER "hlLjz" //manque: q | t

typedef struct		s_result
{
	char			buf[444];
}					t_result;

typedef struct		s_printf
{
	t_result		result;
	int				total;
}					t_printf;

/**
** parcourt la str(chaine de format) passé en arguments de printf,
** determine si on a un: (1)caractere simple, (2)caractere d'echappement '\', (3)caractere de specfication de format '%'
** (1): aucune modification, l'afficher sur la sortie standard
** (2): converti en caractere simple le char suivant, et l'afficher sur la sortie standard
** (3): traitement de l'argument a envoyer en fonction des attributs: flags, field with, precision, format(modifieur/specifieur)
**
** ARGUMENT EN ENTRE: la structure printf, la va_list
**
** TYPE DE RETOUR:
**/
int		parser(t_printf *print, va_list vl);


#endif
