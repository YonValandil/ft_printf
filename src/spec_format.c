#include "ft_printf.h"

int 	o(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		*str = ft_ulltoa_base(specifier.ul, 8);
	else
		*str = ft_ulltoa_base(specifier.u, 8);
	return (ft_strlen(*str));
}

int 	x(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int len_arg;

	if (data->flag[0] && (1 << flag_hash))
		data->prefix = (data->format[data->format_i] == 'x') ? "Ox" : "OX";
	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		*str = ft_ulltoa_base(specifier.ul, 16);
	else
		*str = ft_ulltoa_base(specifier.u, 16);
	len_arg = ft_strlen(*str);
	while (++i <= len_arg)
		if (data->format[data->format_i] == 'X')
			(*str)[i] = ft_toupper((*str)[i]);
	return (ft_strlen(*str));
}
