/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satoumiu <satoumiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:14:14 by satoumiu          #+#    #+#             */
/*   Updated: 2022/10/04 22:02:16 by satoumiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_joint(char *s1, char *s2, char *new_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	src1;
	size_t	src2;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	src1 = ft_strlen(s1);
	src2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (src1 + src2 + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_joint(s1, s2, new_str));
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*array;

	i = 0;
	if (s == NULL)
		return (NULL);
	array = (char *)s;
	if ((char) c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (array[i] != '\0')
	{
		if (array[i] == (char) c)
			return (&array[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*src;
	size_t	i;

	src = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (src == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
