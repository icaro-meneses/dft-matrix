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
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "matrix_operations.h"

#define SIZE  3

#define UPPER 5
#define LOWER -5

int
main(void)
{
	float complex** matrix_test;
	float complex* vector_test;
	float complex* vector_mult;

	srand((unsigned int)time(NULL));

	matrix_test = matrix_create(SIZE);
	vector_test = vector_create(SIZE);
	vector_mult = vector_create(SIZE);

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			matrix_test[row][col] =
				((rand() % (UPPER - LOWER + 1)) + LOWER) +
				((rand() % (UPPER - LOWER + 1)) + LOWER) * I;
		}
	}

	for (int item = 0; item < SIZE; item++)
	{
		vector_test[item] =
			((rand() % (UPPER - LOWER + 1)) + LOWER) +
			((rand() % (UPPER - LOWER + 1)) + LOWER) * I;
	}

	print_matrix(matrix_test, SIZE);
	print_vector(vector_test, SIZE);
	print_vector(vector_mult, SIZE);

	matrix_vector_mult(matrix_test, vector_test, SIZE, vector_mult);

	print_vector(vector_mult, SIZE);

	matrix_delete(matrix_test, SIZE);
	vector_delete(vector_test);
	vector_delete(vector_mult);

	return 0;
}
