/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hexlow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 18:54:57 by dreijans      #+#    #+#                 */
/*   Updated: 2022/11/24 13:23:27 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	howmuch(unsigned int a)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		i++;
	}
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static int	put_hexlow(unsigned int n)
{
	if ((n / 16) != 0)
		put_hexlow(n / 16);
	if ((n % 16) < 10)
	{
		print_char((n % 16) + 48);
	}
	else
	{
		print_char((n % 16) + 87);
	}
	return (n);
}

int	print_hexlow(unsigned int n)
{
	int	count;

	count = howmuch(n);
	put_hexlow(n);
	return (count);
}

/*
why do i get LONG max/min errors when i put long in the function and now i don't?
*/