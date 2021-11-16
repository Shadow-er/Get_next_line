/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:44:35 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/16 20:25:59 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	char	*d;

	c = (char)c;
	while (*str)
	{
		if (*str == c)
		{
			d = (char *)str;
			return (d);
		}
		str++;
	}
	if (*str == c)
	{
		d = (char *)str;
		return (d);
	}
	return (0);
}

void	*ft_memmove(void *dst,void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < p && p < s + len)
	{
		s = s + len;
		p = p + len;
		while (len--)
			*--p = *--s;
	}
	else
	{
		while (len--)
			*p++ = *s++;
	}	
	return (dst);
}

char	*ft_strdup(char *s1)
{
	unsigned int	r;
	unsigned int	i;
	char			*dst;

	r = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (r + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char				*i;
	unsigned int		len1;
	unsigned int		len2;
	unsigned int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 && s2 == 0)
		return (ft_strdup(s1));
	if (s1 == 0 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	j = len1 + len2 + 1;
	i = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (i == 0)
		return (0);
	ft_memmove(i, s1, len1);
	ft_memmove(i + len1, s2, len2);
	i[j - 1] = '\0';
	return (i);
}

char	*ft_split(char **s)
{
	char			*temp;
	char			*save;
	unsigned int	i;
	unsigned int	j;
	unsigned int	reste;

	i = 0;
	j = 0;
	while (s[0][i])
		i++;
	while(s[0][j] != '\n' && s[0][j])
		j++;
	reste = i - j - 1;
	temp = ft_substr(s[0], 0, j + 1);
	save = ft_substr(s[0], j + 1, reste);
	s[0] = ft_substr(save,0, reste);
	return (temp);
}
