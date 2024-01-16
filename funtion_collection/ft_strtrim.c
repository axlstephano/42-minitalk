/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:07:22 by axcastil          #+#    #+#             */
/*   Updated: 2023/10/07 16:52:07 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	final;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	final = ft_strlen(s1 + start);
	while (final && ft_strchr(set, s1[final]))
		final--;
	return (ft_substr(s1 + start, 0, final - start + 2));
}*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*int main (int ac, char **av)
{
	if (ac == 3)
		printf ("%s", ft_strtrim(av[1], av[2]));
	return 0;
}*/
