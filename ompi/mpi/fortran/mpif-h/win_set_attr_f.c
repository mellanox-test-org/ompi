/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2011-2012 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "ompi/mpi/fortran/mpif-h/bindings.h"
#include "ompi/attribute/attribute.h"
#include "ompi/win/win.h"


#if OMPI_BUILD_MPI_PROFILING
#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak PMPI_WIN_SET_ATTR = ompi_win_set_attr_f
#pragma weak pmpi_win_set_attr = ompi_win_set_attr_f
#pragma weak pmpi_win_set_attr_ = ompi_win_set_attr_f
#pragma weak pmpi_win_set_attr__ = ompi_win_set_attr_f

#pragma weak PMPI_Win_set_attr_f = ompi_win_set_attr_f
#pragma weak PMPI_Win_set_attr_f08 = ompi_win_set_attr_f
#else
OMPI_GENERATE_F77_BINDINGS (PMPI_WIN_SET_ATTR,
                           pmpi_win_set_attr,
                           pmpi_win_set_attr_,
                           pmpi_win_set_attr__,
                           pompi_win_set_attr_f,
                           (MPI_Fint *win, MPI_Fint *win_keyval, MPI_Aint *attribute_val, MPI_Fint *ierr),
                           (win, win_keyval, attribute_val, ierr) )
#endif
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_WIN_SET_ATTR = ompi_win_set_attr_f
#pragma weak mpi_win_set_attr = ompi_win_set_attr_f
#pragma weak mpi_win_set_attr_ = ompi_win_set_attr_f
#pragma weak mpi_win_set_attr__ = ompi_win_set_attr_f

#pragma weak MPI_Win_set_attr_f = ompi_win_set_attr_f
#pragma weak MPI_Win_set_attr_f08 = ompi_win_set_attr_f
#else
#if ! OMPI_BUILD_MPI_PROFILING
OMPI_GENERATE_F77_BINDINGS (MPI_WIN_SET_ATTR,
                           mpi_win_set_attr,
                           mpi_win_set_attr_,
                           mpi_win_set_attr__,
                           ompi_win_set_attr_f,
                           (MPI_Fint *win, MPI_Fint *win_keyval, MPI_Aint *attribute_val, MPI_Fint *ierr),
                           (win, win_keyval, attribute_val, ierr) )
#else
#define ompi_win_set_attr_f pompi_win_set_attr_f
#endif
#endif

#if OMPI_ENABLE_MPI_PROFILING
#define MPI_Win_set_attr PMPI_Win_set_attr
#endif

void ompi_win_set_attr_f(MPI_Fint *win, MPI_Fint *win_keyval,
			MPI_Aint *attribute_val, MPI_Fint *ierr)
{
    int c_ierr;
    MPI_Win c_win = MPI_Win_f2c(*win);

    /* This stuff is very confusing.  Be sure to see the comment at
       the top of src/attributes/attributes.c. */

    c_ierr = ompi_attr_set_fortran_mpi2(WIN_ATTR,
                                        c_win,
                                        &c_win->w_keyhash,
                                        OMPI_FINT_2_INT(*win_keyval),
                                        *attribute_val,
                                        false);
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);
}
