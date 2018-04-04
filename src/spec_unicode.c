#include "ft_printf.h"

void put_unicode(wchar_t wchar, char **str, int *i)
{
	if (wchar <= 0x7f)
		(*str)[*i] = wchar;
	else if (wchar <= 0x7ff)
	{
		(*str)[*i] = (wchar >> 6) + 0xC0;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
	else if (wchar <= 0xffff)
	{
		(*str)[*i] = (wchar >> 12) + 0xE0;
		(*str)[++(*i)] = ((wchar >> 6) & 0x3F) + 0x80;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		(*str)[*i] = (wchar >> 18) + 0xF0;
		(*str)[++(*i)] = ((wchar >> 12) & 0x3F) + 0x80;
		(*str)[++(*i)] = ((wchar >> 6) & 0x3F) + 0x80;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
}

int 	C(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = 0;
	specifier.lc = va_arg(vl, wchar_t);
	if (!(*str = ft_strnew(4)))
		exit(EXIT_FAILURE);
	put_unicode(specifier.lc, str, &i);
	return (ft_strlen(*str));
}

int 	S(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	specifier.ls = va_arg(vl, wchar_t*);
	if (specifier.ls == NULL)
	{
		if(!(*str = ft_strdup("(null)")))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*str = ft_strnew(5000)))
			exit(EXIT_FAILURE);
		while (((specifier.ls)[j] != 0))
		{
			put_unicode((specifier.ls)[j], str, &i);
			++i;
			++j;
		}
	}
	return (ft_strlen(*str));
}
