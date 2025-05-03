#include "Convolution2D.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
// readMatrix function from txt file, fill 0
void readMatrix(double matrix[], int height, int width, ifstream& file)
{
    for(int i = 0; i < height * width; i++)
    {
        matrix[i] = 0.0;
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(!(file >> matrix[i * width + j]))
            {
                break;
            }
        }
        if(file.eof()) break;
    }
}

void writeMatrix(const double matrix[], int height, int width, const char* filename)
{
    ofstream file(filename);
    if(file.is_open())
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                file << matrix[i * width + j] << " ";
            }
            file << "\n";
        }
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1); 
    }
}

bool compareMatrices(const double matrix1[], const double matrix2[], int height, int width)
{
    const double tmp = 0.0;
    for(int i = 0; i < height * width; i++)
    {
        if(abs(matrix1[i] - matrix2[i]) > tmp)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    double input[INPUT_HEIGHT * INPUT_WIDTH];
    double kernel[KERNEL_HEIGHT * KERNEL_WIDTH];
    double output[OUTPUT_HEIGHT * OUTPUT_WIDTH];
    double golden_output[OUTPUT_HEIGHT * OUTPUT_WIDTH];

    ifstream input_file("C:/Users/lenovo/Convolution2D/input.txt");
    if(!(input_file.is_open()))
    {
        cerr << "Error: Unable to open file input.txt" << endl;
        return 1;
    }

    readMatrix(input, INPUT_HEIGHT, INPUT_WIDTH, input_file);

    readMatrix(kernel, KERNEL_HEIGHT, KERNEL_WIDTH, input_file);
    input_file.close();

    double input2D[INPUT_HEIGHT][INPUT_WIDTH];
    double kernel2D[KERNEL_HEIGHT][KERNEL_WIDTH];
    double output2D[OUTPUT_HEIGHT][OUTPUT_WIDTH];

    for(int i = 0; i < INPUT_HEIGHT; i++)
    {
        for(int j = 0; j < INPUT_WIDTH; j++)
        {
            input2D[i][j] = input[i * INPUT_WIDTH + j];
        }
    }
    for(int i = 0; i < KERNEL_HEIGHT; i++)
    {
        for(int j = 0; j < KERNEL_WIDTH; j++)
        {
            kernel2D[i][j] = kernel[i * KERNEL_WIDTH + j];
        }
    }
    Convolution2D(input2D, kernel2D, output2D);

    for(int i = 0; i < OUTPUT_HEIGHT; i++)
    {
        for(int j = 0; j < OUTPUT_WIDTH; j++)
        {
            output[i * OUTPUT_WIDTH + j] = output2D[i][j];
        }
    }
    writeMatrix(output, OUTPUT_HEIGHT, OUTPUT_WIDTH, "C:/Users/lenovo/Convolution2D/result.txt");
    ifstream golden_file("C:/Users/lenovo/Convolution2D/golden_result.txt");
    if(!golden_file.is_open())
    {
        cerr << "Error: Unable to open file golden_result.txt" << endl;
        return 1;
    }
    readMatrix(golden_output, OUTPUT_HEIGHT, OUTPUT_WIDTH, golden_file);
    golden_file.close();
    if(compareMatrices(output, golden_output, OUTPUT_HEIGHT, OUTPUT_WIDTH))
    {
        cout << "Test passed" << endl;
    }
    else cout << "Test failed" << endl;
    return 0;
}
