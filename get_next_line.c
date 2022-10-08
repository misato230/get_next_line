/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satoumiu <satoumiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:00 by satoumiu          #+#    #+#             */
/*   Updated: 2022/10/08 13:32:19 by satoumiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_mem(char *free1, char *free2)
{
	free(free1);
	free(free2);
	return (NULL);
}

char	*read_and_joint(int fd, char *memo)
{
	char	*tmp;
	char	*buffer;
	ssize_t	rd_len;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	rd_len = 1;
	while (!ft_strchr(memo, '\n') && rd_len != 0)
	{
		rd_len = read(fd, tmp, BUFFER_SIZE);
		if (rd_len == -1 || (rd_len == 0 && memo[0] == '\0'))
			return (free_mem(tmp, memo));
		tmp[rd_len] = '\0';
		buffer = ft_strjoin(memo, tmp);
		if (!buffer)
			return (free_mem(tmp, memo));
		free(memo);
		memo = buffer;
	}
	free(tmp);
	return (memo);
}

char	*find_nl(char *memo)
{
	size_t	i;
	char	*str;

	i = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (memo[i])
	{
		str[i] = memo[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_next(char *memo)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (NULL);
	}
	i++;
	tmp = ft_strdup(&memo[i]);
	free(memo);
	if (!tmp)
		return (NULL);
	memo = tmp;
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memo)
	{
		memo = ft_strdup("");
		if (!memo)
			return (NULL);
	}
	memo = read_and_joint(fd, memo);
	if (!memo)
		return (NULL);
	str = find_nl(memo);
	if (!str)
	{
		free(memo);
		return (NULL);
	}
	memo = save_next(memo);
	return (str);
}
