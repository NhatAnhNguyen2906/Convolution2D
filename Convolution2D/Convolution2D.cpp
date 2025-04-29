#include "convolution2D.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
/* struct convolutionResult
{
	vector<vector<double>> output;
	string error;
};
*/
convolutionResult Convolution2D(
		const vector<vector<double> >& input,
		const vector<vector<double> >& kernel,
		int stride,
		int padding
)
{
	convolutionResult result;
	int input_height = input.size(); // input's height
	int input_width = input_height > 0 ? input[0].size() : 0; //input's width
	int kernel_height = kernel.size(); //kernel's height
	int kernel_width = kernel_height > 0 ? kernel[0].size() : 0; //kernel's width

	// Validate input dimensions and parameters
	if(input_height == 0 || input_width == 0 || kernel_height == 0 || kernel_width == 0 || stride <= 0)
	{
		result.error = "Invalid input dimensions or stride.";
		return result; // Return error message if dimensions are invalid
	}

	// Calculate output dimensions using convolution formula

	// Output height
	int output_height = floor((input_height + 2 * padding - kernel_height) / static_cast<double>(stride)) + 1;
	// Output width
	int output_width = floor((input_width + 2 * padding - kernel_width) / static_cast<double>(stride) + 1);
	// Check if output dimensions are valid
	if(output_height <= 0 || output_width <= 0)
	{
		result.error = "Output dimensions are invalid";
		return result;
	}
	// Initialize output matrix (dimensions output_height x output_width), all elements set = 0
	result.output = vector<vector<double> >(output_height, vector<double>(output_width, 0.0));

	// Perform convolution operation
	for(int i = 0; i < output_height; i++)
	{
		for(int j = 0; j < output_width; j++)
		{
			double sum = 0;
			for(int m = 0; m < kernel_height; m++)
			{
				for(int n = 0; n < kernel_width; n++)
				{
					//Calculate the corresponding input indices
					int input_row = i * stride + m - padding;
					int input_column = j * stride + n - padding;
					//Check if the input indices are within bounds
					if(input_row >= 0 && input_row < input_height && input_column >= 0 && input_column < input_width)
					{
						sum += kernel[m][n] * input[input_row][input_column];
					}
				}
			}
			result.output[i][j] = sum;
		}
	}
	return result;
}

void printMatrix(const vector<vector<double> >& matrix)
{
	for(size_t i = 0; i < matrix.size(); i++)
	{
		for(size_t j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
