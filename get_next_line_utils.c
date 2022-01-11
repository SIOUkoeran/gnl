/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:20:09 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/11 17:04:07 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
    char	*temp;
    size_t	length;

    length = 0;
    while (s1[length] != '\0')
    {
        length++;
    }
    temp = (char *)malloc(sizeof(char) * (length + 1));
    if (temp == NULL)
        return (NULL);
    ft_strlcpy(temp, s1, length + 1);
    return (temp);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	return_value;

	i = 0;
    return_value = 0;
    while (src[return_value] != '\0')
        return_value++;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (return_value);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_length;
	char	*result_str;
    size_t	idx;

    idx = -1;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	result_str = malloc((total_length + 1) * sizeof(char));
	if (result_str == NULL)
		return (NULL);
    while (++idx < total_length + 1)
        result_str[idx] ='\0';
	if (result_str == NULL)
		return (NULL);
	ft_strlcat(result_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(result_str, s2, total_length + 1);
	free(s1);
	return (result_str);
}

size_t	ft_strlen(char const *s1)
{
	size_t	length;
	
	length = 0;
	if (s1 == NULL)
		return (0);
    while (s1[length] != '\0')
		length++;
    return (length);
}

char	*ft_strchr(char const *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}