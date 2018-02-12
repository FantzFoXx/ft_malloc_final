/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:49:14 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/28 15:11:32 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# include "libft.h"

void	ft_debug_common(const char *fonc, int li, const char *c, const char *n);
void	ft_debug(const char *fonc, int line);
void	ft_debugstr(const char *s);
void	ft_debugnbr(int n);
void	ft_debugnbrl(long n);
void	ft_debugnbrul(t_ul n, char *base);
void	ft_debugnbrul(t_ul n, char *base);
void	ft_debugnbrul(t_ul n, char *base);
void	ft_debugc(const char c);
void	ft_debugptr(void *ptr);

# ifdef DEBUG
#  undef DEBUG
#  define DEBUGIDEM __FUNCTION__, __LINE__,
#  define DEBUG ft_debug_common(DEBUGIDEM "\n", NULL);
#  define DEBUGCOM(x) ft_debug_common(DEBUGIDEM ":", #x)
#  define DEBUGSTR(x) DEBUGCOM(x);ft_debugstr(x)
#  define DEBUGNBR(x) DEBUGCOM(x);ft_debugnbr(x)
#  define DEBUGNBRL(x) DEBUGCOM(x);ft_debugnbrl(x)
#  define DEBUGNBRUL(x) DEBUGCOM(x);ft_debugnbrul(x, "0123456789")
#  define DEBUGNBRULB2(x) DEBUGCOM(x);ft_debugnbrul(x, "01")
#  define DEBUGNBRULB16(x) DEBUGCOM(x);ft_debugnbrul(x, "0123456789ABCEDF")
#  define DEBUGC(x) DEBUGCOM(x);ft_debugc(x)
#  define DEBUGPTR(x) DEBUGCOM(x);ft_debugptr(x)
# else
#  undef DEBUG
#  define DEBUG
#  define DEBUGSTR(x)
#  define DEBUGNBR(x)
#  define DEBUGNBRL(x)
#  define DEBUGNBRUL(x)
#  define DEBUGNBRULB2(x)
#  define DEBUGNBRULB16(x)
#  define DEBUGC(x)
#  define DEBUGPTR(x)
# endif

#endif
