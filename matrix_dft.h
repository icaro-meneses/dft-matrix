/*
 * ======================================================================
 *
 *       Filename:  matrix_dft.h
 *
 *    Description:  Header file for DFT(Matrix) implementation, which
 *					contains function prototypes.
 *
 *        Version:  1.0
 *        Created:  22/01/23 21:03:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef MATRIX_DFT_LIB_H
#define MATRIX_DFT_LIB_H

#include <complex.h>

#define PI	   3.141592653589793f
#define TWO_PI (2.0 * PI)

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fill_wn_matrix
 *  Description:  Fill the (NxN) matrix with the W^(kn)
 *				  coefficients
 * =================================================================
 */
void
fill_wn_matrix(float complex** matrix, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fill_x_vector
 *  Description:  Fill the (Nx1) vector with the signal
 *				  sampled in the discrete time
 * =================================================================
 */
void
fill_x_vector(float complex* dtf_vector,
			  float complex* signal,
			  const int dft_vector_size,
			  const int signal_size);

void
get_dft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing);

#endif
