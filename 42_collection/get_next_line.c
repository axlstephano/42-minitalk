/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:23:09 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/04 17:24:05 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = ft_strjoin(result, buffer);
	free(result);
	return (line);
}

char	*next_line(char	*buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i ++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*liner(char	*buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	if (buffer[len] == 0)
		return (NULL);
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len ++;
	len ++;
	new_line = ft_substr(buffer, 0, len);
	return (new_line);
}

char	*reader(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		free(result);
		return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), NULL);
		buffer[byte_read] = 0;
		result = joinandfree(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result)
		{
			free(result);
			result = NULL;
		}
		return (NULL);
	}
	result = reader(fd, result);
	if (!result)
		return (NULL);
	new_line = liner(result);
	result = next_line(result);
	return (new_line);
}

/*int main()
{
    int fd;
    char *result;
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    result = get_next_line(fd);
    while (result != NULL)
    {
        printf("%s",result);
        free(result);
        result = get_next_line(fd);
    }
    close(fd);
    return(0);
}*/
