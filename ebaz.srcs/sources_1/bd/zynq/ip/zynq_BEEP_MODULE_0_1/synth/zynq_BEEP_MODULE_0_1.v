// (c) Copyright 1995-2023 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:module_ref:BEEP_MODULE:1.0
// IP Revision: 1

(* X_CORE_INFO = "BEEP_MODULE,Vivado 2018.3" *)
(* CHECK_LICENSE_TYPE = "zynq_BEEP_MODULE_0_1,BEEP_MODULE,{}" *)
(* CORE_GENERATION_INFO = "zynq_BEEP_MODULE_0_1,BEEP_MODULE,{x_ipProduct=Vivado 2018.3,x_ipVendor=xilinx.com,x_ipLibrary=module_ref,x_ipName=BEEP_MODULE,x_ipVersion=1.0,x_ipCoreRevision=1,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED,LD0=191130,LRE=170241,LMI=151698,LFA=143183,LSO=127550,LLA=113635,LXI=101234,D0=95546,RE=85134,MI=75837,FA=71581,SO=63775,LA=56817,XI=50617,HD0=47823,HRE=42563,HMI=37921,HFA=35793,HSO=31887,HLA=28408,HXI=25309,NONE=6250000,T125_MS=00010111110101111000010000,T12_5_MS=00000010011000100101101000}" *)
(* IP_DEFINITION_SOURCE = "module_ref" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module zynq_BEEP_MODULE_0_1 (
  clk,
  enable,
  buzzer
);

(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME clk, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN zynq_clk_0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 clk CLK" *)
input wire clk;
input wire enable;
output wire buzzer;

  BEEP_MODULE #(
    .LD0(191130),
    .LRE(170241),
    .LMI(151698),
    .LFA(143183),
    .LSO(127550),
    .LLA(113635),
    .LXI(101234),
    .D0(95546),
    .RE(85134),
    .MI(75837),
    .FA(71581),
    .SO(63775),
    .LA(56817),
    .XI(50617),
    .HD0(47823),
    .HRE(42563),
    .HMI(37921),
    .HFA(35793),
    .HSO(31887),
    .HLA(28408),
    .HXI(25309),
    .NONE(6250000),
    .T125_MS(26'B00010111110101111000010000),
    .T12_5_MS(26'B00000010011000100101101000)
  ) inst (
    .clk(clk),
    .enable(enable),
    .buzzer(buzzer)
  );
endmodule
