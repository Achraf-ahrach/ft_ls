/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:36:38 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/12 18:40:20 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *con);
void	ft_putstr(char *str, int *con);
void	ft_putnbr(int nb, int *con);
void	ft_uhex(unsigned int nb, int *con);
void	ft_lhex(unsigned int nb, int *con);
void	ft_unsigned(unsigned int nb, int *con);
void	ft_address(size_t nb, int *con);
#endif
