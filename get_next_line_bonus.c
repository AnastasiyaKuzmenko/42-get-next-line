/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:45:36 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/27 10:47:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buffer, char *str)
{
	int		ret;
	char	*tmp;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		buffer[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buffer);
		else
		{
			tmp = str;
			str = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

static char	*convert_line(char *str, char **result)
{
	int		len;
	char	*remain;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
	{
		*result = ft_substr(str, 0, len + 1);
	}
	else
	{
		*result = ft_strdup(str);
	}
	if (str[len] == '\0')
		return (NULL);
	remain = ft_substr(str, len + 1, ft_strlen(str) - len);
	if (*remain == '\0')
	{
		free(remain);
		remain = NULL;
	}
	str[len + 1] = '\0';
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str[OPEN_MAX];
	char		*result;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX - 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buffer)
		return (NULL);
	str[fd] = read_line(fd, buffer, str[fd]);
	free(buffer);
	if (str[fd] == NULL)
	{
		return (NULL);
	}
	tmp = str[fd];
	str[fd] = convert_line(tmp, &result);
	free(tmp);
	tmp = NULL;
	return (result);
}
