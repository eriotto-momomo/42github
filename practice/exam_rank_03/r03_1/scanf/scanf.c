#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*ft_scanf
- handle s, d and c.
- dont handle options *, m and '
- dont handle max field width
- dont handle types mdifior vars
- dont handle conversions beginning with %n$

Allowed:isspace, isdigit, va_start, va_arg, va_copy, va_end, 
fgetc, ungetc, ferror, feof, stdi
*/

void	skip_input_space()
{
	char current;

	if(feof(stdin) || ferror(stdin))
		return ;
	current = fgetc(stdin);
	while(isspace(current))
		current = fgetc(stdin);
	if(feof(stdin) || ferror(stdin) || current < 0)
		return ;
	ungetc(current, stdin);
}

int	scan_char(va_list ap)
{
	char *target;
	char current;

	target = va_arg(ap, char *);
	if(!target || feof(stdin) || ferror(stdin))
		return (-1);
	current = fgetc(stdin);
	if(ferror(stdin) || current < 0)
		return (-1);
	*target = current;
	return (0);
}

int	scan_int(va_list ap)
{
	long long int res = 0;
	int op = 1;
	char current = 0;
	int *target;
	int is_first = 1;
	int has_digit = 0;

	target = va_arg(ap, int *);
	if(!target || feof(stdin) || ferror(stdin))
		return (-1);
	current = fgetc(stdin);
	while(!isspace(current) 
		&& (isdigit(current) || (is_first && (current == '-' || current == '+')))
		&& current >= 0 
		&& !feof(stdin)
		&& !ferror(stdin))
	{
		if(is_first)
			is_first = 0;
		if(current == '-')
			op = -1;
		else if(isdigit(current))
		{
			has_digit = 1;
			res *= 10;
			res += current - '0';
		}
		current = fgetc(stdin);
	}
	if(feof(stdin) || ferror(stdin) || current < 0)
	{
		if(res == 0 && !has_digit)
			return (-1);
		else if(res == 0 && has_digit)
			return (-2);
		else
		{
			*target = res * op;
			return  (-2);
		}
	}
	ungetc(current, stdin);
	*target = res * op;
	if(res == 0 && !has_digit)
		return (-3);
	return (0);
}

int	scan_string(va_list ap)
{
	char *target;
	char current;
	size_t pos = 0;

	target = va_arg(ap, char *);
	if(!target || feof(stdin) || ferror(stdin))
		return (-1);
	current = fgetc(stdin);
	while(!isspace(current) 
		&& current >= 0 
		&& !feof(stdin)
		&& !ferror(stdin))
	{
		target[pos] = current;
		pos++;
		current = fgetc(stdin);
	}
	if(feof(stdin) || ferror(stdin) || current < 0)
	{
		if(pos == 0)
			return (-1);
		else
			return  (-2);
	}
	ungetc(current, stdin);
	return (0);
}

int receive_input(const char *format, va_list ap)
{
	switch (*format)
	{
		case 'c':
			return (scan_char(ap));
		case 'd':
			skip_input_space();
			return (scan_int(ap));
		case 's':
			skip_input_space();
			return (scan_string(ap));
		default:
			return (-1);
	}
}

int check_comp(char c)
{
	char current;
	skip_input_space();
	if(feof(stdin) || ferror(stdin))
		return (-1);
	current = fgetc(stdin);
	if(feof(stdin) || ferror(stdin) || current < 0)
	{
		return (-1);
	}
	if(c != current)
	{
		ungetc(current, stdin);
		return (-1);	
	}
	return (0);
}


int ft_scanf(const char *format, ...)
{
	int	i = 0;
	int	result = 0;
	int error_id = 0;
	va_list	ap;
	
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			error_id = receive_input(&(format[i]), ap);
			//printf("Error ID: %i\n", error_id);
			if (error_id != 0)
				break;
			else
				result++;
		}
		else if(!isspace(format[i]))
		{
			if(check_comp(format[i]) != 0)
				break;
		}
		i++;
	}
	va_end(ap);
	if(error_id != 0 && result == 0)
	{
		if(error_id == -3)
			return result;
		else if(error_id == -2)
			return (result + 1);
		else
			return -1;
	}
	return (result);
}



//FUNCTION TESTS TO BE REMOVED ON RENDUE
void clearall(char *c, char *c2, char *str, char *str2, char *str3, int *n, int *n2, int *n3)
{
	*c = 0;
	*c2 = 0;
	memset(str, 0, strlen(str));
	memset(str2, 0, strlen(str2));
	memset(str3, 0, strlen(str3));
	*n = 0;
	*n2 = 0;
	*n3 = 0;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int res;

	char c;
	char c2;

	char str[50];
	char str2[50];
	char str3[50];

	int n;
	int n2;
	int n3;

	//CHAR
	if(0){
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%c%c", &c, &c2);
		printf("NRM: (%i) - %c & %c\n", res, c, c2);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%c%c", &c, &c2);
		printf("FT: (%i) - %c & %c\n", res, c, c2);
		
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%c", &c);
		printf("NRM: (%i) - %c\n", res, c);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%c", &c);
		printf("FT: (%i) - %c\n", res, c);
	}

	//SIMPLE STRING
	if(0){
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%s", str);
		printf("NRM: (%i) - %s\n", res, str);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%s", str);
		printf("FT: (%i) - %s\n", res, str);


		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%s", str);
		printf("NRM: (%i) - %s\n", res, str);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%s", str);
		printf("FT: (%i) - %s\n", res, str);
	}

	//TRIPLE STRING
	if(0){
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%s%s%s", str, str2, str3);
		printf("NRM: (%i) - %s && %s && %s\n", res, str, str2, str3);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%s%s%s", str, str2, str3);
		printf("FT: (%i) - %s && %s && %s\n", res, str, str2, str3);
	}

	//STRING with check
	if(1){
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("Hello    World%s", str);
		printf("NRM: (%i) - %s\n", res, str);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("Hello    World %s", str);
		printf("FT: (%i) - %s\n", res, str);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%s", str);
		printf("FT: (%i) - %s\n", res, str);
	}

	//NUMBNERS
	if(0)
	{
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = scanf("%d%s", &n, str);
		printf("NRM: (%i) - %i && %s\n", res, n, str);
		clearall(&c, &c2, str, str2, str3, &n, &n2, &n3);
		res = ft_scanf("%d%s", &n, str);
		printf("FT: (%i) - %i && %s\n", res, n, str);
	}

	return 0;
}