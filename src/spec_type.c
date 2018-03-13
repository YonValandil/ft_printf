#include "ft_printf.h"

void 	s(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int len;

	i = -1;
	specifier.s = va_arg(vl, char *);
	len = ft_strlen(specifier.s);
	while (++i <= len)
		add_to_result(data, specifier.s[i], 1);
}

void 	c(t_printf *data, va_list vl, t_type specifier)
{
	specifier.c = (char)va_arg(vl, int);
	add_to_result(data, specifier.c, 1);
}

void 	p(t_printf *data, va_list vl, t_type specifier)
{
	char *str;
	int nbr_digit;
	int i;

	i = -1;
	specifier.l = va_arg(vl, unsigned long);
	str = ft_lltoa_base(specifier.l, 16);
	nbr_digit = ft_strlen(str);
	add_to_result(data, '0', 1);
	add_to_result(data, 'x', 1);
	while (++i <= nbr_digit)
		add_to_result(data, str[i], 1);
}

void 	d(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	char *str;
	int nb_digit;
	int val_prefix;
	int effective_pre;
	int effective_fw;

	i = -1;
	specifier.l = va_arg(vl, long);
	apply_modifier_signed(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)) || (data->flag[0] & (1 << flag_z)) ||
		(data->flag[0] & (1 << flag_j)))
		str = ft_lltoa_base(specifier.l, 10);
	else
		str = ft_lltoa_base(specifier.d, 10);
	nb_digit = ft_strlen(str);
	effective_fw = apply_effective_value(data,
		&effective_pre, &val_prefix, nb_digit);

	

	while (++i <= nb_digit)
		add_to_result(data, str[i], 1);
}

void 	u(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int nbr_digit;
	char *str;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long int);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & (1 << flag_l)))
		str = ft_ulltoa_base(specifier.ul, 10);
	else
		str = ft_ulltoa_base(specifier.u, 10);
	nbr_digit = ft_strlen(str);
	while (++i <= nbr_digit)
		add_to_result(data, str[i], 1);
}
