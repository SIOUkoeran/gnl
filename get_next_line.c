/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:20:12 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/11 17:10:24 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	size_t			i;

	i = 0;
	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (dest_length > size)
		return (size + src_length);
	if (size > dest_length + 1)
	{
		while (src[i] != '\0' && i < (size - 1 - dest_length))
		{
			dest[dest_length + i] = src[i];
			i++;
		}
	}
	dest[dest_length + i] = '\0';
	return (src_length + dest_length);
}

static char *ft_return_malloc(char *result)
{
	size_t 	length;
	char 	*temp;
	
	length = 0;
	if (!result)
		return (NULL);
	while (result[length] != '\n' && result[length])
		length++;
	if (result[length] == '\n')
		length++;
	temp = (char *)malloc(sizeof(char) * (length + 1));
	temp[length] = '\0';
	if (temp == NULL)
		return (NULL);
	return (temp);	
}
static char	*ft_return_new_line(char **result, char *buff, int fd)
{
	size_t 	length;
	char 	*temp;
	char	*temp_result;
	free(buff);
	length = 0;
	if (!result[fd])
		return (NULL);
	temp = ft_return_malloc(result[fd]);
	if (temp == NULL)
		return (NULL);
	while (result[fd][length] != '\n' && result[fd][length])
	{
		temp[length] = result[fd][length];
		length++;
	}
	if (result[fd][length] == '\n')
		temp[length++] = '\n';
	temp[length] = '\0';
	temp_result = result[fd];
	result[fd] = ft_strdup(result[fd] + length);
	free(temp_result);
	return (temp);
}

char	*get_next_line(int fd)
{
    char			*buff;
 	static char		*result[OPEN_MAX];
	int				size;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
        return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	while (size  > 0)
    {
		buff[size] = '\0';
		if (result[fd] != NULL)
			result[fd] = ft_strjoin(result[fd], buff);
		if (result[fd] == NULL)
			result[fd] = ft_strdup(buff);
		if (ft_strchr(result[fd], '\n'))
			return ft_return_new_line(result, buff, fd);
		size = read(fd, buff, BUFFER_SIZE);
	}
	if (ft_strlen(result[fd]) > 0)
		return (ft_return_new_line(result, buff, fd));
	free(buff);
	free(result[fd]);
	return (NULL);
}
// int main()
// {
// 	char *temp;
// 	int flag = 1;
// 	int fd = open("./test.txt", O_RDONLY);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	printf("\n");
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	printf("\n");
// 	int cnt = 0;
// 	// while (flag == 1)
// 	// {
// 	// 	temp = get_next_line(fd);
// 	// 	printf("%s\n", temp);
// 	// 	if (temp == NULL)
// 	// 		flag = 2;
// 	// 	printf("cnt : %d", cnt++);
// 	// }
// }