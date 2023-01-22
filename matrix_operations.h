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

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_create
 *  Description:  Create a (NxN) matrix defined by size.
 * =================================================================
 */
float**
matrix_create(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_matrix
 *  Description:  Print the (NxN) matrix in stdout.
 * =================================================================
 */
void
print_matrix(float** matrix, const int size_N);

#endif
