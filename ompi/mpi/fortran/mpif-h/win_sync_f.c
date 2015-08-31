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
 * Copyright (c) 2011-2014 Cisco Systems, Inc.  All rights reserved.
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

#if OMPI_BUILD_MPI_PROFILING
#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak PMPI_WIN_SYNC = ompi_win_sync_f
#pragma weak pmpi_win_sync = ompi_win_sync_f
#pragma weak pmpi_win_sync_ = ompi_win_sync_f
#pragma weak pmpi_win_sync__ = ompi_win_sync_f

#pragma weak PMPI_Win_sync_f = ompi_win_sync_f
#pragma weak PMPI_Win_sync_f08 = ompi_win_sync_f
#else
OMPI_GENERATE_F77_BINDINGS (PMPI_WIN_SYNC,
                           pmpi_win_sync,
                           pmpi_win_sync_,
                           pmpi_win_sync__,
                           pompi_win_sync_f,
                           (MPI_Fint *win, MPI_Fint *ierr),
                           (win, ierr) )
#endif
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_WIN_SYNC = ompi_win_sync_f
#pragma weak mpi_win_sync = ompi_win_sync_f
#pragma weak mpi_win_sync_ = ompi_win_sync_f
#pragma weak mpi_win_sync__ = ompi_win_sync_f

#pragma weak MPI_Win_sync_f = ompi_win_sync_f
#pragma weak MPI_Win_sync_f08 = ompi_win_sync_f
#else
#if ! OMPI_BUILD_MPI_PROFILING
OMPI_GENERATE_F77_BINDINGS (MPI_WIN_SYNC,
                           mpi_win_sync,
                           mpi_win_sync_,
                           mpi_win_sync__,
                           ompi_win_sync_f,
                           (MPI_Fint *win, MPI_Fint *ierr),
                           (win, ierr) )
#else
#define ompi_win_sync_f pompi_win_sync_f
#endif
#endif

#if OMPI_ENABLE_MPI_PROFILING
#define MPI_Win_sync PMPI_Win_sync
#endif

void ompi_win_sync_f(MPI_Fint *win, MPI_Fint *ierr)
{
    int c_ierr;
    MPI_Win c_win = MPI_Win_f2c(*win);

    c_ierr = MPI_Win_sync(c_win);
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);
}
