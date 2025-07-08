/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 05:57:43 by abronner          #+#    #+#             */
/*   Updated: 2025/06/30 07:00:58 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE36="0123456789abcdefghijklmnopqrstuvwxyz"

//	Converts the inital portion of string 's' into a long integer value
//	according to the given base, which must be between 2 and 36 inclusive, or
//	be the special value 0.
//	The string may begin with an arbitrary amount of whitespace (as determined
//	by ft_isspace()) followed by a single optional '+' or '-' sign. If base is
//	0 or 16, the string may include a '0x' or '0X' prefix, and the nmber will be
//	read in base 16; otherwise, a zero base is taken as 10 unless the next
//	character is 0, in which case i  is taken as 8 (octal).
//	The remainder of the string is converted to a long value, stopping at the
//	first character that is not a valid digit in the given base. (The bases use
//	the digits 0 - 9 as their first 10 digits and then the alphabet until their
//	size is reached).
//	If 'endptr' is not NULL, the address of the first invalid digit is stored in
//	endptr. If there were no valid digit it stores the original value and
//	returns 0.
//	Returns the result of the conversion, unless the value would under- or over-
//	flow. If and underflow occurs, returns LONG_MIN; if an overflow occurs
//	returns LONG_MAX.

static int	base_zero(const char *s, int *i);

long	ft_strtol(const char *s, char **endptr, int base)
{
	const char	sbase[37] = BASE36;
	size_t		i;
	long		val;
	long		dig;
	long		sign;

	if (!s || base < 0 || base == 1 || base > 36)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		++i;
	if (base == 0)
		base = base_zero(s, &i);
	sbase[base] = '\0';
	val = 0;
	while (1)
	{
		dig_c = ft_strchr(sbase, s[i]);
		if (!dig_c)
			break ;
		dig = dig_c - s;
		if (flow_check())
			return ()
		val *= 10;
		val += dig;
		++i;
	}
}

//	Checks whether a base is decimal, octal or hex based on the string 's' at
//	the offset stored at 'i'. Changes the offset of 'i' while moving through the
//	string to determine the base, so the offset is the start of the digit string
//	without any prefixes.

static int	base_zero(const char *s, int *i)
{
	if (s[*i] != '0')
		return (10);
	++*i;
	if (s[*i] != 'x' && s[*i] != 'X')
		return (8);
	++*i;
	return (16);
}

static int	base_char(const char *base, int baselen, char c, long *dig)
{
	size_t	i;

	i = 0;
	while (base[i] && i < baselen)
	{
		if (base[i] == c)
			return (offset =)
	}
}
