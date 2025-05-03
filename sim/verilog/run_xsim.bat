
set PATH=
call D:/Vitis_2018/Vivado/2018.3/bin/xelab xil_defaultlib.apatb_Convolution2D_top glbl -prj Convolution2D.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "D:/Vitis_2018/Vivado/2018.3/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s Convolution2D -debug wave
call D:/Vitis_2018/Vivado/2018.3/bin/xsim --noieeewarnings Convolution2D -tclbatch Convolution2D.tcl -gui -view Convolution2D_dataflow_ana.wcfg -protoinst Convolution2D.protoinst

