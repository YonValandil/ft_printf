#include "ft_printf.h"

void put_unicode(wchar_t wchar, char **str, int *i)
{
	// int z = *i;
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
	// return (*i - z);
}

int unicode_len(wchar_t *uni_str, int *byte_len)
{
	// wchar_t *asd = uni_str;
    //
	// while (*uni_str != 0)
	// 	uni_str++;
	// return (uni_str - asd);

//----------------------------------

	// int i;
    //
	// i = 0;
	// while (uni_str[i] != 0)
	// {
	// 	if (*uni_str <= 0x7f)
	// 		++i;
	// 	else if (*uni_str <= 0x7ff)
	// 		i += 2;
	// 	else if (*uni_str <= 0xffff)
	// 		i += 3;
	// 	else
	// 		i += 4;
	// }
	// return (i);
//----------------------------------

	wchar_t *asd = uni_str;

	while (*uni_str != 0)
	{
		if (*uni_str <= 0x7f)
			*byte_len += 1;
		else if (*uni_str <= 0x7ff)
			*byte_len += 2;
		else if (*uni_str <= 0xffff)
			*byte_len += 3;
		else
			*byte_len += 4;
		uni_str++;
	}
	return (uni_str - asd);
}

int n_unicode_len(wchar_t *uni_str, int *byte_len, int n)
{
	wchar_t *asd = uni_str;
	int i;

	i = 0;
	while (i < n)
	{
		if (*uni_str <= 0x7f)
			*byte_len += 1;
		else if (*uni_str <= 0x7ff)
			*byte_len += 2;
		else if (*uni_str <= 0xffff)
			*byte_len += 3;
		else
			*byte_len += 4;
		uni_str++;
		++i;
	}
	return (uni_str - asd);
}
int 	C(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = 0;
	specifier.lc = va_arg(vl, wchar_t);
	if (!(*str = ft_strnew(4)))
		exit(EXIT_FAILURE);
	put_unicode(specifier.lc, str, &i);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	return (ft_strlen(*str));
}

#include <stdio.h>
int 	S(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int j;
	int uni_byte_len;
	int uni_len;

	i = 0;
	j = 0;
	uni_byte_len = 0;
	specifier.ls = va_arg(vl, wchar_t*);
	uni_len = unicode_len(specifier.ls, &uni_byte_len);
	if ((data->flag[0] & flag_pre) && (data->flag[2] < uni_len))
	// if ((data->flag[0] & flag_pre) && (data->flag[2] < uni_byte_len))
	{
		uni_byte_len = 0;
		uni_len = n_unicode_len(specifier.ls, &uni_byte_len, data->flag[2]);
	}

	// printf("\n\nuni_len ======= %d\n", uni_len);
	// printf("uni_byte_len ======= %d\n", uni_byte_len);

	if (specifier.ls == NULL)
	{
		if(!(*str = ft_strdup("(null)")))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*str = ft_strnew(uni_len * 4)))
			exit(EXIT_FAILURE);
		while (j < uni_len)
		{
			put_unicode((specifier.ls)[j], str, &i);
			++i;
			++j;
		}
	}
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= uni_len))
			data->flag[0] &= ~flag_pre;
	return (ft_strlen(*str));
}
