/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:25 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/20 21:11:39 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dst);
	i = j;
	if (dst < src || j < dstsize)
		return (0);
	while (src[j - i] && j + 1 < dstsize)
	{	
		dst[j] = src[j - i];
		j++;
	}
	if (j < dstsize)
		dst[j] = '\0';
	return (i + ft_strlen(src));
}*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	dlen = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = 0;
	j = ft_strlen(dst);
	while (src[i] && j + 1 < dstsize)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (dlen + ft_strlen(src));
}
/*int main()
{
	char	s1[20] = "hola, ";
	char	s2[] = "mundo";
	printf("%d\n", (int)ft_strlcat(s1, s2, 12));
	printf("%s\n", s1);
	return (0);
}*/
