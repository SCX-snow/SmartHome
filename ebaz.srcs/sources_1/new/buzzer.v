module BEEP_MODULE(
    input clk,//50m 波形
    input enable,
    output reg buzzer
);
parameter LD0=191130;
parameter LRE=170241;
parameter LMI=151698;
parameter LFA=143183;
parameter LSO=127550;
parameter LLA=113635;
parameter LXI=101234;
parameter D0=95546;
parameter RE=85134;
parameter MI=75837;
parameter FA=71581;
parameter SO=63775;
parameter LA=56817;
parameter XI=50617;
parameter HD0=47823;
parameter HRE=42563;
parameter HMI=37921;
parameter HFA=35793;
parameter HSO=31887;
parameter HLA=28408;
parameter HXI=25309;
parameter NONE=6250000;

//PWM 发声模块，用来产生特定的PWM波形
reg [16:0]beep_pwm_count;
reg [16:0]beep_pwm;
always@(posedge clk)
    if(enable)begin
    if(beep_pwm_count>=beep_pwm)begin
        beep_pwm_count<=17'd0;
        buzzer<=~buzzer;
     end
    else beep_pwm_count<=beep_pwm_count+1'b1;
    end

reg [3:0]voice_mode = 0; 
parameter T125_MS = 26'd6_250_000 ;
parameter T12_5_MS = 26'd625_000 ; 
reg [24:0]T = T125_MS;
reg [24:0]time_count;//


//初始化寄存器用
initial begin
    voice_mode<=3'd0;
    time_count<=25'd0;
end

//0.5秒定时器，每0.5秒改变一次声调，通过voice_mode来调整音调
 always@(posedge clk)
     if(time_count>=T)begin
         time_count<=25'd0;
         if(voice_mode>=4'd15)voice_mode<=3'd0;
         else voice_mode<=voice_mode+3'd1;
     end
     else time_count<=time_count+1'b1;
 
 //将当前voice_mode对应的音调值赋给 beep_pwm寄存器    
 //向右移动一位的作用是，预设值是实际波长的一半
 always@(posedge clk)
    case(voice_mode)
        5'd0:begin
            beep_pwm<=MI>>1;
            T=2*T125_MS;
            end
        5'd1:begin
            beep_pwm<=NONE>>1;
            T=2*T12_5_MS;
            end
        5'd2:begin
            beep_pwm<=MI>>1;
            T=2*T125_MS;
            end
        5'd3:begin
            beep_pwm<=NONE>>1;
            T=4*T12_5_MS;
            end
        5'd4:begin
            beep_pwm<=MI>>1;
            T=2*T125_MS;
            end 
        5'd5:begin
            beep_pwm<=NONE>>1;
            T=2*T12_5_MS;
            end 
        5'd6:begin
            beep_pwm<=D0>>1;
            T=T125_MS;
            end
        5'd7:begin
            beep_pwm<=NONE>>1;
            T=T12_5_MS;
            end  
        5'd8:begin
            beep_pwm<=MI>>1;
            T=T125_MS;
            end 
        5'd9:begin
            beep_pwm<=NONE>>1;
            T=4*T12_5_MS;
            end  
        5'd10:begin
            beep_pwm<=NONE>>1;
            T=2*T125_MS;
            end   
        5'd11:begin
            beep_pwm<=SO>>1;
            T=2*T125_MS;
            end 
        5'd12:begin
            beep_pwm<=NONE>>1;
            T=4*T12_5_MS;
            end 
        5'd13:begin
            beep_pwm<=NONE>>1;
            T=2*T125_MS;
            end 
        5'd14:begin
            beep_pwm<=SO>>1;
            T=2*T125_MS;
            end 
        5'd15:begin
            beep_pwm<=NONE>>1;
            T=4*T12_5_MS+2*T125_MS;
            end 
    endcase

endmodule