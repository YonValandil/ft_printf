#include "ft_printf.h"

void 	s(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;

	i = -1;
	specifier.s = va_arg(vl, char *);
	// apply_modifier(data, &specifier, 1);
	tmp = ft_strlen(specifier.s);
	while (++i <= tmp)
		add_to_result(data, specifier.s[i], 1);
}

void 	c(t_printf *data, va_list vl, t_type specifier)
{
	specifier.c = (char)va_arg(vl, int);
	// apply_modifier(data, &specifier, 1);
	// if (((data->flag[0] & (1 << flag_pre)) / (1 << flag_pre)))
	add_to_result(data, specifier.c, 1);
}


void 	p(t_printf *data, va_list vl, t_type specifier)
{
	(void)data;
	(void)vl;
	(void)specifier;
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
	specifier.u = va_arg(vl, unsigned int);
	apply_modifier(data, &specifier, 0);
	a = ft_ulltoa_base(specifier.u, 10);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}
