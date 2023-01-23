/*
 * ======================================================================
 *
 *       Filename:  out_file.h
 *
 *    Description:  Header file for function prototypes
 *					for operations on outputting data files
 *					and graphing.
 *
 *        Version:  1.0
 *        Created:  23/01/23 16:11:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef OUT_FILE_LIB_H
#define OUT_FILE_LIB_H

#include <complex.h>

/*
 * ===  FUNCTION  ==================================================
 *         Name:  output_data_cpx
 *  Description:  Generates a file containing the data
 *				  in columns in complex form: "REAL IMAG\n"
 * =================================================================
 */
void
output_data_cpx(char* file_name, float complex* data, int data_size);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  output_data
 *  Description:  Generates a file containing the data
 *				  in columns in form: "REAL\n"
 * =================================================================
 */
void
output_data(char* file_name, float* data, int data_size);

#endif
