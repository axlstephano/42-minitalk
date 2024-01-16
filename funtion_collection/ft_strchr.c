/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:36:23 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/13 18:09:13 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*int main()
{
	char *str = "hoala";
	int letter = 1024;
	printf ("%p\n", ft_strchr(str, letter));
	printf ("%p", strchr(str, letter));
	return 0;
}*/
//como se trata de punteros, es más conveniente return(NULL)
