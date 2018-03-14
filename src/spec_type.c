#include "ft_printf.h"

int 	s(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int len_arg;

	i = -1;
	specifier.s = va_arg(vl, char *);
	len_arg = ft_strlen(specifier.s);
	while (++i <= len_arg)
		add_to_result(data, specifier.s[i], 1);
	return (len_arg);
	if ((data->flag[0] & (1 << flag_plus)))
		data->flag[0] &= ~(1 << flag_plus);
	if ((data->flag[0] & (1 << flag_zero)))
		data->flag[0] &= ~(1 << flag_zero);
	if ((data->flag[0] & (1 << flag_hash)))
		data->flag[0] &= ~(1 << flag_hash);
	if ((data->flag[0] & (1 << flag_space)))
		data->flag[0] &= ~(1 << flag_space);
}

int 	c(t_printf *data, va_list vl, t_type specifier, char **str)
{
	specifier.c = (char)va_arg(vl, int);
	if ((data->flag[0] & (1 << flag_plus)))
		data->flag[0] &= ~(1 << flag_plus);
	if ((data->flag[0] & (1 << flag_zero)))
		data->flag[0] &= ~(1 << flag_zero);
	if ((data->flag[0] & (1 << flag_hash)))
		data->flag[0] &= ~(1 << flag_hash);
	if ((data->flag[0] & (1 << flag_space)))
		data->flag[0] &= ~(1 << flag_space);
	return (1);
}

int 	p(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int len_arg;
	int i;

	i = -1;
	specifier.l = va_arg(vl, unsigned long);
	*str = ft_lltoa_base(specifier.l, 16);
	len_arg = ft_strlen(*str);
	add_to_result(data, '0', 1);
	add_to_result(data, 'x', 1);
	return (len_arg);
}

int 	d(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.l = va_arg(vl, long);
	apply_modifier_signed(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		*str = ft_lltoa_base(specifier.l, 10);
	else
		*str = ft_lltoa_base(specifier.d, 10);
	if ((data->flag[0] & (1 << flag_hash)))
			data->flag[0] &= ~(1 << flag_hash);
	if ((data->flag[0] & (1 << flag_plus)))
			; //modifier lltoa_base pour le signe
	return (ft_strlen(*str));
}

int 	u(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long int);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)))
		*str = ft_ulltoa_base(specifier.ul, 10);
	else
		*str = ft_ulltoa_base(specifier.u, 10);
	return (ft_strlen(*str));
}
