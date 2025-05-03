set_param project.enableReportConfiguration 0
load_feature core
current_fileset
xsim {Convolution2D} -view {{Convolution2D_dataflow_ana.wcfg}} -tclbatch {Convolution2D.tcl} -protoinst {Convolution2D.protoinst}
