#include "ft_std.h"
#include "ft_string.h"

char	addOne(unsigned int i, char c) {return (i + c);}

int main(void)
{
	char	*s = ft_strmapi("1234", addOne);
	return (0);
}
