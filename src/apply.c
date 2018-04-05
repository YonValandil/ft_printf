/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/04 06:20:54 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
** applique les casts de modificateur de longueur pour les types unsigned
present en argument, et garde le plus grand si plusieurs sont envoyé
**/
void 	apply_modifier_unsigned(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & flag_L))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & flag_j))
		specifier->l = (uintmax_t)specifier->l;
	else if ((data->flag[0] & flag_z))
		specifier->l = (size_t)specifier->l;
	else if ((data->flag[0] & flag_l))
		specifier->l = (unsigned long)specifier->l;
	else if ((data->flag[0] & flag_h))
		specifier->l = (unsigned short)specifier->l;
	else if ((data->flag[0] & flag_hh))
		specifier->l = (unsigned char)specifier->l;
}

/**
** applique les casts de modificateur de longueur pour les types signed
present en argument, et garde le plus grand si plusieurs sont envoyé
**/
void 	apply_modifier_signed(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & flag_L))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & flag_j))
		specifier->l = (intmax_t)specifier->l;
	else if ((data->flag[0] & flag_z))
		specifier->l = (ssize_t)specifier->l;
	else if ((data->flag[0] & flag_l))
		specifier->l = (long)specifier->l;
	else if ((data->flag[0] & flag_h))
		specifier->l = (short)specifier->l;
	else if ((data->flag[0] & flag_hh))
		specifier->l = (char)specifier->l;
}

/**
** recherche dans le tableau d pointeur sur foncion le bon argument envoyé
** en parametre et l'execute.
**/
void 	apply_specifier(t_printf *data, va_list vl)
{
	int i;
	char *str_arg;
	int len_arg;

	i = -2;
	len_arg = 0;
	t_type specifier;
	specifier.l = 0;
	data->val_prefix = 0;
	static int const *const tab_ptr_get_spec[18] =
		{(void*)"s", (void*)&s, (void*)"S", (void*)&S,
		(void*)"p", (void*)&p, (void*)"dDi", (void*)&d,
		(void*)"oO", (void*)&o, (void*)"uU", (void*)&u,
		(void*)"xX", (void*)&x, (void*)"c", (void*)&c,
	(void*)"C", (void*)&C};
	while ((i += 2) < (9 * 2))
		if (ft_strchr((char*)tab_ptr_get_spec[i], data->format[data->format_i]))
			len_arg = ((t_ptr_get_spec)tab_ptr_get_spec[i + 1])(data, vl,
				specifier, &str_arg);
	if ((data->flag[0] & flag_plus) && (data->flag[0] & flag_space))
		data->flag[0] &= ~flag_space;
	if ((data->flag[0] & flag_neg))
		data->flag[0] &= ~flag_zero;
	data->effective_fw = apply_effective_value(data, len_arg);
	apply_print_f(data, str_arg, len_arg);
}

/**
** applique les differentes etapes (obligatoire et optionnel) de printf,
** dans l'ordre:
** 1 - la largeur de champ
** 2 - les prefix
** 3 - la largeur apres les prefix si besoin
** 4 - ajoute la precision
** 5 - la valeur de l'argument dans va_arg
** 6 - et la largeur de champ de fin
**/
void 	apply_print_f(t_printf *data, char *str_arg, int len_arg)
{
	if ((data->flag[0] & flag_width) && !(data->flag[0] & flag_neg)
		&& !((data->flag[0] & flag_plus) && (data->flag[0] & flag_zero))
		&& !((data->flag[0] & flag_hash) && (data->flag[0] & flag_zero)))
	{
		put_n_char_to_result(data, (data->flag[0] & flag_zero)
		? '0' : ' ', data->effective_fw);
	}
	if (data->val_prefix > 0)
		add_str_to_result(data, data->str_prefix, 1);
	if ((data->flag[0] & flag_width) && !(data->flag[0] & flag_neg)
		&& (((data->flag[0] & flag_plus) && (data->flag[0] & flag_zero))
		|| ((data->flag[0] & flag_hash) && (data->flag[0] & flag_zero))))
		put_n_char_to_result(data, '0', data->effective_fw);
	if (data->flag[0] & flag_pre)
		put_n_char_to_result(data, '0', data->effective_pre);
	if (((data->format[data->format_i] == 'c') ||
		(data->format[data->format_i] == 'C')) && !(ft_strlen(str_arg)))
		add_to_result(data, ' ', 2);
	else
		add_str_to_result(data, str_arg, 1);
	if ((data->flag[0] & flag_width) && (data->flag[0] & flag_neg))
		put_n_char_to_result(data, ' ', data->effective_fw);
	ft_memdel((void**)&str_arg);
	ft_memdel((void**)&(data->str_prefix));
}

/**
** calcul les valeurs effective (la valeur reel a appliquer)
** de la precision et de la largeur de champ.
**/
int 	apply_effective_value(t_printf *data, int len_arg)
{
	if (data->flag[0] & flag_pre)
	{
		if ((data->format[data->format_i] == 'c')
		|| (data->format[data->format_i] == 's')
		|| (data->format[data->format_i] == 'C')
		|| (data->format[data->format_i] == 'S'))
		{
			if (data->flag[2] < len_arg)
				data->effective_pre = data->flag[2];
		}
		else
		{
			if (data->flag[2] > len_arg)
				data->effective_pre = data->flag[2] - len_arg;
		}
	}
	if (data->flag[0] & flag_space)
	{
		data->val_prefix = 1;
		data->str_prefix = ft_strdup(" ");
	}
	if (data->flag[0] & flag_width)
		data->effective_fw = data->flag[1] - len_arg -
		data->effective_pre - data->val_prefix;
	return (data->effective_fw);
}
