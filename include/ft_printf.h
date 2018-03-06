/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:42:49 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/06 20:10:45 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# include <stdio.h>

# define BUF_SIZE 1
# define SPECIFIER "sSpdouxXcCiDOU"
# define FLAG "0-+ #hhjlzL.123456789"

enum {flag_zero = 0, flag_neg, flag_plus, flag_space, flag_hash, flag_hh,
	flag_h, flag_j, flag_l, flag_z, flag_L, flag_pre, flag_with};

typedef enum 		e_bool
{
	false = 0,
	true
}					t_bool;

typedef union		u_type
{
    char c;
    unsigned char uc;
    short sh;
	unsigned int u;
	unsigned long int ul;
	unsigned long long int ull;
	long long ll;
	long double ldb;
    long l;
    float f;
    int d;
	char* s;
}					t_type;

/**
** structure qui sert de node pour la liste chainée(queue):
** on enregistre le resultat traité de la chaine de format au fur et a mesure
** dans buf, et si le buffer n'est pas assez gros on creer un nouveau maillon.
** buf: stockage du resultat de printf.
**/
typedef struct		s_result
{
	char			buf[BUF_SIZE + 1];
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
	t_result		*result_start;
	t_result		*result_end;
	int				result_i;
	int				format_i;
	int				flag[3];
}					t_printf;

typedef void (*t_ptr_get_spec)(t_printf *, va_list, t_type specifier);

void apply_modifier(t_printf *data, t_type *specifier, int sign);
void apply_specifier(t_printf *data, va_list vl);

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
void	get_flag(t_printf *print);

/**
** creer/update la list chainee, et store le bon caractere dans le buffer.
** si flag == 0 alors on prend le caractere dans la chaine de format
** sinon on envoi le caractere manuellement
**/
void 	add_to_result(t_printf *data, char c, int flag);

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

/**
** Toutes les declarations des specifiers en pointeurs de fonctions
**/

void 	s(t_printf *data, va_list vl, t_type specifier);
void 	S(t_printf *data, va_list vl, t_type specifier);
void 	p(t_printf *data, va_list vl, t_type specifier);
void 	d(t_printf *data, va_list vl, t_type specifier);
void 	D(t_printf *data, va_list vl, t_type specifier);
void 	S(t_printf *data, va_list vl, t_type specifier);
void 	o(t_printf *data, va_list vl, t_type specifier);
void 	O(t_printf *data, va_list vl, t_type specifier);
void 	u(t_printf *data, va_list vl, t_type specifier);
void 	U(t_printf *data, va_list vl, t_type specifier);
void 	x(t_printf *data, va_list vl, t_type specifier);
void 	X(t_printf *data, va_list vl, t_type specifier);
void 	c(t_printf *data, va_list vl, t_type specifier);
void 	C(t_printf *data, va_list vl, t_type specifier);

#endif
