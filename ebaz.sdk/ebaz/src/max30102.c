/*
 * max30102.c
 *
 *  Created on: 2023年5月22日
 *      Author: slcomplex
 */


#include "max30102.h"

void max30102_i2c_read(u8 uch_addr,u8 *uch_data,u8 data_size){
	u8 send[1];
	send[0]=uch_addr;
	XIicPs_MasterSendPolled(&InstancePtr, send,1, 0x57);
	while (XIicPs_BusIsBusy(&InstancePtr));
	XIicPs_MasterRecvPolled(&InstancePtr, uch_data,data_size, 0x57);
}

void max30102_fifo_read(int *data)
{
    u8 receive_data[6],temp_data;
	do{
		max30102_i2c_read(0x00,&temp_data,1);
		usleep(1000);
	}while((temp_data&0x40)!=0x40);
	max30102_i2c_read(0x07,receive_data,6);		//读出一组两通道数据
	data[0] = ((receive_data[0]<<16 | receive_data[1]<<8 | receive_data[2]) & 0x03ffff);
    data[1] = ((receive_data[3]<<16 | receive_data[4]<<8 | receive_data[5]) & 0x03ffff);

}

float max30102_get(){
	int ac=0,dc=0,ac2=0,dc2=0,i=0,max,min,max2,min2;
	float R;
	for(i=0;i<40;i++){
		int temp[2]={0};
		max30102_fifo_read(temp);
		if(temp[0]+temp[1]<20000)
			break;
		if(i==0){
			max=temp[0];
			min=temp[0];
			max2=temp[1];
			min2=temp[1];
		}
		if(max<temp[0]){
			max=temp[0];
		}
		if(min>temp[0]){
			min=temp[0];
		}
		if(max2<temp[1]){
			max2=temp[1];
		}
		if(min2>temp[1]){
			min2=temp[1];
		}
		if(i==39){//39数据为1周期
			ac=max-min;//单个周期内最大最小数据差为交流分量
			dc=min;		//数据=直流分量+交流分量
			ac2=max2-min2;//同理
			dc2=min2;
		}
	}
	if(i>=39){
		R=(ac2*dc*1.0)/(ac*dc2*1.0);
	return (-45.060*R*R+ 30.354 *R + 94.845);
	}
	return 0;
}

void max30102_i2c_write(u8 uch_addr,u8 uch_data){
	u8 send[2];
	send[0]=uch_addr;
	send[1]=uch_data;
	XIicPs_MasterSendPolled(&InstancePtr, send,2, 0x57);
	while (XIicPs_BusIsBusy(&InstancePtr));
}

void max30102_init(){
	u8 data;
	XIicPs_Config *Config;
	Config = XIicPs_LookupConfig(XPAR_XIICPS_0_DEVICE_ID);
	XIicPs_CfgInitialize(&InstancePtr, Config, Config->BaseAddress);
	XIicPs_SetSClk(&InstancePtr, 100000);
	max30102_i2c_write(0x09,0x40);  	//写模式配置寄存器，置位B6，重启MAX30102
	usleep(50000);							//等待MAX30102完成重启
	max30102_i2c_write(0x02,0xC0);		//使能 新采集数据中断
	max30102_i2c_write(0x03,0x02);  	//使能 内部温度转换完成中断
	max30102_i2c_write(0x04,0x00);		//FIFO 写入指针归零
	max30102_i2c_write(0x05,0x00);		//FIFO 计数器归零
	max30102_i2c_write(0x06,0x00);   	//FIFO 读出指针归零
	max30102_i2c_write(0x08,0x0F); 	//FIFO 8平均采样，不覆盖更新，剩余15个空数据时发布FIFO将满中断
	max30102_i2c_write(0x09,0x03);  	//FIFO 工作在血氧模式，红色红外轮番测量
	max30102_i2c_write(0x0A,0x2B); 	//SpO2 configuration:ACD resolution:15.63pA,sample rate control:100Hz, LED pulse width:215 us
	max30102_i2c_write(0x21,0x01);
	max30102_i2c_write(0x0C,0x2f);	//配置红外电流
	max30102_i2c_write(0x0D,0x2f);	//配置红光电流
	max30102_i2c_read(0x00,&data,1);
	max30102_i2c_read(0x01,&data,1);	//clear the flag
}





