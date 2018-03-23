#include "ft_printf.h"

void	get_flag(t_printf *data)
{
	int i;
	int *j;

	j = &(data->format_i);
	while (ft_strchr(FLAG, data->format[++(*j)]) && (i = -1))
	{
		while (++i <= 11)
			if (data->format[*j] != 'h')
				data->flag[0] |= (data->format[*j] == FLAG[i]) << i;
		if (data->format[*j] == 'h' && (data->flag[0] |= flag_hh))
			data->flag[0] ^= (data->flag[0] & flag_h) ? 1 << 6 : 3 << 5;
		if (ft_isdigit(data->format[*j]) && (data->format[*j] != '0') &&
			(data->flag[0] |= flag_width) && !(data->flag[1] = 0))
		{
			--*j;
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[1] = data->flag[1] * 10 + data->format[*j] - '0';
		}
		if ((data->format[*j] == '.') && !(data->flag[2] = 0))
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[2] = data->flag[2] * 10 + data->format[*j] - '0';
	}
	if (data->format[*j] == 'D' || data->format[*j] == 'O' ||
		data->format[*j] == 'U')
		data->flag[0] |= flag_l;
}

void 	percent_case(t_printf *data)
{
	if (!(data->flag[0] & flag_neg))
	{
		put_n_char_to_result(data, ' ', data->flag[1] - 1);
		add_to_result(data, '%', 1);
	}
	else
	{
		add_to_result(data, '%', 1);
		put_n_char_to_result(data, ' ', data->flag[1] - 1);
	}
}
void	parser(t_printf *data, va_list vl)
{
	t_bool	is_flag;

	while ((data->format[++(data->format_i)]) && !(is_flag = false))
	{
		if(data->format[data->format_i] == '%' && (is_flag = true))
		{
			data->flag[0] = 0;
			get_flag(data);
			if (ft_strchr(SPECIFIER, data->format[data->format_i]))
				apply_specifier(data, vl);
			else if (data->format[data->format_i] == '%')
				percent_case(data);
			else
				add_to_result(data, 'c', 0);
		}
		else
			add_to_result(data, 'c', 0);
	}
}
