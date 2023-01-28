/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:20:49 by muhcelik          #+#    #+#             */
/*   Updated: 2023/01/05 18:39:35 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pall(size_t num, char *mdf, int ctrl_p, int mdf_len)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	if (ctrl_p == 3)
	{
		if (!mdf)
			return (write(1, "(null)", 6));
		else
			while (mdf[++i])
				len += write(1, &mdf[i], 1);
		return (len);
	}
	if (ctrl_p == 1)
		len += write(1, "0x", 2);
	if ((int)num < 0 && ctrl_p == 2)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num / mdf_len != 0)
		len += ft_pall(num / mdf_len, mdf, 0, mdf_len);
	len += write(1, &mdf[num % mdf_len], 1);
	return (len);
}
