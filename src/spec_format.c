#include "ft_printf.h"

int 	o(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int len_arg;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
		*str = ft_ulltoa_base(specifier.ul, 8);
	else
		*str = ft_ulltoa_base(specifier.u, 8);
	len_arg = ft_strlen(*str);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= len_arg))
		data->flag[0] &= ~flag_pre;
	if (data->flag[0] & flag_zero)
		data->flag[0] &= ~flag_zero;
	if (data->flag[0] & flag_plus)
		data->flag[0] &= ~flag_plus;
	if (data->flag[2] > len_arg)
		data->flag[0] &= ~flag_hash;
	if ((data->flag[0] & flag_hash) && (specifier.ul != 0))
	{
		data->flag[0] &= ~flag_space;
		data->val_prefix = 1;
		data->str_prefix = ft_strdup("0");
	}
	return (len_arg);
}

int 	x(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int len_arg;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
		*str = ft_ulltoa_base(specifier.ul, 16);
	else
		*str = ft_ulltoa_base(specifier.u, 16);
	len_arg = ft_strlen(*str);
	while (++i <= len_arg)
		if (data->format[data->format_i] == 'X')
			(*str)[i] = ft_toupper((*str)[i]);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= len_arg))
			data->flag[0] &= ~flag_pre;
	if ((data->flag[0] & flag_plus))
			data->flag[0] &= ~flag_plus;
	if (data->flag[0] & flag_hash)
	{
		data->flag[0] &= ~flag_space;
		data->str_prefix = (data->format[data->format_i] == 'x') ?
			ft_strdup("0x") : ft_strdup("0X");
		data->val_prefix = 2;
	}
	return (ft_strlen(*str));
}
