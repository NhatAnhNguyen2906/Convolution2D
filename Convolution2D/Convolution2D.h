#ifndef CONVOLUTION2D_H
#define CONVOLUTION2D_H

#include <vector>
#include <string>
using namespace std;
/* Function to perform 2D convolution
 Parameters:
 - input: Input matrix (2D vector) with dimensions H x W
 - kernel: Kernel matrix (2D vector) with dimensions M_h x M_w
 - stride: Step size for sliding the kernel (default = 1)
 - padding: Number of rows/columns to pad around the input matrix (default = 0)
 */
struct convolutionResult {
    vector<vector<double> > output;
    string error;
};


convolutionResult Convolution2D(
    const vector<vector<double> >& input,
    const vector<vector<double> >& kernel,
    int stride = 1,
    int padding = 0
);

// Print matrix for verification
void printMatrix(const vector<vector<double> >& matrix);

#endif
