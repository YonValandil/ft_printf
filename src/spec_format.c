#include "ft_printf.h"

void 	o(t_printf *data, va_list vl, t_type specifier)
{
	(void)data;
	(void)vl;
	(void)specifier;
}

void 	x(t_printf *data, va_list vl, t_type specifier)
{
	int i;
	int tmp;
	char *a;

	specifier.d = va_arg(vl, int);
	printf("val x = %ld\n", specifier.d);
	a = ft_lltoa_base(specifier.d, 16);
	printf("val x2 = %ld\n", specifier.d);
	printf("val a = %s\n", a);

	// apply_modifier(data, &specifier, 0);
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
