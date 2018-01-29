/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:42:49 by jjourne           #+#    #+#             */
/*   Updated: 2018/01/21 06:53:06 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# include <stdio.h>

# define BUFF_SIZE 5 //un ou 2 f?
# define SPECIFIER "sSpdDioOuUxXcC" //float et binary?
# define FLAG "0-+ #123456789.hlLjz" //manque: q et t

typedef enum 		e_flag
{
	e_flag_zero = 0,
	e_flag_neg,
	e_flag_plus,
	e_flag_space,
	e_flag_hash,
	e_flag_with,
	e_flag_pre,
	e_flag_spe
}					t_flag;

/**
** structure qui sert de node pour la liste chainée(queue):
** on enregistre le resultat traité de la chaine de format au fur et a mesure
** dans buf, et si le buffer n'est pas assez gros on creer un nouveau maillon.
** buf: stockage du resultat de printf.
**/
typedef struct		s_result
{
	char			buf[BUFF_SIZE + 1];
	struct s_result	*next;
}					t_result;

/**
** structure general de la fonction:
** format: chaine de caractere de ft_printf a traiter
** t_result begin/end: pointeurs vers la liste chainée
** int flag[3]:
** flag[0] -> tous les flags à activés ou non
** flag[1] -> la largeur de champ
** flag[2] -> la precision
**/
typedef struct		s_printf
{
	char			*format;
	t_result		*res_begin;
	t_result		*res_end;
	int				flag[3];
}					t_printf;

/**
** parcourt la str(chaine de format) passé en arguments de ft_printf,
** determine si on a un: (1)caractere simple, (2)caractere d'echappement '\', (3)caractere de specfication de format '%'
** (1): aucune modification, l'afficher sur la sortie standard
** (2): converti en caractere simple le char suivant, et l'afficher sur la sortie standard
** (3): traitement de l'argument a envoyer en fonction des attributs: flags, field with, precision, format(modifieur/specifieur)
**
** ARGUMENT EN ENTRE: structure printf, va_list
** TYPE DE RETOUR: void
**/
void	parser(t_printf *print, va_list vl);

/**
** parcourt la chaine format (apres le %) et store les valeurs adequates
** dans flag[0] flag[1] et flag[2], jusqu'a tomber sur un caractere non flag.
**/
int		get_flag(t_printf *print, int j, int i);

/**
** fonction principale:
** creer la valist initialize les parametres et appel les autres sous fonctions.
**/
int		ft_printf(const char *format, ...);

/**
** fonction pour supprimer la liste chainee qui contient le buffer du resultat
**/
void 	del_list(t_result *lst);

/**
** fonctions d'affichage pour le debug
**/
void 	print_flag(t_printf *data);
void 	print_lst(t_printf *data);
void 	print_format(t_printf *data);

#endif
