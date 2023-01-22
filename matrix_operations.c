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

	for (int row = 0; row < size_N; row++)
	{
		for (int col = 0; col < size_N; col++)
		{
			matrix_output_ptr[row][col] = 0.0f;
		}
	}

	return matrix_output_ptr;
}

float*
vector_create(const int size_N)
{
	float* vector_output_ptr;

	vector_output_ptr = (float*)malloc(size_N * sizeof(float));

	if (vector_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s vector.\n",
			   "vector_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int item = 0; item < size_N; item++)
	{
		vector_output_ptr[item] = 0.0f;
	}

	return vector_output_ptr;
}

void
print_matrix(float** matrix, const int size_N)
{
	printf("Square matrix (%d x %d):\n", size_N, size_N);
	for (int row = 0; row < size_N; row++)
	{
		for (int col = 0; col < size_N; col++)
		{
			printf("\t%6.2f ", matrix[row][col]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void
print_vector(float* vector, const int size_N)
{
	printf("Column vector (%d x 1) represented as row vector:\n",
		   size_N);
	for (int item = 0; item < size_N; item++)
	{
		printf("\t%6.2f ", vector[item]);
	}
	printf("\n\n");
}

void
matrix_delete(float** matrix, const int size_N)
{
	for (int row = 0; row < size_N; row++)
	{
		free(matrix[row]);
	}

	free(matrix);
}

void
vector_delete(float* vector)
{
	free(vector);
}

void
matrix_vector_mult(float** matrix,
				   float* vector,
				   const int size_N,
				   float* vector_result)
{
	float aux_value = 0.0f;

	for (int row = 0; row < size_N; row++)
	{
		aux_value = 0.0f;

#ifdef DEBUG_MODE
		printf("mult_out[%d] = ", row);
		for (int col = 0; col < size_N; col++)
		{
			printf("(%6.2f * %6.2f)", matrix[row][col], vector[col]);
			aux_value += (matrix[row][col] * vector[col]);

			if (col < (size_N - 1))
			{
				printf(" + ");
			}
		}
		printf(" = %6.2f\n", aux_value);
#endif

#ifndef DEBUG_MODE
		for (int col = 0; col < size_N; col++)
		{
			aux_value += (matrix[row][col] * vector[col]);
		}
#endif

		vector_result[row] = aux_value;
	}
	printf("\n");
}

