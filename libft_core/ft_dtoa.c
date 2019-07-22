/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:25:02 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/21 23:30:35 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "trashcan.h"

static double	rounding(double d, int precision)
{
	double place;

	place = 1;
	while (precision--)
		place /= 10;
	return ((d + (place * 5)));
}

static char		*check_limits(double d)
{
	if (d != d)
		return ("nan");
	else if (d == INFINITY)
		return ("inf");
	else if (d == -INFINITY)
		return ("-inf");
	return (NULL);
}

static char		*helper(double d, int precision, char *str, t_rash_can *trash)
{
	char	*one;
	int		n;

	n = 0;
	if (precision != 0)
	{
		mom(trash, T_CHAR, str);
		str = ft_strjoin(str, ".");
		mom(trash, T_CHAR, str);
		one = ft_strnew(precision);
		mom(trash, T_CHAR, one);
		while (precision--)
		{
			d = (d - (long)d) * 10;
			one[n++] = (long)d + '0';
		}
		str = ft_strjoin(str, one);
	}
	return (str);
}

char			*ft_dtoa(double d, int precision)
{
	t_rash_can	trash;
	char		*str;
	char		*sign;

	sign = NULL;
	str = NULL;
	if ((str = check_limits(d)))
		return (str);
	new_trash_bag(&trash);
	if (d < 0)
	{
		sign = "-";
		d = -(d);
	}
	d = rounding(d, (precision + 1));
	str = ft_longlongtoa_base(d, 10);
	if (sign)
	{
		mom(&trash, T_CHAR, str);
		str = ft_strjoin(sign, str);
	}
	str = helper(d, precision, str, &trash);
	garbage_day(&trash);
	return (str);
}
