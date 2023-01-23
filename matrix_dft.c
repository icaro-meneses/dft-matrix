/*
 * ======================================================================
 *
 *       Filename:  matrix_dft.c
 *
 *    Description:  Source file for matrix_dft.h, including function
 *					implementations.
 *
 *        Version:  1.0
 *        Created:  22/01/23 21:04:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "matrix_dft.h"
#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <stdbool.h>

void
fill_wn_matrix(float complex** matrix,
			   const int size_N,
			   bool inv_dft_mode)
{
	/* If the mode is DFT */
	if (!inv_dft_mode)
	{
		/* In the martix of coefficients, k represents the rows and
		 * n represents the columns */
		for (int k = 0; k < size_N; k++)
		// for (int n = 0; n < size_N; n++)
		{
			for (int n = 0; n < size_N; n++)
			// for (int k = 0; k < size_N; k++)
			{
				matrix[n][k] = cexpf((-I * TWO_PI * k * n) / size_N);
			}
		}
	}

	/* If the mode is Inverse DFT */
	else
	{
		/* In the martix of coefficients, k represents the rows and
		 * n represents the columns */
		for (int k = 0; k < size_N; k++)
		{
			for (int n = 0; n < size_N; n++)
			{
				matrix[k][n] = (1.0f / size_N) *
							   cexpf((I * TWO_PI * k * n) / size_N);
			}
		}
	}
}

void
fill_x_vector(float complex* dft_vector,
			  float complex* signal,
			  const int dft_vector_size,
			  const int signal_size)
{
	int fill_op_size = signal_size;

	if (signal_size > dft_vector_size)
	{
		fill_op_size = dft_vector_size;
	}

	for (int item = 0; item < fill_op_size; item++)
	{
		dft_vector[item] = signal[item];
	}
}

void
get_dft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing)
{
	int middle = ((window_length - 1) / 2) + 1;
	int i;
	int aux = 0;

	for (i = 0; i < middle; i++)
	{
		freq_array[i] = i;
	}

	i	= middle;
	aux = (-1) * (window_length / 2);
	while (aux < 0)
	{
		freq_array[i] = aux;

		aux++;
		i++;
	}

	for (i = 0; i < window_length; i++)
	{
		freq_array[i] =
			(float)freq_array[i] / (window_length * sample_spacing);
	}
}

float complex*
dft_calc(float complex* signal,
		 const int dft_size,
		 const int signal_size)
{
	float complex** coef_wn_matrix;
	float complex* xn_vector;
	float complex* result_dft;

	coef_wn_matrix = matrix_create_cpx(dft_size);
	xn_vector	   = vector_create_cpx(dft_size);
	result_dft	   = vector_create_cpx(dft_size);

	fill_wn_matrix(coef_wn_matrix, dft_size, false);
	fill_x_vector(xn_vector, signal, dft_size, signal_size);

#ifdef DEBUG_MODE
	printf("Coefficents matrix:\n");
	print_matrix_cpx(coef_wn_matrix, dft_size);

	printf("X(n) vector:\n");
	print_vector_cpx(xn_vector, dft_size);
#endif

	matrix_vector_mult_cpx(coef_wn_matrix,
						   xn_vector,
						   dft_size,
						   result_dft);

	matrix_delete_cpx(coef_wn_matrix, dft_size);
	vector_delete_cpx(xn_vector);

	return result_dft;
}

float*
abs_dft_calc(float complex* dft, const int dft_size)
{
	float* dft_abs_output;

	dft_abs_output = vector_create(dft_size);

	for (int item = 0; item < dft_size; item++)
	{
		dft_abs_output[item] = cabsf(dft[item]);
	}

	return dft_abs_output;
}

float complex*
inv_dft_calc(float complex* dft, const int dft_size)
{
	float complex** coef_wn_matrix;
	float complex* xn_vector;
	float complex* result_inv_dft;

	coef_wn_matrix = matrix_create_cpx(dft_size);
	xn_vector	   = vector_create_cpx(dft_size);
	result_inv_dft = vector_create_cpx(dft_size);

	fill_wn_matrix(coef_wn_matrix, dft_size, true);
	fill_x_vector(xn_vector, dft, dft_size, dft_size);

	matrix_vector_mult_cpx(coef_wn_matrix,
						   xn_vector,
						   dft_size,
						   result_inv_dft);

	matrix_delete_cpx(coef_wn_matrix, dft_size);
	vector_delete_cpx(xn_vector);

	return result_inv_dft;
}
