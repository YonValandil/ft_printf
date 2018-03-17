/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/17 05:23:41 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	apply_modifier_unsigned(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & (1 << flag_L)))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & (1 << flag_j)))
		specifier->l = (uintmax_t)specifier->l;
	else if ((data->flag[0] & (1 << flag_z)))
		specifier->l = (size_t)specifier->l;
	else if ((data->flag[0] & (1 << flag_l)))
		specifier->l = (unsigned long)specifier->l;
	else if ((data->flag[0] & (1 << flag_h)))
		specifier->l = (unsigned short)specifier->l;
	else if ((data->flag[0] & (1 << flag_hh)))
		specifier->l = (unsigned char)specifier->l;
}

void 	apply_modifier_signed(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & (1 << flag_L)))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & (1 << flag_j)))
		specifier->l = (intmax_t)specifier->l;
	else if ((data->flag[0] & (1 << flag_z)))
		specifier->l = (ssize_t)specifier->l;
	else if ((data->flag[0] & (1 << flag_l)))
		specifier->l = (long)specifier->l;
	else if ((data->flag[0] & (1 << flag_h)))
		specifier->l = (short)specifier->l;
	else if ((data->flag[0] & (1 << flag_hh)))
		specifier->l = (char)specifier->l;
}

void 	apply_specifier(t_printf *data, va_list vl)
{
	int i;
	char *str_arg;
	int len_arg;

	i = -2;
	len_arg = 0;
	t_type specifier;
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
	data->effective_fw = apply_effective_value(data, len_arg);

	//attributs regles generales
	if ((data->flag[0] & (1 << flag_plus) && (data->flag[0] & (1 << flag_space)))) //si flag + ET flag_space, ALORS flag_space est ecrasé
		data->flag[0] &= ~(1 << flag_space);
	if ((data->flag[0] & (1 << flag_neg)) || (data->flag[0] & (1 << flag_pre))) //si flag - OU flag_pre, ALORS flag 0 est ecrasé
		data->flag[0] &= ~(1 << flag_zero);
		if ((data->format[data->format_i] == 'c') || (data->format[data->format_i] == 's')
		|| (data->format[data->format_i] == 'C') || (data->format[data->format_i] == 'S'))
			data->flag[0] |= (1 << flag_zero);
//-------------------------------------------------

	//field width, begin
	if ((data->flag[0] & (1 << flag_with))
		&& !(data->flag[0] & (1 << flag_neg))
		&& !((data->flag[0] & (1 << flag_plus)) && (data->flag[0] & (1 << flag_zero)))//si flag + ET flag 0, la fw est apres le prefix
		&& !((data->flag[0] & (1 << flag_hash)) && (data->flag[0] & (1 << flag_zero))))//si flag # ET flag 0, la fw est apres le prefix
			put_n_char_to_result(data, ((data->flag[0] & (1 << flag_zero)) ? '0' : ' '), data->effective_fw);
	//-------------------------------------------------

	//prefix
	// data->str_prefix = ft_strdup("a");
		if (data->val_prefix > 0)
			add_str_to_result(data, data->str_prefix, 1);
	//-------------------------------------------------

	//field width, after prefix
	if ((data->flag[0] & (1 << flag_with)) //si fw exist
		&& !(data->flag[0] & (1 << flag_neg)) //si pas de flag -
		&& (((data->flag[0] & (1 << flag_plus)) && (data->flag[0] & (1 << flag_zero)))
		|| ((data->flag[0] & (1 << flag_hash)) && (data->flag[0] & (1 << flag_zero)))))
		(data->flag[0] & (1 << flag_zero)) ?
			put_n_char_to_result(data, '0', data->effective_fw) :
			put_n_char_to_result(data, ' ', data->effective_fw);
	//-------------------------------------------------

	//precision
	if ((data->flag[0] & (1 << flag_pre)))
		put_n_char_to_result(data, '0', data->effective_pre);
	//-------------------------------------------------

	//val arg
	add_str_to_result(data, str_arg, 1);
	//-------------------------------------------------

	//field width, end
	if ((data->flag[0] & (1 << flag_with)) && (data->flag[0] & (1 << flag_neg)))
		put_n_char_to_result(data, ' ', data->effective_fw);
	ft_memdel((void**)&str_arg);
	ft_memdel((void**)&(data->str_prefix));
	//-------------------------------------------------
}

int 	apply_effective_value(t_printf *data, int len_arg)
{
	if ((data->flag[0] & (1 << flag_pre)))
	{
		if ((data->format[data->format_i] == 'c') || (data->format[data->format_i] == 's')
		|| (data->format[data->format_i] == 'C') || (data->format[data->format_i] == 'S'))
			if (data->flag[2] < len_arg)
				data->effective_pre = data->flag[2];
		else
			if (data->flag[2] > len_arg)
				data->effective_pre = data->flag[2] - len_arg;
	}
	if ((data->flag[0] & (1 << flag_space)))
	{
		data->val_prefix = 1;
		data->str_prefix = ft_strdup(" ");
	}
	if ((data->flag[0] & (1 << flag_with)))
		data->effective_fw = data->flag[1] - len_arg - data->effective_pre - data->val_prefix;
	return (data->effective_fw);
}
