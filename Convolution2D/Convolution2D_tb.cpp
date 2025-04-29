#include "convolution2D.h"
#include <iostream>

int main()
{
	vector<vector<double>> input = {
			{1, 1, 1, 0, 0},
			{0, 1, 1, 1, 0},
	        {0, 0, 1, 1, 1},
	        {0, 0, 1, 1, 0},
	        {0, 1, 1, 0, 0}	
	};
	vector<vector<double>> kernel = {
			{1, 0, 1},
			{0, 1, 0},
			{1, 0, 1}
	};
	cout << "Input Matrix:" << endl;
	printMatrix(input);
	cout << "Kernel Matrix:" << endl;
	printMatrix(kernel);
	
	auto output = Convolution2D(input, kernel, 1, 0);
	vector<vector<double>> expectedOutput = {
			{4, 3, 4},
			{2, 4, 3},
			{2, 3, 4}
	};
	bool correct = true;
	if(output.output.size() != expectedOutput.size() || output.output[0].size() != expectedOutput[0].size())
	{
		correct = false;
	}
	else
	{
		for(int i = 0; i < output.output.size(); i++)
		{
			for(int j = 0; j < output.output[0].size(); j++)
			{
				if(output.output[i][j] != expectedOutput[i][j])
				{
					correct = false;
					break;
				}
			}
		}
	}
	if(correct == true) cout << "Test: Passed";
	else cout << "Test: Failed";
	return 0;
}
