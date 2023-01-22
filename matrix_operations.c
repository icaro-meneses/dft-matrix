/*
 * ======================================================================
 *
 *       Filename:  matrix_operations.c
 *
 *    Description:  Source file for matrix_operations.h
 *
 *        Version:  1.0
 *        Created:  22/01/23 17:32:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>

float**
matrix_create(const int size_N)
{
	float** matrix_output_ptr;

	matrix_output_ptr = (float**)malloc(size_N * sizeof(float*));

	if (matrix_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s 2d array.\n",
			   "matrix_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int row = 0; row < size_N; row++)
	{
		matrix_output_ptr[row] =
			(float*)malloc(size_N * sizeof(float));

		if (matrix_output_ptr[row] == NULL)
		{
			printf("Error in memory allocation for %s[%d] array.\n",
				   "matrix_output_ptr",
				   row);
			exit(EXIT_FAILURE);
		}
	}

	return matrix_output_ptr;
}

void
print_matrix(float** matrix, const int size_N)
{
	for (int row = 0; row < size_N; row++)
	{
		for (int col = 0; col < size_N; col++)
		{
			printf("%6.2f ", matrix[row][col]);
		}
		printf("\n");
	}
	printf("\n\n");
}
