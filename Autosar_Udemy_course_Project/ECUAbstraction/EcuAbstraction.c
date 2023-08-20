

/* Include RTE Application header */
#include "Rte_TempBridgeSWC.h"


/* Code for Runnable - Read Temperature */
void ReadTemperature_Function()
{
	uint16 ADC_Result;
	float PinVoltage, Temperature;
	/* Trigger ADC Conversion and read results */
	Adc_StartGroupConversion(1);
	Adc_ReadGroup(1,&ADC_Result);
	
	/* Convert ADC raw Value to volt*/
	/*10bit ADC with ref-2.5v*/
	PinVoltage = (2.5/1024)*ADC_Result;
	
	/* convert voltage to temperature */
	/* Resp. sensor actuator SWC on Application Layer*/
	/* Sensor -> for 35deg output voltage is 0.35V*/
	
	Temperature = PinVoltage *100;
	
	/*write temperature results to RTE*/
	Rte_write_PP_Temperature(Temperature);
}

/* Code for Runnable - StartMotor (server) */

void StartMotor_Function(uint8 FanSpeed){
	
	if(FanSpeed >50){
		/* Triger cooling fan with half speed*/
		/* H-Bridge settings login to (1,0) */
		Dio_writeChannel(10,STD_HIGH);
		Dio_writeChannel(11,STD_LOW);
	}
	else{
		/* Run fan at full speed */
		
		/* H-Bridge settings logic to (1,1)*/
		Dio_writeChannel(10,STD_HIGH);
		Dio_writeChannel(11,STD_HIGH);
	}
	
}

/* Code for Runnable - Stop Motor*/
void StopMotor_Function()
{
	
	/* H-Bridge settings logic (0,0) */
	Dio_writeChannel(10,STD_LOW);
	Dio_writeChannel(11,STD_LOW);
}