/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/07 15:47:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_uitoupperhexa_len(unsigned int n)
{
	unsigned int	n_len;
	unsigned int	diviseur;

	n_len = 0;
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		n_len++;
		diviseur = diviseur / 16;
	}
	return (n_len);
}

char	*ft_uitoa_hexa_maj(unsigned int n)
{
	char			*base;
	unsigned int	len;
	unsigned int	diviseur;
	unsigned int	result;
	char			*str;
	int				i;

	len = ft_uitoupperhexa_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	base = "0123456789ABCDEF";
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	i = 0;
	while (diviseur > 0)
	{
		result = (n / diviseur) % 16;
		str[i++] = base[result];
		diviseur = diviseur / 16;
	}
	str[i] = '\0';
	return (str);

}

void	ft_print_hexa_maj(t_flags *flags)
{
	unsigned int	X;
	char			*str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	X = va_arg(flags->args, unsigned int);
	str = ft_uitoa_hexa_maj(X);
	ft_treat_integer(str, flags);
	free(str);
}
