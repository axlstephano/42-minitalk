/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:59:52 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/13 15:17:53 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*string;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	string = malloc(count * size);
	if (!string)
		return (NULL);
	ft_bzero(string, count * size);
	return (string);
}
