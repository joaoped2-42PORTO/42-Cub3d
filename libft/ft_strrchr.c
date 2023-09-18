/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:40:15 by huolivei          #+#    #+#             */
/*   Updated: 2022/11/29 15:02:08 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && i > 0)
		i--;
	if (i == 0 && str[i] != c)
		return (0);
	return ((char *)str + i);
}

#include <string.h>
#include <stdio.h>

int main()
{
    // Storing it in string array
    char string[] = "Geeks for Geeks";

    // The character we've to search for
    char character = 'r';

    // Storing in a pointer ptr
    char* ptr = strrchr(string, character);
    printf("%c\n", *ptr);
    ptr = ft_strrchr(string, character);
    printf("%c\n", *ptr);
    return 0;
}
