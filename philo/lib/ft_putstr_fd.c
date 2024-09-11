/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:45:54 by yushsato          #+#    #+#             */
/*   Updated: 2024/08/29 23:32:44 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putstr_fd(const char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
