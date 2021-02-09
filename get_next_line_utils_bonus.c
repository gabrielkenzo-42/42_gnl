/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:02:11 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/06/13 20:43:56 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 0)
		*ptr++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (count > 1000000)
		count = 1000000;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	char		*ptrd1;
	char		*ptrd2;
	const char	*ptrs;

	if (!dest)
		return (0);
	ptrd1 = dest;
	ptrd2 = dest + destsize;
	ptrs = src;
	while (*ptrs && ptrd1 < ptrd2)
		*ptrd1++ = *ptrs++;
	if (ptrd1 < ptrd2)
		*ptrd1 = 0;
	else if (destsize > 0)
		ptrd1[-1] = 0;
	return (ft_strlen(src));
}
