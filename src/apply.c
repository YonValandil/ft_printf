/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/06 11:40:28 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	apply_modifier(t_printf *data, t_type *specifier)
{
	if (((data->flag[0] & (1 << flag_hh)) / (1 << flag_hh)))
		specifier->l = (char)specifier->l;
	if (((data->flag[0] & (1 << flag_h)) / (1 << flag_h)))
		specifier->l = (short)specifier->l;
	if (((data->flag[0] & (1 << flag_l)) / (1 << flag_l)))
		specifier->l = (long)specifier->l;
	if (((data->flag[0] & (1 << flag_z)) / (1 << flag_z)))
		specifier->l = (size_t)specifier->l;
	if (((data->flag[0] & (1 << flag_j)) / (1 << flag_j)))
		specifier->l = (intmax_t)specifier->l;
	if (((data->flag[0] & (1 << flag_L)) / (1 << flag_L)))
			specifier->l = (long double)specifier->l;
}

void 	apply_specifier(t_printf *data, va_list vl)
{
	int i = -1;
	t_type specifier;
	t_ptr_get_spec *tab_ptr_get_spec;

	specifier.l = 0;
	tab_ptr_get_spec = (t_ptr_get_spec[14]){&s, &S, &p, &d, &D, &o, &O,
		&u, &U, &x, &X, &c, &C};
	while (++i < 12)
		if (data->format[data->format_i] == SPECIFIER[i])
			tab_ptr_get_spec[i](data, vl, specifier);
	if (data->format[data->format_i] == 'i')
		tab_ptr_get_spec[3](data, vl, specifier);
	//affichage de debug
	print_flag(data);
	printf("\n-------------------------------------\n\n");
}

void 	  apply_attribut()
{
}

// void 	ptr_apply_zero(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_neg(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_plus(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_space(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_hash(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_precision(t_data *data, vl)
// {
//
// }
//
// void 	ptr_apply_with(t_data *data, vl)
// {
//
// }
