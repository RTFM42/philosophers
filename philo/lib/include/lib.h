/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:03 by yushsato          #+#    #+#             */
/*   Updated: 2024/09/22 16:28:04 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "channel.h"

int		ft_atoi(const char *str);
void	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(const char *str);

#endif
