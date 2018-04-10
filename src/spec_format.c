#include "ft_printf.h"

int 	o(t_printf *data, va_list vl, t_type specifier, char **str)
{
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0) && (specifier.ul ==0))
	{
		if(!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if (specifier.ul == 0)
	// if (specifier.ul == 0)
	{
		*str = ft_strdup("0");
		data->flag[0] &= ~flag_hash;
	}
	else if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
	{
		if(!(*str = ft_ulltoa_base(specifier.ul, 8)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if(!(*str = ft_ulltoa_base(specifier.u, 8)))
			exit(EXIT_FAILURE);
	}
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];////
	if (data->flag[2] > ft_strlen(*str))
		data->flag[0] &= ~flag_hash;
	if ((data->flag[0] & flag_hash))
	{
		data->flag[0] &= ~flag_space;
		data->val_prefix = 1;
		if(!(data->str_prefix = ft_strdup("0")))
			exit(EXIT_FAILURE);
	}
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
	return (ft_strlen(*str));
}

int 	x(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0))
	{
		if(!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
	{
		if(!(*str = ft_ulltoa_base(specifier.ul, 16)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if(!(*str = ft_ulltoa_base(specifier.u, 16)))
			exit(EXIT_FAILURE);
	}
	while (++i <= ft_strlen(*str))
		if (data->format[data->format_i] == 'X')
			(*str)[i] = ft_toupper((*str)[i]);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
			data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];////
	if ((data->flag[0] & flag_hash) && (specifier.ul != 0))
	{
		data->flag[0] &= ~flag_space;
		if (data->format[data->format_i] == 'x')
		{
			if(!(data->str_prefix = ft_strdup("0x")))
				exit(EXIT_FAILURE);
		}
		else
		{
			if(!(data->str_prefix = ft_strdup("0X")))
				exit(EXIT_FAILURE);
		}
		data->val_prefix = 2;
	}
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
	return (ft_strlen(*str));
}
