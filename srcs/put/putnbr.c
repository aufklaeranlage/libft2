/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:50:12 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:11:17 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Outputs the integer 'n' to the specified file descriptor.

#include "ft_put.h"

static void	ft_putnbrbaserec_fd(long n, int base, char *sbase, int fd);

void	ft_putnbrbase_fd(long n, int base, int fd)
{
	char	sbase[36] = BASE36;

	if (base <= 1)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbrbaserec_fd(-1 * (n / base), base, sbase, fd);
		ft_putchar_fd(sbase[-1 * (n % base)], fd);
	}
	else
	{
		ft_putnbrbaserec_fd(n / base, base, sbase, fd);
		ft_putchar_fd(sbase[n % base], fd);
	}
	return ;
}

static void	ft_putnbrbaserec_fd(long n, int base, char *sbase, int fd)
{
	if (!n)
		return ;
	ft_putnbrbaserec_fd(n / base, base, sbase, fd);
	ft_putchar_fd(sbase[n % base], fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbrbase_fd((long)n, 10, fd);
	return ;
}
