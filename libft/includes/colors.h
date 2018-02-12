/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:35:35 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/22 18:44:48 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# ifndef BG_LIGHT

#  define DARK_BLACK    	"\033[0;30m"
#  define DARK_RED      	"\033[0;31m"
#  define DARK_GREEN    	"\033[0;32m"
#  define DARK_YELLOW   	"\033[0;33m"
#  define DARK_BLUE     	"\033[0;34m"
#  define DARK_PURPLE   	"\033[0;35m"
#  define DARK_CYAN     	"\033[0;36m"
#  define DARK_GREY     	"\033[0;37m"

#  define BLACK    			"\033[0;90m"
#  define RED      			"\033[91m"
#  define GREEN    			"\033[0;92m"
#  define YELLOW   			"\033[0;93m"
#  define BLUE     			"\033[0;94m"
#  define PURPLE   			"\033[0;95m"
#  define CYAN     			"\033[0;96m"
#  define GREY     			"\033[0;97m"

#  define HLIGHT_BLACK		"\033[40m"
#  define HLIGHT_RED		"\033[41m"
#  define HLIGHT_GREEN		"\033[42m"
#  define HLIGHT_YELLOW		"\033[43m"
#  define HLIGHT_DARK_BLUE	"\033[44m"
#  define HLIGHT_BLUE		"\033[104m"
#  define HLIGHT_PURPLE		"\033[45m"
#  define HLIGHT_CYAN		"\033[46m"
#  define HLIGHT_GREY		"\033[47m"

# endif

# define DEFAULT_COLOR "\033[0;m"
#endif
