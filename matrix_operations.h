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
 *         Name:  get_size
 *  Description:  Determines the size of a signal to power
 *				  of 2.
 * =================================================================
 */
int
get_size(int num);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  gcd
 *  Description:  Determines the Greater Common Divisor
 *				  between two integers.
 * =================================================================
 */
int
gcd(int num_a, int num_b);

float*
vector_create(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_create_cpx
 *  Description:  Create a (NxN) matrix defined by size.
 * =================================================================
 */
float complex**
matrix_create_cpx(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  vector_create_cpx
 *  Description:  Create a complex (Nx1) matrix defined by size.
 * =================================================================
 */
float complex*
vector_create_cpx(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_matrix_cpx
 *  Description:  Print the complex (NxN) matrix in stdout.
 * =================================================================
 */
void
print_matrix_cpx(float complex** matrix, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_vector_cpx
 *  Description:  Print the complex (Nx1) vector in stdout.
 * =================================================================
 */
void
print_vector_cpx(float complex* vector, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_vector_cpx
 *  Description:  Print the (Nx1) vector in stdout.
 * =================================================================
 */
void
print_vector(float* vector, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete_cpx
 *  Description:  Free the memory allocated in complex matrix
 * =================================================================
 */
void
matrix_delete_cpx(float complex** matrix, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete_cpx
 *  Description:  Free the memory allocated in complex vector
 * =================================================================
 */
void
vector_delete_cpx(float complex* vector);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete_cpx
 *  Description:  Free the memory allocated in vector
 * =================================================================
 */
void
vector_delete(float* vector);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_vector_mult_cpx
 *  Description:  Performs multiplication between a complex
 *				  matrix(NxN) and complex vector(Nx1) and
 *				  returns a complex vector(Nx1).
 * =================================================================
 */
void
matrix_vector_mult_cpx(float complex** matrix,
					   float complex* vector,
					   const int size_N,
					   float complex* vector_result);

#endif
