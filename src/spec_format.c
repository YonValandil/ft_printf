#include "ft_printf.h"

void 	o(t_printf *data, va_list vl, t_type specifier)
{
	(void)data;
	(void)vl;
	(void)specifier;
}

void 	x(t_printf *data, va_list vl, t_type specifier)
{
	char *a;

	specifier.d = va_arg(vl, int);
	printf("val x = %ld\n", specifier.d);
	a = ft_lltoa_base(specifier.d, 16);
	printf("val a = %s\n", a);
	// apply_modifier(data, &specifier, 0);
}

void 	X(t_printf *data, va_list vl, t_type specifier)
{
	(void)data;
	(void)vl;
	(void)specifier;
}
