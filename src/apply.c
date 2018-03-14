/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/14 17:01:08 by jjourne          ###   ########.fr       */
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

	//field width begin

	//prefix

	//field width after prefix

	//precision

	//val arg
	add_str_to_result(data, str_arg, 1);

	//field width end
}

int 	apply_effective_value(t_printf *data, int len_arg) //si flag - pas mettre le flag 0
{
	if ((data->flag[0] & (1 << flag_pre)))
		if (data->flag[2] > len_arg)
			data->effective_pre = data->flag[2] - len_arg;
	if ((data->flag[0] & (1 << flag_plus)))
		data->val_prefix += 1;
	if ((data->flag[0] & (1 << flag_space)))
		data->val_prefix += 1;
	// if () { //pour le hash
	// }
	if ((data->flag[0] & (1 << flag_with)))
		data->effective_fw = data->flag[1] - len_arg - data->effective_pre - data->val_prefix;

	printf("\n-----> value nbr_digit = %d\n", len_arg);
	printf("-----> value_preffix = %d\n", data->val_prefix);
	printf("-----> effective_pre = %d\n", data->effective_pre);
	printf("\n-----> effective_fw = %d\n", data->effective_fw);
	return (data->effective_fw);
}
