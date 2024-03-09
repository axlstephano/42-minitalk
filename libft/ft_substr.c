/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:09:32 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/21 20:41:31 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = NULL;
	if (!*s || ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

/*int main()
{
    char *str = "cuarentaydos";
    char *sub = ft_substr(str,2, 7);
    printf("%s", sub);
    return 0;
}*/
