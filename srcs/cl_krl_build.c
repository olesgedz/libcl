/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:10:44 by jblack-b          #+#    #+#             */
/*   Updated: 2019/10/22 18:16:24 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"
#include "libgnl.h"
#include "libcl.h"

cl_int				cl_krl_build(t_cl_info *cl,\
	t_cl_krl *krl, t_vect *kernel_names)
{
	unsigned char	**names;
	int				i;
	cl_int			ret;

	i = -1;
	names = ft_nsplit((*kernel_names).data,\
	(*kernel_names).used, ":", sizeof(":") - 1);
	while ((char *)names[++i])
	{
		if (!(krl[i].krl = clCreateKernel(cl->prog, (char *)names[i], &ret)))
			return (ret);
	}
	ft_2darray_uchar_free(&names);
	return (ret);
}
