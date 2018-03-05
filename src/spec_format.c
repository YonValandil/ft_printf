#include "ft_printf.h"

void 	o(t_printf *data, va_list vl, t_type specifier)
{

}

void 	O(t_printf *data, va_list vl, t_type specifier)
{

}

void 	u(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;
	char *a;

	i = -1;
	specifier.ul = va_arg(vl, unsigned int);
	apply_modifier(data, &specifier);
	a = ft_ulltoa_base(specifier.u, 10);
	tmp = ft_strlen(a);
	while (++i <= tmp)
		add_to_result(data, a[i], 1);
}

void 	U(t_printf *data, va_list vl, t_type specifer)
{

}

void 	x(t_printf *data, va_list vl, t_type specifier)
{

}

void 	X(t_printf *data, va_list vl, t_type specifier)
{

}
