#include "ft_printf.h"

int 	C(t_printf *data, va_list vl, t_type specifier, char **str)
{
	specifier.lc = va_arg(vl, wchar_t);
	if (!(*str = ft_strnew(4)))
		exit(EXIT_FAILURE);
	if (specifier.lc <= 0x7f)
	{
		(*str)[0] = specifier.lc;
	}
	else if (specifier.lc <= 0xff)
	{
		(*str)[0] = (specifier.lc >> 6) + 0xC0;
		(*str)[1] = (specifier.lc & 0x3F) + 0x80;
	}
	else if (specifier.lc <= 0xffff)
	{
		(*str)[0] = (specifier.lc >> 12) + 0xE0;
		(*str)[1] = ((specifier.lc >> 6) & 0x3F) + 0x80;
		(*str)[2] = (specifier.lc & 0x3F) + 0x80;
		printf("dsccsc`scscscsdsdsdscddsdcdsddc\n");
	}
	else
	{
		(*str)[0] = (specifier.lc >> 18) + 0xF0;
		(*str)[1] = ((specifier.lc >> 12) & 0x3F) + 0x80;
		(*str)[2] = ((specifier.lc >> 6) & 0x3F) + 0x80;
		(*str)[3] = (specifier.lc & 0x3F) + 0x80;
	}
	return (ft_strlen(*str));
}

int 	S(t_printf *data, va_list vl, t_type specifier, char **str)
{
	(void)data;
	(void)vl;
	(void)specifier;
	return 2;
}
