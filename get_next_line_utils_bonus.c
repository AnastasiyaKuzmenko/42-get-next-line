/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:45:56 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/13 11:06:50 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0' && s[index] != (char)c)
	{
		index++;
	}
	if (s[index] == '\0' && s[index] != (char)c)
	{
		return (0);
	}
	return ((char *)&s[index]);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	j;

	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
	{
		len = ft_strlen(s + start);
	}
	result = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == result)
	{
		return (NULL);
	}
	j = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + j] != '\0' && j < len)
		{
			result[j] = s[start + j];
			j++;
		}
	}
	result[j] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == result)
	{
		return (0);
	}
	while (index < len)
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1len;
	int		s2len;
	int		index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (NULL == result)
		return (0);
	while (index < s1len + s2len)
	{
		if (index < s1len)
			result[index] = s1[index];
		else
			result[index] = s2[index - s1len];
		index++;
	}
	result[index] = '\0';
	return (result);
}
