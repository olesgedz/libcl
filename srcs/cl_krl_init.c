/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:32:12 by olesgedz          #+#    #+#             */
/*   Updated: 2019/10/19 22:29:16 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libcl.h"

void
	cl_krl_init
	(t_cl_krl *krl
	, size_t nargs)
{
	if (!(krl->args = ft_memalloc(sizeof(*krl->args) * nargs)))
		ft_malloc_err(sizeof(*krl->args) * nargs, __FUNCTION__,\
		__FILE__, __LINE__);
	if (!(krl->sizes = ft_memalloc(sizeof(*krl->sizes) * nargs)))
		ft_malloc_err(sizeof(*krl->sizes) * nargs,\
		__FUNCTION__, __FILE__, __LINE__);
	krl->nargs = nargs;
}
