#include "ft_printf.h"

int 	o(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
		*str = ft_ulltoa_base(specifier.ul, 8);
	else
		*str = ft_ulltoa_base(specifier.u, 8);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	if (data->flag[0] & flag_zero)
		data->flag[0] &= ~flag_zero;
	if (data->flag[0] & flag_plus)
		data->flag[0] &= ~flag_plus;
	if (data->flag[2] > ft_strlen(*str))
		data->flag[0] &= ~flag_hash;
	if ((data->flag[0] & flag_hash) && (specifier.ul != 0))
	{
		data->flag[0] &= ~flag_space;
		data->val_prefix = 1;
		data->str_prefix = ft_strdup("0");
	}
	if (data->flag[0] & flag_pre)
		data->flag[0] &= ~flag_zero;
	return (ft_strlen(*str));
}

int 	x(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
		*str = ft_ulltoa_base(specifier.ul, 16);
	else
		*str = ft_ulltoa_base(specifier.u, 16);
	while (++i <= ft_strlen(*str))
		if (data->format[data->format_i] == 'X')
			(*str)[i] = ft_toupper((*str)[i]);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
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
	if (data->flag[0] & flag_pre)
		data->flag[0] &= ~flag_zero;
	return (ft_strlen(*str));
}
