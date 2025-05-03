############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Convolution2D
set_top Convolution2D
add_files Convolution2D.cpp
add_files Convolution2D.h
add_files -tb Convolution2D_tb.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./Convolution2D/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -wave_debug -trace_level all -tool xsim
export_design -format ip_catalog
