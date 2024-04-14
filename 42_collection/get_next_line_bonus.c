/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:20:54 by axcastil          #+#    #+#             */
/*   Updated: 2023/12/27 19:37:51 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*result[1024];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (result[fd])
		{
			free(result[fd]);
			result[fd] = NULL;
		}
		return (NULL);
	}
	result[fd] = reader(fd, result[fd]);
	if (!result[fd])
		return (free(result[fd]), NULL);
	new_line = liner(result[fd]);
	result[fd] = next_line(result[fd]);
	return (new_line);
}
//int main()
//{
//    int fd1;
//	int	fd2;
//	int	fd3;
//    char *result1;
//	char *result2;
//	char *result3;

//    // Archivo 1: text.txt
//    fd1 = open("text1.txt", O_RDONLY);
//	fd2 = open("text2.txt", O_RDONLY);
//	fd3 = open("text3.txt", O_RDONLY);
//    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
//        return 0;
//    result1 = get_next_line(fd1);
//	result2 = get_next_line(fd2);
//    result3 = get_next_line(fd3);
//	while (result1 || result2 || result3)
//    {
//		printf("%s%s%s\n", result1, result2, result3);
//        free(result1);
//		free(result2);
//		free(result3);
//		result1 = get_next_line(fd1);
//		result2 = get_next_line(fd2);
//		result3 = get_next_line(fd3);
//    }
//    close(fd1);
//	close(fd2);
//	close(fd3);
//    return 0;
//}
