// ==============================================================
// File generated on Sat May 03 15:55:51 +0700 2025
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "input_r"
#define AUTOTB_TVIN_input_r  "../tv/cdatafile/c.Convolution2D.autotvin_input_r.dat"
// wrapc file define: "kernel"
#define AUTOTB_TVIN_kernel  "../tv/cdatafile/c.Convolution2D.autotvin_kernel.dat"
// wrapc file define: "output_r"
#define AUTOTB_TVOUT_output_r  "../tv/cdatafile/c.Convolution2D.autotvout_output_r.dat"
#define AUTOTB_TVIN_output_r  "../tv/cdatafile/c.Convolution2D.autotvin_output_r.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "output_r"
#define AUTOTB_TVOUT_PC_output_r  "../tv/rtldatafile/rtl.Convolution2D.autotvout_output_r.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			input_r_depth = 0;
			kernel_depth = 0;
			output_r_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{input_r " << input_r_depth << "}\n";
			total_list << "{kernel " << kernel_depth << "}\n";
			total_list << "{output_r " << output_r_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int input_r_depth;
		int kernel_depth;
		int output_r_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void Convolution2D (
const double input[5][5],
const double kernel[3][3],
double output[3][3]);

void AESL_WRAP_Convolution2D (
const double input[5][5],
const double kernel[3][3],
double output[3][3])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "output_r"
		aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // data

			sc_bv<64> *output_r_pc_buffer = new sc_bv<64>[9];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'output_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'output_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					output_r_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_output_r))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: output_r
				{
					// bitslice(63, 0)
					// {
						// celement: output(63, 0)
						// {
							sc_lv<64>* output_lv0_0_2_1_lv1_0_2_1 = new sc_lv<64>[9];
						// }
					// }

					// bitslice(63, 0)
					{
						int hls_map_index = 0;
						// celement: output(63, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (2) @ (1)
								for (int i_1 = 0; i_1 <= 2; i_1 += 1)
								{
									if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
									{
										output_lv0_0_2_1_lv1_0_2_1[hls_map_index].range(63, 0) = sc_bv<64>(output_r_pc_buffer[hls_map_index].range(63, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(63, 0)
					{
						int hls_map_index = 0;
						// celement: output(63, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (2) @ (1)
								for (int i_1 = 0; i_1 <= 2; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : output[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : output[0][0]
									// output_left_conversion : *(long long*)&output[i_0][i_1]
									// output_type_conversion : (output_lv0_0_2_1_lv1_0_2_1[hls_map_index]).to_uint64()
									if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
									{
										*(long long*)&output[i_0][i_1] = (output_lv0_0_2_1_lv1_0_2_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] output_r_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "input_r"
		char* tvin_input_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_input_r);

		// "kernel"
		char* tvin_kernel = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel);

		// "output_r"
		char* tvin_output_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_output_r);
		char* tvout_output_r = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_output_r);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_input_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_input_r, tvin_input_r);

		sc_bv<64>* input_r_tvin_wrapc_buffer = new sc_bv<64>[25];

		// RTL Name: input_r
		{
			// bitslice(63, 0)
			{
				int hls_map_index = 0;
				// celement: input(63, 0)
				{
					// carray: (0) => (4) @ (1)
					for (int i_0 = 0; i_0 <= 4; i_0 += 1)
					{
						// carray: (0) => (4) @ (1)
						for (int i_1 = 0; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : input[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : input[0][0]
							// regulate_c_name       : input
							// input_type_conversion : *(long long*)&input[i_0][i_1]
							if (&(input[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<64> input_tmp_mem;
								input_tmp_mem = *(long long*)&input[i_0][i_1];
								input_r_tvin_wrapc_buffer[hls_map_index].range(63, 0) = input_tmp_mem.range(63, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 25; i++)
		{
			sprintf(tvin_input_r, "%s\n", (input_r_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_input_r, tvin_input_r);
		}

		tcl_file.set_num(25, &tcl_file.input_r_depth);
		sprintf(tvin_input_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_input_r, tvin_input_r);

		// release memory allocation
		delete [] input_r_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel, tvin_kernel);

		sc_bv<64>* kernel_tvin_wrapc_buffer = new sc_bv<64>[9];

		// RTL Name: kernel
		{
			// bitslice(63, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(63, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (2) @ (1)
						for (int i_1 = 0; i_1 <= 2; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : *(long long*)&kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<64> kernel_tmp_mem;
								kernel_tmp_mem = *(long long*)&kernel[i_0][i_1];
								kernel_tvin_wrapc_buffer[hls_map_index].range(63, 0) = kernel_tmp_mem.range(63, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 9; i++)
		{
			sprintf(tvin_kernel, "%s\n", (kernel_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel, tvin_kernel);
		}

		tcl_file.set_num(9, &tcl_file.kernel_depth);
		sprintf(tvin_kernel, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel, tvin_kernel);

		// release memory allocation
		delete [] kernel_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_output_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);

		sc_bv<64>* output_r_tvin_wrapc_buffer = new sc_bv<64>[9];

		// RTL Name: output_r
		{
			// bitslice(63, 0)
			{
				int hls_map_index = 0;
				// celement: output(63, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (2) @ (1)
						for (int i_1 = 0; i_1 <= 2; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : output[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : output[0][0]
							// regulate_c_name       : output
							// input_type_conversion : *(long long*)&output[i_0][i_1]
							if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<64> output_tmp_mem;
								output_tmp_mem = *(long long*)&output[i_0][i_1];
								output_r_tvin_wrapc_buffer[hls_map_index].range(63, 0) = output_tmp_mem.range(63, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 9; i++)
		{
			sprintf(tvin_output_r, "%s\n", (output_r_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);
		}

		tcl_file.set_num(9, &tcl_file.output_r_depth);
		sprintf(tvin_output_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);

		// release memory allocation
		delete [] output_r_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		Convolution2D(input, kernel, output);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_output_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);

		sc_bv<64>* output_r_tvout_wrapc_buffer = new sc_bv<64>[9];

		// RTL Name: output_r
		{
			// bitslice(63, 0)
			{
				int hls_map_index = 0;
				// celement: output(63, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (2) @ (1)
						for (int i_1 = 0; i_1 <= 2; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : output[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : output[0][0]
							// regulate_c_name       : output
							// input_type_conversion : *(long long*)&output[i_0][i_1]
							if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<64> output_tmp_mem;
								output_tmp_mem = *(long long*)&output[i_0][i_1];
								output_r_tvout_wrapc_buffer[hls_map_index].range(63, 0) = output_tmp_mem.range(63, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 9; i++)
		{
			sprintf(tvout_output_r, "%s\n", (output_r_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);
		}

		tcl_file.set_num(9, &tcl_file.output_r_depth);
		sprintf(tvout_output_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);

		// release memory allocation
		delete [] output_r_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "input_r"
		delete [] tvin_input_r;
		// release memory allocation: "kernel"
		delete [] tvin_kernel;
		// release memory allocation: "output_r"
		delete [] tvout_output_r;
		delete [] tvin_output_r;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

