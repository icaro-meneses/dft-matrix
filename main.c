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
#include <math.h>
#include "matrix_operations.h"
#include "matrix_dft.h"
#include "out_file.h"

#define DFT_SIZE 8192

int
main(void)
{
	float complex* signal_example;
	float complex* dft_output;
	float complex* inv_dft_output;
	float* dft_freqs;
	float* dft_abs;

	float freq_A, freq_B;
	float signal_freq;
	float total_time	   = 1.0f;
	float sample_frequency = 8.0e3f;
	float sample_period	   = 1.0f / sample_frequency;
	int signal_size = (int)ceilf(sample_frequency * total_time);

	printf("signal_size: %d\n", signal_size);

	signal_size = get_size(signal_size);
	printf("new signal_size: %d\n", signal_size);

	signal_example = vector_create_cpx(signal_size);
	dft_freqs	   = vector_create(DFT_SIZE);
	get_dft_freqs(dft_freqs, DFT_SIZE, sample_period);

	freq_A		= 1000.0f;
	freq_B		= 2000.0f;
	signal_freq = (float)gcd((int)freq_A, freq_B);
	for (int n = 0; n < signal_size; n++)
	{
		signal_example[n] =
			csinf(TWO_PI * freq_A * n * sample_period) +
			0.5f * csinf(TWO_PI * freq_B * n * sample_period +
						 ((3.0f * PI) / 4.0f));
	}

	dft_output	   = dft_calc(signal_example, DFT_SIZE, signal_size);
	dft_abs		   = abs_dft_calc(dft_output, DFT_SIZE);
	inv_dft_output = inv_dft_calc(dft_output, DFT_SIZE);

#ifdef DEBUG_MODE
	printf("Signal Example (Complex Form):\n");
	print_vector_cpx(signal_example, signal_size);
	printf("DFT Freqs:\n");
	print_vector(dft_freqs, DFT_SIZE);
	printf("DFT Output (Complex Form):\n");
	print_vector_cpx(dft_output, DFT_SIZE);
	printf("DFT Output (Magnitude):\n");
	print_vector(dft_abs, DFT_SIZE);
	printf("\nInverse DFT Output (Complex Form):\n");
	print_vector_cpx(inv_dft_output, signal_size);
#endif

	printf("Outputting the data files...\n");
	output_data_cpx("input_signal.txt", signal_example, signal_size);
	output_data("input_signal_params.txt",
				(float[]){signal_freq, sample_frequency},
				2);
	output_data("dft_freqs.txt", dft_freqs, DFT_SIZE);
	output_data_cpx("dft_out.txt", dft_output, DFT_SIZE);
	output_data("dft_abs.txt", dft_abs, DFT_SIZE);
	output_data_cpx("inv_dft.txt", inv_dft_output, signal_size);

	vector_delete_cpx(signal_example);
	vector_delete_cpx(dft_output);
	vector_delete(dft_freqs);
	vector_delete(dft_abs);
	vector_delete_cpx(inv_dft_output);

	return 0;
}
