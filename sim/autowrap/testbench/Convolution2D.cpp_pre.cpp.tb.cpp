// ==============================================================
// File generated on Sat May 03 15:55:50 +0700 2025
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#1 "C:/Users/lenovo/Convolution2D/Convolution2D.cpp"
#1 "<built-in>"
#1 "<command-line>"
#1 "C:/Users/lenovo/Convolution2D/Convolution2D.cpp"
#1 "C:/Users/lenovo/Convolution2D/Convolution2D.h" 1
#11 "C:/Users/lenovo/Convolution2D/Convolution2D.h"
void Convolution2D
(
 const double input[5][5],
 const double kernel[3][3],
 double output[(5 - 3 + 1)][(5 - 3 + 1)]
);
#2 "C:/Users/lenovo/Convolution2D/Convolution2D.cpp" 2

void Convolution2D(
 const double input[5][5],
 const double kernel[3][3],
 double output[(5 - 3 + 1)][(5 - 3 + 1)]
) {
 for(int i = 0; i < (5 - 3 + 1); i++)
 {
  for(int j = 0; j < (5 - 3 + 1); j++)
  {
   double sum = 0.0;
   for(int m = 0; m < 3; m++)
   {
    for(int n = 0; n < 3; n++)
    {
     sum += kernel[m][n] * input[i + m][j + n];
    }
   }
   output[i][j] = sum;
  }
 }
}
