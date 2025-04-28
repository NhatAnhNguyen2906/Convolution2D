 Design and Implementation of a 2D Convolution Accelerator Using Vivado HLS

I. Introduction 
This project is part of an embedded systems design course, aimed at designing and implementing a hardware accelerator for 2D convolution using Vivado HLS. The 2D convolution algorithm is developed in C, synthesized into RTL, and implemented on the Zynq-7000 platform. The project covers algorithm development, simulation, optimization, and hardware evaluation.

II. Objectives  
- Develop an algorithm for 2D convolution between an input image I and a kernel K.  
- Implement the algorithm in C and validate it via C simulation.  
- Synthesize the C code into RTL (VHDL/Verilog) using Vivado HLS.  
- Perform C/RTL co-simulation to ensure design correctness.  
- Optimize the design for improved hardware performance.  
- Implement the design on Zynq-7000 and evaluate resource utilization and performance.

III. Project Structure  
- "src/": Contains the C source code for the 2D convolution algorithm and testbench.  
- "hls/": Contains HLS scripts and code for RTL synthesis.  
- "vivado/": Contains the Vivado project for IP integration and bitstream generation.  
- "docs/": Contains the detailed report and related documentation.  
- "results/": Contains simulation results, resource usage, and performance reports.

IV.Setup and Run Instructions  
  1. Software Requirements:  
   - Xilinx Vivado HLS (2018).  
   - Xilinx Vivado  (2018).  
  2. Hardware Requirements:  
   - Zynq-7000 board (e.g., ZedBoard or ZC702).  
  3. Verify Results:  
   - Compare hardware output with C simulation results.  
   - Evaluate resource usage and performance from Vivado reports.
Team Members  
- Member 1: Nguyễn Nhật Anh - 2202904
- Member 2: Vũ Ngọc Duy - 22029023

Contributions  
- Member 1: Algorithm development, C code, and testbench.  
- Member 2: HLS optimization and Zynq-7000 implementation.

---

Note: This project is conducted as part of a course requirement and must not be copied or used without the authors' permission.
