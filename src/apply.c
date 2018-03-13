/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/13 07:22:04 by jjourne          ###   ########.fr       */
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

// void 		ft_printf_precision(t_printf *data)
// {

// }

// void 		ft_printf_field_with(t_printf *data)
// {
	//FIELD WITH:
	//--need precision effective,
	//--need nbr de digit (ici nbr_digit),
	// - preffix

	//si FW des le debut: (flag 0 ou pas peut importe)

	//si apres prefix (avec flag 0 sinon impossible)
	//----------------

	//PRECISION:
	//-- effet sur les chiffres si plus grand
	//-- effet sur les textes si plus petit

	//----------------

	//FIELD WITH:
	//si a la fin (avec flag 0 et - mettre des espaces)

	//----------------
// }
