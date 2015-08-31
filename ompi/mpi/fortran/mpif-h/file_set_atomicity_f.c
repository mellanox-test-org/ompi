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

#if OMPI_BUILD_MPI_PROFILING
#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak PMPI_FILE_SET_ATOMICITY = ompi_file_set_atomicity_f
#pragma weak pmpi_file_set_atomicity = ompi_file_set_atomicity_f
#pragma weak pmpi_file_set_atomicity_ = ompi_file_set_atomicity_f
#pragma weak pmpi_file_set_atomicity__ = ompi_file_set_atomicity_f

#pragma weak PMPI_File_set_atomicity_f = ompi_file_set_atomicity_f
#pragma weak PMPI_File_set_atomicity_f08 = ompi_file_set_atomicity_f
#else
OMPI_GENERATE_F77_BINDINGS (PMPI_FILE_SET_ATOMICITY,
                           pmpi_file_set_atomicity,
                           pmpi_file_set_atomicity_,
                           pmpi_file_set_atomicity__,
                           pompi_file_set_atomicity_f,
                           (MPI_Fint *fh, ompi_fortran_logical_t *flag, MPI_Fint *ierr),
                           (fh, flag, ierr) )
#endif
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_FILE_SET_ATOMICITY = ompi_file_set_atomicity_f
#pragma weak mpi_file_set_atomicity = ompi_file_set_atomicity_f
#pragma weak mpi_file_set_atomicity_ = ompi_file_set_atomicity_f
#pragma weak mpi_file_set_atomicity__ = ompi_file_set_atomicity_f

#pragma weak MPI_File_set_atomicity_f = ompi_file_set_atomicity_f
#pragma weak MPI_File_set_atomicity_f08 = ompi_file_set_atomicity_f
#else
#if ! OMPI_BUILD_MPI_PROFILING
OMPI_GENERATE_F77_BINDINGS (MPI_FILE_SET_ATOMICITY,
                           mpi_file_set_atomicity,
                           mpi_file_set_atomicity_,
                           mpi_file_set_atomicity__,
                           ompi_file_set_atomicity_f,
                           (MPI_Fint *fh, ompi_fortran_logical_t *flag, MPI_Fint *ierr),
                           (fh, flag, ierr) )
#else
#define ompi_file_set_atomicity_f pompi_file_set_atomicity_f
#endif
#endif

#if OMPI_ENABLE_MPI_PROFILING
#define MPI_File_set_atomicity PMPI_File_set_atomicity
#endif

void ompi_file_set_atomicity_f(MPI_Fint *fh, ompi_fortran_logical_t *flag, MPI_Fint *ierr)
{
    int c_ierr;
    MPI_File c_fh = MPI_File_f2c(*fh);

    c_ierr = MPI_File_set_atomicity(c_fh,
                                    OMPI_LOGICAL_2_INT(*flag));
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);
}
