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

void
fill_wn_matrix(float complex** matrix, const int size_N)
{
	/* In the martix of coefficients, k represents the rows and
	 * n represents the columns */
	for (int k = 0; k < size_N; k++)
	{
		for (int n = 0; n < size_N; n++)
		{
			matrix[k][n] = cexpf((-I * TWO_PI * k * n) / size_N);
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
	printf("aux: %d\n", aux);
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
