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
#include "matrix_dft.h"

#define SIZE  8

#define UPPER 5
#define LOWER -5

int
main(void)
{
	float complex** matrix_test;
	float complex* vector_test;
	float* vector_freq_test;

	srand((unsigned int)time(NULL));

	matrix_test		 = matrix_create_cpx(SIZE);
	vector_test		 = vector_create_cpx(SIZE);
	vector_freq_test = vector_create(SIZE);

	get_dft_freqs(vector_freq_test, SIZE, 0.1f);

	print_vector(vector_freq_test, SIZE);

	matrix_delete_cpx(matrix_test, SIZE);
	vector_delete_cpx(vector_test);

	return 0;
}
