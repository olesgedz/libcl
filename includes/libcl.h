/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:31:36 by olesgedz          #+#    #+#             */
/*   Updated: 2019/10/22 18:26:21 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCL_H
# define LIBCL_H

# include "libvect.h"
# define CL_SILENCE_DEPRECATION
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef struct			s_cl_info
{
	cl_platform_id		pl_id;
	cl_device_id		dev_id;
	cl_context			ctxt;
	cl_command_queue	cmd_queue;
	cl_program			prog;
	cl_uint				dev_num;
	cl_int				ret;
	t_vect				*krl_names;
}						t_cl_info;

typedef struct			s_cl_krl
{
	cl_kernel			krl;
	cl_mem				*args;
	size_t				*sizes;
	size_t				nargs;
}						t_cl_krl;

cl_int					cl_prog_build(t_cl_info *cl, t_cl_krl *krl, int fd,
	char *string);
cl_int					cl_krl_exec
	(t_cl_info *cl, cl_kernel krl, cl_uint work_dim, size_t *work_size);
cl_int					cl_read
	(t_cl_info *cl, cl_mem mem, size_t size, void *data);
cl_int					cl_write
	(t_cl_info *cl, cl_mem mem, size_t size, void *data);
cl_int					cl_init(t_cl_info *cl);
void					cl_krl_init(t_cl_krl *krl, size_t nargs);
cl_int					krl_set_args(cl_context ctxt, t_cl_krl *krl);
cl_int					cl_krl_build(t_cl_info *cl,\
	t_cl_krl *krl, t_vect *kernel_names);
#endif
