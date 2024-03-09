/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:25:26 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/16 21:37:27 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	char	*aux;

	duplicate = (char *)malloc(ft_strlen(s1) + 1);
	if (!duplicate)
		return (NULL);
	aux = duplicate;
	while (*s1)
	{
		*duplicate = *s1;
		duplicate++;
		s1++;
	}
	*duplicate = '\0';
	return (aux);
}

/*int main()
{
    char *str = "hola";
    printf("%s", ft_strdup(str));
    return 0;
}*/
