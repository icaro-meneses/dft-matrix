/*
 * ======================================================================
 *
 *       Filename:  matrix_operations.h
 *
 *    Description:  Header file for matrix operations function
 *					prototypes.
 *
 *        Version:  1.0
 *        Created:  22/01/23 17:26:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef MAT_OP_LIB_H
#define MAT_OP_LIB_H

#include <complex.h>

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_create
 *  Description:  Create a (NxN) matrix defined by size.
 * =================================================================
 */
float complex**
matrix_create(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  vector_create
 *  Description:  Create a (Nx1) matrix defined by size.
 * =================================================================
 */
float complex*
vector_create(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_matrix
 *  Description:  Print the (NxN) matrix in stdout.
 * =================================================================
 */
void
print_matrix(float complex** matrix, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_vector
 *  Description:  Print the (Nx1) vector in stdout.
 * =================================================================
 */
void
print_vector(float complex* vector, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete
 *  Description:  Free the memory allocated in matrix
 * =================================================================
 */
void
matrix_delete(float complex** matrix, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete
 *  Description:  Free the memory allocated in vector
 * =================================================================
 */
void
vector_delete(float complex* vector);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_vector_mult
 *  Description:  Performs multiplication between a matrix(NxN) and
 *				  vector(Nx1) and returns a vector(Nx1).
 * =================================================================
 */
void
matrix_vector_mult(float complex** matrix,
				   float complex* vector,
				   const int size_N,
				   float complex* vector_result);

#endif
