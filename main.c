/*
 * ======================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  DFT Calculation
 *
 *        Version:  1.0
 *        Created:  22/01/23 17:02:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include <stdio.h>
#include "matrix_operations.h"

#define SIZE 4

int
main(void)
{
	float** matrix_test;
	float* vector_test;

	matrix_test = matrix_create(SIZE);
	vector_test = vector_create(SIZE);

#ifdef DEBUG_MODE
	print_matrix(matrix_test, SIZE);
	print_vector(vector_test, SIZE);
#endif

	matrix_delete(matrix_test, SIZE);
	vector_delete(vector_test);

	return 0;
}
