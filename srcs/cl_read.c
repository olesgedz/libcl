/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:32:17 by olesgedz          #+#    #+#             */
/*   Updated: 2019/08/30 23:32:18 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libcl.h"

cl_int
	cl_read
	(t_cl_info *cl
	, cl_mem mem
	, size_t size
	, void *data)
{
	clFinish(cl->cmd_queue);
	return (clEnqueueReadBuffer(cl->cmd_queue
		, mem
		, CL_TRUE
		, 0
		, size
		, data
		, 0
		, NULL
		, NULL));
}
