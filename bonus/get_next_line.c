/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:34:31 by alamiri           #+#    #+#             */
/*   Updated: 2024/12/07 14:07:44 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd)
{
	char	*buff;
	char	*res;
	char	*tem;
	ssize_t	c;

	res = NULL;
	buff = (char *)malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	c = 1;
	while (c > 0)
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c < 0)
			break ;
		buff[c] = '\0';
		tem = res;
		res = ft_strjoin(res, buff);
		free(tem);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*ft_getline(char *t)
{
	char	*getline;
	int		i;

	if (!t || t[0] == '\0')
		return (NULL);
	i = 0;
	while (t[i] && t[i] != '\n')
		i++;
	getline = (char *)malloc((i + 2) * sizeof(char));
	if (!getline)
		return (NULL);
	i = 0;
	while (t[i] && t[i] != '\n')
	{
		getline[i] = t[i];
		i++;
	}
	if (t[i] == '\n')
	{
		getline[i] = '\n';
		i++;
	}
	getline[i] = '\0';
	return (getline);
}

char	*ft_cat(char *cat)
{
	char	*p;

	int (i), (j), (t);
	t = 0;
	i = 0;
	while (cat[i] && cat[i] != '\n')
		i++;
	if ((cat[i] == '\n' && !cat[i + 1]) || !cat[i])
	{
		free(cat);
		return (NULL);
	}
	if (cat[i] == '\n')
		i++;
	j = i;
	while (cat[i])
		i++;
	p = (char *)malloc(((i - j) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
		p[t++] = cat[j++];
	p[t] = '\0';
	free(cat);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*buff;
	char		*test;
	char		*tem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_reader(fd);
	tem = p;
	p = ft_strjoin(p, buff);
	free(tem);
	test = ft_getline(p);
	if (p)
		p = ft_cat(p);
	free(buff);
	return (test);
}
