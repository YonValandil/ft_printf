#include "ft_printf.h"

void 	o(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int nbr_digit;
	char *str;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		str = ft_ulltoa_base(specifier.ul, 8);
	else
		str = ft_ulltoa_base(specifier.u, 8);
	nbr_digit = ft_strlen(str);
	while (++i <= nbr_digit)
		add_to_result(data, str[i], 1);
}

void 	x(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int nbr_digit;
	char *str;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		str = ft_ulltoa_base(specifier.ul, 16);
	else
		str = ft_ulltoa_base(specifier.u, 16);
	nbr_digit = ft_strlen(str);
	while (++i <= nbr_digit)
	{
		if (data->format[data->format_i] == 'X')
			str[i] = ft_toupper(str[i]);
		add_to_result(data, str[i], 1);
	}
}
