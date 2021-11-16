/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:11:18 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/16 20:53:23 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

unsigned int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s == '\0')
		return (0);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0); 
	i = 0;
	while (s[start + i] && len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buffer;
	int			i;
	char		*temp;

	if (fd < 0)
		return(NULL);
	if(!s)
		s = ft_strdup("");
	free(s);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == 0)
		return(0);
	i = read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	if(i < 0)
		return (NULL);
	while (i > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(s,buffer);
		free(s);
		s = temp;
		if(ft_strchr(s,'\n'))
			break;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	if (i == 0)
		return (s);
	return (ft_split(&s));
}
