/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:31:55 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/04 17:22:47 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == src || !len)
		return (dst);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}

/*int main()
{
    char    s[] = "42madrid";
    char    d[9];
    printf("%s\n", ((char *)ft_memmove(d, s,8)));
    //printf("%s\n", s);
	//printf("%s\n", d);
	//printf("%p\n", s);
	//printf("%p\n", d);
	//printf("%ld\n", d - s);
	//printf("%ld\n", s - d);
    //}
    //return 0;
}*/
