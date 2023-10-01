# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "D0" -parent ${Page_0}
  ipgui::add_param $IPINST -name "FA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HD0" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HFA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HLA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HMI" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HRE" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HSO" -parent ${Page_0}
  ipgui::add_param $IPINST -name "HXI" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LD0" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LFA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LLA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LMI" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LRE" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LSO" -parent ${Page_0}
  ipgui::add_param $IPINST -name "LXI" -parent ${Page_0}
  ipgui::add_param $IPINST -name "MI" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NONE" -parent ${Page_0}
  ipgui::add_param $IPINST -name "RE" -parent ${Page_0}
  ipgui::add_param $IPINST -name "SO" -parent ${Page_0}
  ipgui::add_param $IPINST -name "T125_MS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "T12_5_MS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "XI" -parent ${Page_0}


}

proc update_PARAM_VALUE.D0 { PARAM_VALUE.D0 } {
	# Procedure called to update D0 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.D0 { PARAM_VALUE.D0 } {
	# Procedure called to validate D0
	return true
}

proc update_PARAM_VALUE.FA { PARAM_VALUE.FA } {
	# Procedure called to update FA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.FA { PARAM_VALUE.FA } {
	# Procedure called to validate FA
	return true
}

proc update_PARAM_VALUE.HD0 { PARAM_VALUE.HD0 } {
	# Procedure called to update HD0 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HD0 { PARAM_VALUE.HD0 } {
	# Procedure called to validate HD0
	return true
}

proc update_PARAM_VALUE.HFA { PARAM_VALUE.HFA } {
	# Procedure called to update HFA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HFA { PARAM_VALUE.HFA } {
	# Procedure called to validate HFA
	return true
}

proc update_PARAM_VALUE.HLA { PARAM_VALUE.HLA } {
	# Procedure called to update HLA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HLA { PARAM_VALUE.HLA } {
	# Procedure called to validate HLA
	return true
}

proc update_PARAM_VALUE.HMI { PARAM_VALUE.HMI } {
	# Procedure called to update HMI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HMI { PARAM_VALUE.HMI } {
	# Procedure called to validate HMI
	return true
}

proc update_PARAM_VALUE.HRE { PARAM_VALUE.HRE } {
	# Procedure called to update HRE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HRE { PARAM_VALUE.HRE } {
	# Procedure called to validate HRE
	return true
}

proc update_PARAM_VALUE.HSO { PARAM_VALUE.HSO } {
	# Procedure called to update HSO when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HSO { PARAM_VALUE.HSO } {
	# Procedure called to validate HSO
	return true
}

proc update_PARAM_VALUE.HXI { PARAM_VALUE.HXI } {
	# Procedure called to update HXI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HXI { PARAM_VALUE.HXI } {
	# Procedure called to validate HXI
	return true
}

proc update_PARAM_VALUE.LA { PARAM_VALUE.LA } {
	# Procedure called to update LA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LA { PARAM_VALUE.LA } {
	# Procedure called to validate LA
	return true
}

proc update_PARAM_VALUE.LD0 { PARAM_VALUE.LD0 } {
	# Procedure called to update LD0 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LD0 { PARAM_VALUE.LD0 } {
	# Procedure called to validate LD0
	return true
}

proc update_PARAM_VALUE.LFA { PARAM_VALUE.LFA } {
	# Procedure called to update LFA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LFA { PARAM_VALUE.LFA } {
	# Procedure called to validate LFA
	return true
}

proc update_PARAM_VALUE.LLA { PARAM_VALUE.LLA } {
	# Procedure called to update LLA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LLA { PARAM_VALUE.LLA } {
	# Procedure called to validate LLA
	return true
}

proc update_PARAM_VALUE.LMI { PARAM_VALUE.LMI } {
	# Procedure called to update LMI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LMI { PARAM_VALUE.LMI } {
	# Procedure called to validate LMI
	return true
}

proc update_PARAM_VALUE.LRE { PARAM_VALUE.LRE } {
	# Procedure called to update LRE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LRE { PARAM_VALUE.LRE } {
	# Procedure called to validate LRE
	return true
}

proc update_PARAM_VALUE.LSO { PARAM_VALUE.LSO } {
	# Procedure called to update LSO when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LSO { PARAM_VALUE.LSO } {
	# Procedure called to validate LSO
	return true
}

proc update_PARAM_VALUE.LXI { PARAM_VALUE.LXI } {
	# Procedure called to update LXI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.LXI { PARAM_VALUE.LXI } {
	# Procedure called to validate LXI
	return true
}

proc update_PARAM_VALUE.MI { PARAM_VALUE.MI } {
	# Procedure called to update MI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.MI { PARAM_VALUE.MI } {
	# Procedure called to validate MI
	return true
}

proc update_PARAM_VALUE.NONE { PARAM_VALUE.NONE } {
	# Procedure called to update NONE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NONE { PARAM_VALUE.NONE } {
	# Procedure called to validate NONE
	return true
}

proc update_PARAM_VALUE.RE { PARAM_VALUE.RE } {
	# Procedure called to update RE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.RE { PARAM_VALUE.RE } {
	# Procedure called to validate RE
	return true
}

proc update_PARAM_VALUE.SO { PARAM_VALUE.SO } {
	# Procedure called to update SO when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.SO { PARAM_VALUE.SO } {
	# Procedure called to validate SO
	return true
}

proc update_PARAM_VALUE.T125_MS { PARAM_VALUE.T125_MS } {
	# Procedure called to update T125_MS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.T125_MS { PARAM_VALUE.T125_MS } {
	# Procedure called to validate T125_MS
	return true
}

proc update_PARAM_VALUE.T12_5_MS { PARAM_VALUE.T12_5_MS } {
	# Procedure called to update T12_5_MS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.T12_5_MS { PARAM_VALUE.T12_5_MS } {
	# Procedure called to validate T12_5_MS
	return true
}

proc update_PARAM_VALUE.XI { PARAM_VALUE.XI } {
	# Procedure called to update XI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.XI { PARAM_VALUE.XI } {
	# Procedure called to validate XI
	return true
}


proc update_MODELPARAM_VALUE.LD0 { MODELPARAM_VALUE.LD0 PARAM_VALUE.LD0 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LD0}] ${MODELPARAM_VALUE.LD0}
}

proc update_MODELPARAM_VALUE.LRE { MODELPARAM_VALUE.LRE PARAM_VALUE.LRE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LRE}] ${MODELPARAM_VALUE.LRE}
}

proc update_MODELPARAM_VALUE.LMI { MODELPARAM_VALUE.LMI PARAM_VALUE.LMI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LMI}] ${MODELPARAM_VALUE.LMI}
}

proc update_MODELPARAM_VALUE.LFA { MODELPARAM_VALUE.LFA PARAM_VALUE.LFA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LFA}] ${MODELPARAM_VALUE.LFA}
}

proc update_MODELPARAM_VALUE.LSO { MODELPARAM_VALUE.LSO PARAM_VALUE.LSO } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LSO}] ${MODELPARAM_VALUE.LSO}
}

proc update_MODELPARAM_VALUE.LLA { MODELPARAM_VALUE.LLA PARAM_VALUE.LLA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LLA}] ${MODELPARAM_VALUE.LLA}
}

proc update_MODELPARAM_VALUE.LXI { MODELPARAM_VALUE.LXI PARAM_VALUE.LXI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LXI}] ${MODELPARAM_VALUE.LXI}
}

proc update_MODELPARAM_VALUE.D0 { MODELPARAM_VALUE.D0 PARAM_VALUE.D0 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.D0}] ${MODELPARAM_VALUE.D0}
}

proc update_MODELPARAM_VALUE.RE { MODELPARAM_VALUE.RE PARAM_VALUE.RE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.RE}] ${MODELPARAM_VALUE.RE}
}

proc update_MODELPARAM_VALUE.MI { MODELPARAM_VALUE.MI PARAM_VALUE.MI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.MI}] ${MODELPARAM_VALUE.MI}
}

proc update_MODELPARAM_VALUE.FA { MODELPARAM_VALUE.FA PARAM_VALUE.FA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.FA}] ${MODELPARAM_VALUE.FA}
}

proc update_MODELPARAM_VALUE.SO { MODELPARAM_VALUE.SO PARAM_VALUE.SO } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.SO}] ${MODELPARAM_VALUE.SO}
}

proc update_MODELPARAM_VALUE.LA { MODELPARAM_VALUE.LA PARAM_VALUE.LA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.LA}] ${MODELPARAM_VALUE.LA}
}

proc update_MODELPARAM_VALUE.XI { MODELPARAM_VALUE.XI PARAM_VALUE.XI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.XI}] ${MODELPARAM_VALUE.XI}
}

proc update_MODELPARAM_VALUE.HD0 { MODELPARAM_VALUE.HD0 PARAM_VALUE.HD0 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HD0}] ${MODELPARAM_VALUE.HD0}
}

proc update_MODELPARAM_VALUE.HRE { MODELPARAM_VALUE.HRE PARAM_VALUE.HRE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HRE}] ${MODELPARAM_VALUE.HRE}
}

proc update_MODELPARAM_VALUE.HMI { MODELPARAM_VALUE.HMI PARAM_VALUE.HMI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HMI}] ${MODELPARAM_VALUE.HMI}
}

proc update_MODELPARAM_VALUE.HFA { MODELPARAM_VALUE.HFA PARAM_VALUE.HFA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HFA}] ${MODELPARAM_VALUE.HFA}
}

proc update_MODELPARAM_VALUE.HSO { MODELPARAM_VALUE.HSO PARAM_VALUE.HSO } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HSO}] ${MODELPARAM_VALUE.HSO}
}

proc update_MODELPARAM_VALUE.HLA { MODELPARAM_VALUE.HLA PARAM_VALUE.HLA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HLA}] ${MODELPARAM_VALUE.HLA}
}

proc update_MODELPARAM_VALUE.HXI { MODELPARAM_VALUE.HXI PARAM_VALUE.HXI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HXI}] ${MODELPARAM_VALUE.HXI}
}

proc update_MODELPARAM_VALUE.NONE { MODELPARAM_VALUE.NONE PARAM_VALUE.NONE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NONE}] ${MODELPARAM_VALUE.NONE}
}

proc update_MODELPARAM_VALUE.T125_MS { MODELPARAM_VALUE.T125_MS PARAM_VALUE.T125_MS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.T125_MS}] ${MODELPARAM_VALUE.T125_MS}
}

proc update_MODELPARAM_VALUE.T12_5_MS { MODELPARAM_VALUE.T12_5_MS PARAM_VALUE.T12_5_MS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.T12_5_MS}] ${MODELPARAM_VALUE.T12_5_MS}
}

