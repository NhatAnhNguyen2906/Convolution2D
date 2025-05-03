#include "Convolution2D.h"

void Convolution2D(
	const double input[INPUT_HEIGHT][INPUT_WIDTH],
	const double kernel[KERNEL_HEIGHT][KERNEL_WIDTH],
	double output[OUTPUT_HEIGHT][OUTPUT_WIDTH]
) {
	for(int i = 0; i < OUTPUT_HEIGHT; i++)
	{
		for(int j = 0; j < OUTPUT_WIDTH; j++)
		{
			double sum = 0.0;
			for(int m = 0; m < KERNEL_HEIGHT; m++)
			{
				for(int n = 0; n < KERNEL_WIDTH; n++)
				{
					sum += kernel[m][n] * input[i + m][j + n];
				}
			}
			output[i][j] = sum;
		}
	}
}
