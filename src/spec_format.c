#include "ft_printf.h"

void 	o(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;
	char *a;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier(data, &specifier, 0);
	if (((data->flag[0] & (1 << flag_l)) / (1 << flag_l)) ||
		((data->flag[0] & (1 << flag_z)) / (1 << flag_z)) ||
		((data->flag[0] & (1 << flag_j)) / (1 << flag_j)))
		a = ft_ulltoa_base(specifier.ul, 8);
	else
		a = ft_ulltoa_base(specifier.u, 8);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}

void 	x(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;
	char *a;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier(data, &specifier, 0);
	if (((data->flag[0] & (1 << flag_l)) / (1 << flag_l)) ||
		((data->flag[0] & (1 << flag_z)) / (1 << flag_z)) ||
		((data->flag[0] & (1 << flag_j)) / (1 << flag_j)))
		a = ft_ulltoa_base(specifier.ul, 16);
	else
		a = ft_ulltoa_base(specifier.u, 16);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}

void 	X(t_printf *data, va_list vl, t_type specifier)
{
	(void)data;
	(void)vl;
	(void)specifier;
}
