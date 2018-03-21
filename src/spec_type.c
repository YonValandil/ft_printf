#include "ft_printf.h"

int 	s(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int len_arg;
	char *str_tmp;

	i = -1;
	specifier.s = va_arg(vl, char *);
	if (specifier.s == NULL)
		str_tmp = ft_strdup("(null)");
	else
		str_tmp = ft_strdup(specifier.s);
	len_arg = ft_strlen(str_tmp);
	if ((data->flag[0] & flag_pre) && (data->flag[2] < len_arg))
	{
		*str = (char*)ft_memalloc(data->flag[2] + 1);
		ft_strncpy(*str, str_tmp, data->flag[2]);
	}
	else
		*str = ft_strdup(str_tmp);
	len_arg = ft_strlen(*str);
	if (data->flag[0] & flag_plus)
		data->flag[0] &= ~flag_plus;
	if (data->flag[0] & flag_hash)
		data->flag[0] &= ~flag_hash;
	if (data->flag[0] & flag_space)
		data->flag[0] &= ~flag_space;
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= len_arg))
			data->flag[0] &= ~flag_pre;
	free(str_tmp);
	return (len_arg);
}

int 	c(t_printf *data, va_list vl, t_type specifier, char **str)
{
	char tab[2];

	ft_bzero(tab, 2);
	tab[0] = (char)va_arg(vl, int);
	if ((data->flag[0] & flag_pre) && (data->flag[2] < 1) && !(tab[0]))
		tab[0] = '\0';
	*str = ft_strdup(tab);
	if (data->flag[0] & flag_plus)
		data->flag[0] &= ~flag_plus;
	if (data->flag[0] & flag_hash)
		data->flag[0] &= ~flag_hash;
	if (data->flag[0] & flag_space)
		data->flag[0] &= ~flag_space;
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= 1))
			data->flag[0] &= ~flag_pre;
	return (1);
}

int 	p(t_printf *data, va_list vl, t_type specifier, char **str) //faire les tests pour p
{
	int len_arg;
	int i;

	i = -1;
	specifier.l = va_arg(vl, unsigned long);
	*str = ft_lltoa_base(specifier.l, 16);
	len_arg = ft_strlen(*str);
	add_to_result(data, '0', 1);
	add_to_result(data, 'x', 1);
	return (len_arg);
}

int 	d(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;
	int neg;

	i = -1;
	specifier.l = va_arg(vl, long);
	apply_modifier_signed(data, &specifier);
	if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z)
		|| (data->flag[0] & flag_j))
	{
		*str = ft_lltoa_base(specifier.l, 10);
		neg = (specifier.l < 0) ? 1 : 0 ;
	}
	else
	{
		*str = ft_lltoa_base(specifier.d, 10);
		neg = (specifier.d < 0) ? 1 : 0 ;
	}
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
			data->flag[0] &= ~flag_pre;
	if (data->flag[0] & flag_hash)
			data->flag[0] &= ~flag_hash;
	if (data->flag[0] & flag_pre)
		data->flag[0] &= ~flag_zero;
	if (neg && (data->val_prefix = 1))
		data->str_prefix = ft_strdup("-");
	if ((data->flag[0] & flag_plus) && !(neg) && (data->val_prefix = 1))
		data->str_prefix = ft_strdup("+");
	return (ft_strlen(*str));
}

int 	u(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long int);
	apply_modifier_unsigned(data, &specifier);
	if (data->flag[0] & flag_l)
		*str = ft_ulltoa_base(specifier.ul, 10);
	else
		*str = ft_ulltoa_base(specifier.u, 10);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= ft_strlen(*str)))
			data->flag[0] &= ~flag_pre;
	if (data->flag[0] & flag_hash)
			data->flag[0] &= ~flag_hash;
	if (data->flag[0] & flag_pre)
		data->flag[0] &= ~flag_zero;
	return (ft_strlen(*str));
}
