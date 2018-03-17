#include "ft_printf.h"

int 	C(t_printf *data, va_list vl, t_type specifier, char **str)
{
	(void)data;
	(void)vl;
	(void)specifier;
	return 4;
}

int 	S(t_printf *data, va_list vl, t_type specifier, char **str)
{
	(void)data;
	(void)vl;
	(void)specifier;
	return 2;
}
