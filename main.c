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
#include <complex.h>
#include "matrix_operations.h"
#include "matrix_dft.h"
#include "out_file.h"

#define DFT_SIZE 8

int
main(void)
{
	float complex* signal_example;
	float complex* dft_output;
	float complex* inv_dft_output;
	float* dft_freqs;
	float* dft_abs;

	float freq_A, freq_B;
	float sample_frequency = 8000.0f;
	float sample_period	   = 1.0f / sample_frequency;

	signal_example		   = vector_create_cpx(DFT_SIZE);
	dft_freqs			   = vector_create(DFT_SIZE);
	get_dft_freqs(dft_freqs, DFT_SIZE, sample_period);

	freq_A = 1000.0f;
	freq_B = 2000.0f;
	for (int n = 0; n < DFT_SIZE; n++)
	{
		signal_example[n] =
			csinf(TWO_PI * freq_A * n * sample_period) +
			0.5f * csinf(TWO_PI * freq_B * n * sample_period +
						 ((3.0f * PI) / 4.0f));
	}

	dft_output	   = dft_calc(signal_example, DFT_SIZE, DFT_SIZE);
	dft_abs		   = abs_dft_calc(dft_output, DFT_SIZE);
	inv_dft_output = inv_dft_calc(dft_output, DFT_SIZE);

	printf("Signal Example (Complex Form):\n");
	print_vector_cpx(signal_example, DFT_SIZE);
	printf("DFT Freqs:\n");
	print_vector(dft_freqs, DFT_SIZE);
	printf("DFT Output (Complex Form):\n");
	print_vector_cpx(dft_output, DFT_SIZE);
	printf("DFT Output (Magnitude):\n");
	print_vector(dft_abs, DFT_SIZE);
	printf("\nInverse DFT Output (Complex Form):\n");
	print_vector_cpx(inv_dft_output, DFT_SIZE);

	printf("Outputting the data files...\n");
	output_data("dft_freqs.txt", dft_freqs, DFT_SIZE);
	output_data_cpx("dft_out.txt", dft_output, DFT_SIZE);
	output_data("dft_abs.txt", dft_abs, DFT_SIZE);

	vector_delete_cpx(signal_example);
	vector_delete_cpx(dft_output);
	vector_delete(dft_freqs);
	vector_delete(dft_abs);
	vector_delete_cpx(inv_dft_output);

	return 0;
}
