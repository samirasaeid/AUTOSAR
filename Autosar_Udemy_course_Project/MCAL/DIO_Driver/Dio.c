
/* MCAL Layer for DIO Driver */
#include "Dio.h"


/* Function API to Read a Channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	unsigned int ReadVal;
	/*Assume Channel 10 is mapped to Port P2.0*/
	if(ChannelId == 10){
		ReadVal = P2IN & BIT0;
		
		if(ReadVal == 0x00)/*If pin is low*/
		{
			return STD_LOW;
		}
		else{
			/*if pin is high*/
			return STD_HIGH;
		}
	}
	/*continue for the other channels*/
}

/* Function to write a channel */
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	if(ChannelId == 10)
	{
		if(Level == STD_LOW)
		{
			P2OUT &=~BIT0; /*Set Pin Low*/
		}
		else{
			P2OUT != BIT0; /*Set Pin High*/
		}
	}
	/* continue with other channels */
}