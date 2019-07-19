#include "libft.h"

void capital(t_package *package)
{
	int i;

	i = -1;
	while( ++i < package->string->len)
		package->string->str[i] =
			ft_toupper(package->string->str[i]);
}

int X(t_flag flags, va_list list, t_string **result)
{
	t_package package;

	ft_bzero(&package, sizeof(t_package));
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str = ft_unsignedlltoa_base(va_arg(list, unsigned long long), 16);
	new_trash_bag(&(package.trash));
	mom(&(package.trash), T_CHAR, package.string);
	mom(&(package.trash), T_CHAR, package.string->str);
	package.string->len = ft_strlen(package.string->str);
	x_formatter(&package);
	capital(&package);
	*result = t_string_join(**result, *(package.string));
	garbage_day(&(package.trash));
	return(0);
}
