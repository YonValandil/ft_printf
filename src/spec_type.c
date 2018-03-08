#include "ft_printf.h"

void 	s(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;

	i = -1;
	specifier.s = va_arg(vl, char *);
	tmp = ft_strlen(specifier.s);
	while (++i <= tmp)
		add_to_result(data, specifier.s[i], 1);
}

void 	c(t_printf *data, va_list vl, t_type specifier)
{
	specifier.c = (char)va_arg(vl, int);
	// if (((data->flag[0] & (1 << flag_pre)) / (1 << flag_pre)))
	add_to_result(data, specifier.c, 1);
}

void 	p(t_printf *data, va_list vl, t_type specifier)
{
	char *a;
	int tmp;
	int i;

	i = -1;
	specifier.l = va_arg(vl, unsigned long);
	a = ft_lltoa_base(specifier.l, 16);
	tmp = ft_strlen(a);
	add_to_result(data, '0', 1);
	add_to_result(data, 'x', 1);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}

void 	d(t_printf *data, va_list vl, t_type specifier)
{
	char *a;
	int tmp;
	int i;

	i = -1;
	specifier.l = va_arg(vl, long);
	apply_modifier(data, &specifier, 1);
	if (((data->flag[0] & (1 << flag_l)) / (1 << flag_l)) ||
		((data->flag[0] & (1 << flag_z)) / (1 << flag_z)) ||
		((data->flag[0] & (1 << flag_j)) / (1 << flag_j)))
		a = ft_lltoa_base(specifier.l, 10);
	else
		a = ft_lltoa_base(specifier.d, 10);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}

void 	u(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;
	char *a;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long int);
	apply_modifier(data, &specifier, 0);
	if (((data->flag[0] & (1 << flag_l)) / (1 << flag_l)))
		a = ft_ulltoa_base(specifier.ul, 10);
	else
		a = ft_ulltoa_base(specifier.u, 10);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}
