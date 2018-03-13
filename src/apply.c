/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/13 19:40:59 by jjourne          ###   ########.fr       */
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
	int i = -2;
	t_type specifier;
	static void const *const tab_ptr_get_spec[18] =
		{(void*)"s", (void*)&s, (void*)"S", (void*)&S,
		(void*)"p", (void*)&p, (void*)"dDi", (void*)&d,
		(void*)"oO", (void*)&o, (void*)"uU", (void*)&u,
		(void*)"xX", (void*)&x, (void*)"c", (void*)&c,
		(void*)"C", (void*)&C};
	while ((i += 2) < (9 * 2))
		if (ft_strchr((char*)tab_ptr_get_spec[i], data->format[data->format_i]))
			((t_ptr_get_spec)tab_ptr_get_spec[i + 1])(data, vl, specifier);
}

int 	apply_effective_value(t_printf *data, int *eff_pre, //si flag - pas mettre le flag 0
	int *val_prefix, int nb_digit) //gerer en amont les exceptions, desactive les flags etc..
{
	int eff_fw;

	*eff_pre = 0;
	eff_fw = 0;
	*val_prefix = 0;
	if ((data->flag[0] & (1 << flag_pre)))
		if (data->flag[2] > nb_digit)
			*eff_pre = data->flag[2] - nb_digit;
	if ((data->flag[0] & (1 << flag_plus))) //pour nbr signe
		*val_prefix += 1;
	if ((data->flag[0] & (1 << flag_space)))//pour nbr signe
		*val_prefix += 1;
	// if ((data->flag[0] & (1 << flag_hash)))//pour nbr signe
		// *val_prefix += 2;
	//le #: hexa (+2 sauf si nbr 0), octal ?|
	// if ((data->flag[0] & (1 << flag_x)))
		// *val_prefix += 2;
	if ((data->flag[0] & (1 << flag_with)))
		eff_fw = data->flag[1] - nb_digit - *eff_pre - *val_prefix;

	printf("\n-----> value nbr_digit = %d\n", nb_digit);
	printf("-----> value_preffix = %d\n", *val_prefix);
	printf("-----> effective_pre = %d\n", *eff_pre);
	printf("\n-----> effective_fw = %d\n", eff_fw);
	return (eff_fw);
}
