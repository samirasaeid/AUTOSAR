
#include "Adc.h"

/* Function to start ADC Conversion*/
void Adc_StartGroupConversion(Adc_GroupType Group)
{
	if(Group == 1)
	{
		/*wrie the code*/
	}
}

/* Function API to read ADC group */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
	unsigned int ADCValue;
	if(Group == 1)
	{
		ADCValue = SomeRegister;
		*DataBufferPtr = ADCValue;
	}
}
