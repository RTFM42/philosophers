/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:05:04 by yussato           #+#    #+#             */
/*   Updated: 2024/09/11 19:05:51 by yussato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "channel.h"

int		ft_atoi(const char *str);
void	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(const char *str);

#endif
