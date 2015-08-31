/*
 * Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "ompi/mpi/c/bindings.h"

#if OMPI_BUILD_MPI_PROFILING
#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_Type_struct = PMPI_Type_struct
#endif
#define MPI_Type_struct PMPI_Type_struct
#endif

#if OMPI_ENABLE_MPI_PROFILING
#define MPI_Type_create_struct PMPI_Type_create_struct
#endif

int MPI_Type_struct(int count,
                    int array_of_blocklengths[],
                    MPI_Aint array_of_displacements[],
                    MPI_Datatype array_of_types[],
                    MPI_Datatype *newtype)
{
    /* the param check will be done if necessary on the MPI_Type_create_struct */
    return MPI_Type_create_struct(count,
                                  array_of_blocklengths,
                                  array_of_displacements,
                                  array_of_types,
                                  newtype);
}
