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
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
get_size(int num)
{
	return (int)powf(2.0f, ceilf(logf((float)num) / logf(2.0f)));
}

int
gcd(int num_a, int num_b)
{
	int aux;

	while (num_b != 0)
	{
		aux	  = num_a % num_b;

		num_a = num_b;
		num_b = aux;
	}

	return num_a;
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

float complex**
matrix_create_cpx(const int size_N)
{
	float complex** matrix_output_ptr;

	matrix_output_ptr =
		(float complex**)malloc(size_N * sizeof(float complex*));

	if (matrix_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s 2d array.\n",
			   "matrix_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int row = 0; row < size_N; row++)
	{
		matrix_output_ptr[row] =
			(float complex*)malloc(size_N * sizeof(float complex));

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
			matrix_output_ptr[row][col] = 0.0f + 0.0f * I;
		}
	}

	return matrix_output_ptr;
}

float complex*
vector_create_cpx(const int size_N)
{
	float complex* vector_output_ptr;

	vector_output_ptr =
		(float complex*)malloc(size_N * sizeof(float complex));

	if (vector_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s vector.\n",
			   "vector_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int item = 0; item < size_N; item++)
	{
		vector_output_ptr[item] = 0.0f + 0.0f * I;
	}

	return vector_output_ptr;
}

void
print_matrix_cpx(float complex** matrix, const int size_N)
{
	printf("Square matrix (%d x %d):\n", size_N, size_N);
	for (int row = 0; row < size_N; row++)
	{
		for (int col = 0; col < size_N; col++)
		{
			printf("\t(%6.2f + %6.2fj) ",
				   crealf(matrix[row][col]),
				   cimagf(matrix[row][col]));
		}
		printf("\n");
	}
	printf("\n\n");
}

void
print_vector_cpx(float complex* vector, const int size_N)
{
	printf("Column vector (%d x 1) represented as row vector:\n",
		   size_N);
	for (int item = 0; item < size_N; item++)
	{
		printf("\t(%6.2f + %6.2fj) ",
			   crealf(vector[item]),
			   cimagf(vector[item]));
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
matrix_delete_cpx(float complex** matrix, const int size_N)
{
	for (int row = 0; row < size_N; row++)
	{
		free(matrix[row]);
	}

	free(matrix);
}

void
vector_delete_cpx(float complex* vector)
{
	free(vector);
}

void
vector_delete(float* vector)
{
	free(vector);
}

void
matrix_vector_mult_cpx(float complex** matrix,
					   float complex* vector,
					   const int size_N,
					   float complex* vector_result)
{
	float complex aux_value = 0.0f + 0.0f * I;

	for (int row = 0; row < size_N; row++)
	{
		aux_value = 0.0f + 0.0f * I;

#ifdef DEBUG_MODE
		printf("mult_out[%d] = ", row);
		for (int col = 0; col < size_N; col++)
		{
			printf("[%6.2f + (%6.2f)j] * [%6.2f + (%6.2f)j]",
				   crealf(matrix[row][col]),
				   cimagf(matrix[row][col]),
				   crealf(vector[col]),
				   cimagf(vector[col]));
			aux_value += (matrix[row][col] * vector[col]);

			if (col < (size_N - 1))
			{
				printf(" + ");
			}
		}
		printf(" = %6.2f + (%6.2f)j\n",
			   crealf(aux_value),
			   cimagf(aux_value));
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

