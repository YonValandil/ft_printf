#include "ft_printf.h"

void	get_flag(t_printf *data)
{
	int i;
	int *j;

	data->flag[0] = 0;
	j = &(data->format_i);
	while (ft_strchr(FLAG, data->format[++(*j)]) && (i = -1))
	{
		while (++i <= flag_pre)
			if (data->format[*j] != 'h')
				data->flag[0] |= (data->format[*j] == FLAG[i]) << i;
		if (data->format[*j] == 'h' && (data->flag[0] |= (1 << flag_hh)))
			data->flag[0] ^= (data->flag[0] & 1 << flag_h) ? 1 << 6 : 3 << 5;
		if (ft_isdigit(data->format[*j]) && (data->format[*j] != '0') && (--*j))
		{
			data->flag[0] |= (1 << flag_with);
			data->flag[1] = 0;
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[1] = data->flag[1] * 10 + data->format[*j] - '0';
		}
		if ((data->format[*j] == '.') && !(data->flag[2] = 0))
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[2] = data->flag[2] * 10 + data->format[*j] - '0';
	}
	if (data->format[*j] == 'D')
		data->flag[0] |= (1 << flag_l);
}

void	parser(t_printf *data, va_list vl)
{
	t_bool	is_flag;

	while ((data->format[++(data->format_i)]) && !(is_flag = false))
	{
		if(data->format[data->format_i] == '%' && (is_flag = true))
		{
			get_flag(data);
			if (ft_strchr(SPECIFIER, data->format[data->format_i]))
				apply_specifier(data, vl);
			else
				add_to_result(data, 'c', 0);
		}
		else
		{
			add_to_result(data, 'c', 0);
		}
	}
}
