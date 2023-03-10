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
#include <stdbool.h>

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
fill_wn_matrix(float complex** matrix,
			   const int size_N,
			   bool inv_dft_mode);

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

/*
 * ===  FUNCTION  ==================================================
 *         Name:  get_dft_freqs
 *  Description:  Fill a array with the DFT sample frequencies
 * ==================================================================
 */
void
get_dft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  dft_calc
 *  Description:  Performs the Discrete Fourier Transform of a
 *				  sampled signal as input and returns a vector
 *				  with the complex values of DFT.
 * =================================================================
 */
float complex*
dft_calc(float complex* signal,
		 const int dft_size,
		 const int signal_size);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  abs_dft_calc
 *  Description:  Calculates the magnitude(absolute value) of
 *				  a previous calculated DFT.
 * =================================================================
 */
float*
abs_dft_calc(float complex* dft, const int dft_size);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  inv_dft_calc
 *  Description:  Performs the Inverse Discrete Fourier Transform
 *				  of a DFT input and returns a vector with the
 *				  complex values of IDFT.
 * =================================================================
 */
float complex*
inv_dft_calc(float complex* dft, const int dft_size);

#endif
