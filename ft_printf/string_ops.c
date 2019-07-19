#include "libft.h"

t_string *t_string_join(t_string string_one, t_string string_two)
{
	t_string *newstr;
	int i;
	char *temp;

	
	newstr = (t_string*)malloc(sizeof(t_string));
	newstr->len = (string_one.len) + (string_two.len);
	newstr->str = ft_strnew(newstr->len);
	temp = newstr->str;
	i = -1;
	while(++i < string_one.len)
		*temp++ = *string_one.str++;
	i = -1;
	while(++i < string_two.len)
		*temp++ = *string_two.str++;
	return(newstr);
}
	
void		print_t_string(t_string *result)
{
	int i;

	i = -1;
	while(++i < result->len)
		ft_putchar(result->str[i]);
}
