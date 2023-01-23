/*
 * ======================================================================
 *
 *       Filename:  out_file.c
 *
 *    Description:  Source file for functions for outputting data
 *					files and graphing.
 *
 *        Version:  1.0
 *        Created:  23/01/23 16:17:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "out_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void
output_data_cpx(char* file_name, float complex* data, int data_size)
{
	FILE* file_pointer = fopen(file_name, "w");

	if (file_pointer == NULL)
	{
		printf("Error in creating the file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	for (int n = 0; n < data_size; n++)
	{
		fprintf(file_pointer,
				"%.4f %.4f\n",
				crealf(data[n]),
				cimagf(data[n]));
	}

	fclose(file_pointer);
}

void
output_data(char* file_name, float* data, int data_size)
{
	FILE* file_pointer = fopen(file_name, "w");

	if (file_pointer == NULL)
	{
		printf("Error in creating the file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	for (int n = 0; n < data_size; n++)
	{
		fprintf(file_pointer, "%.4f\n", data[n]);
	}

	fclose(file_pointer);
}
