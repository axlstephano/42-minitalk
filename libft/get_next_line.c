/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:23:09 by axcastil          #+#    #+#             */
/*   Updated: 2023/12/30 18:27:23 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This function is responsible for concatenating the buffer 
//where the characters read from the "reader" function will be entered.

static char	*joinandfree(char *result, char *buffer)
{
	char	*line;

	line = ft_strjoin_gnl(result, buffer);
	free(result);
	return (line);
}

//This function is responsible for storing the characters read after the line break (\n)
//and saving them in the "result" variable of the main function, 
//since these will be used if the function is called again

static char	*next_line(char	*buffer)
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
	next = ft_calloc_gnl((ft_strlen_gnl(buffer) - i + 1), sizeof(char));
	i ++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

//This function handles the return of the "reader" function, 
//filtering the characters found until the line break (\n) is found.

static char	*liner(char	*buffer)
{
	char	*new_line;
	int		len;

	len = 0;
	if (buffer[len] == 0)
		return (NULL);
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len ++;
	len ++;
	new_line = ft_substr_gnl(buffer, 0, len);
	return (new_line);
}

//This function reads the file, having the "BUFFER_SIZE" that we set 
//as the reading pattern, and stops when it encounters a line break (\n)

static char	*reader(int fd, char *result)
{
	int		byte_read;
	char	*buffer;

	if (!result)
		result = ft_calloc_gnl(1, sizeof(char));
	buffer = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), NULL);
		buffer[byte_read] = 0;
		result = joinandfree(result, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

//This is the main function, here we will manage the extracted characters, 
//both for the return in this function call, 
//and for storing the rest of the read file (if there are even more characters)

char	*get_next_line(int fd)
{
	static char	*result;
	char		*new_line;
 
	//Error handler.
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		//Takes the last storage and free.
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
