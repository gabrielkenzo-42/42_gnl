/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:58:18 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/06/13 20:58:05 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	int			ret;
	int			index;
	static char	*leftover[OPEN_MAX];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	*line = NULL;
	if (!leftover[fd])
		leftover[fd] = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	index = ft_strlen(leftover[fd]);
	while (newline_index(leftover[fd]) == -1 && ret > 0 && ret <= BUFFER_SIZE)
	{
		leftover[fd] = enlarge_str(leftover[fd], BUFFER_SIZE);
		ret = read(fd, &leftover[fd][index], BUFFER_SIZE);
		index = index + BUFFER_SIZE;
	}
	if (ret >= 0 && ret <= BUFFER_SIZE)
		leftover[fd] = take_first_line(line, leftover[fd]);
	if (ret > 0 && ret <= BUFFER_SIZE)
		return (1);
	return (ret == 0 ? 0 : -1);
}

int		newline_index(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*enlarge_str(char *str, int n)
{
	int		len;
	char	*s;
	int		i;

	len = ft_strlen(str);
	s = ft_calloc(len + n + 1, sizeof(char));
	i = -1;
	while (str[++i])
		s[i] = str[i];
	free(str);
	return (s);
}

char	*take_first_line(char **line, char *leftover)
{
	char	*temp;
	int		index;
	int		len;

	index = newline_index(leftover);
	temp = 0;
	if (index >= 0)
	{
		leftover[index] = 0;
		len = ft_strlen(&leftover[index + 1]);
		temp = (char*)ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(temp, &leftover[index + 1], len + 1);
	}
	len = ft_strlen(leftover);
	*line = (char*)ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(*line, leftover, len + 1);
	free(leftover);
	leftover = 0;
	return (temp);
}
