/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:41:16 by axcastil          #+#    #+#             */
/*   Updated: 2023/12/02 12:48:57 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inspect(va_list args, char *letter, size_t *number)
{
	if (*letter == 'c')
		ft_putchar_printf(va_arg(args, int), number);
	else if (*letter == 's')
		ft_putstr_printf(va_arg(args, char *), number);
	else if (*letter == 'p')
		ft_putaddress_printf(va_arg(args, void *), number);
	else if (*letter == 'u')
		ft_putunsigned_printf(va_arg(args, unsigned int), number);
	else if (*letter == 'd' || *letter == 'i')
		ft_putnbr_printf(va_arg(args, int), number);
	else if (*letter == 'x' || *letter == 'X')
	{
		if (*letter == 'x')
			ft_puthexadown_printf(va_arg(args, unsigned int), number);
		else
			ft_puthexaup_printf(va_arg(args, unsigned int), number);
	}
	else if (*letter == '%')
		ft_putchar_printf('%', number);
}

int	ft_printf(char const *sentence, ...)
{
	va_list	args;
	size_t	size;

	if (!sentence)
		return (0);
	size = 0;
	va_start(args, sentence);
	while (*sentence)
	{
		if (*sentence == '%')
		{
			sentence++;
			inspect(args, (char *)sentence, &size);
		}
		else
			ft_putchar_printf(*sentence, &size);
		sentence++;
	}
	va_end(args);
	return (size);
}
