/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:08:05 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/04 18:18:31 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char const *sentence, ...);
void	inspect(va_list args, char *letter, size_t *number);
void	ft_putchar_printf(char c, size_t *number);
void	ft_putstr_printf(char *s, size_t *number);
void	ft_putnbr_printf(int n, size_t *number);
void	ft_putunsigned_printf(unsigned int n, size_t *number);
void	ft_putaddress_printf(void *address, size_t *number);
void	ft_puthexaup_printf(unsigned long long n, size_t *number);
void	ft_puthexadown_printf(unsigned long long n, size_t *number);

#endif