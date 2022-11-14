/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Moaz Mohamed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*Definition to determine the working mode of the ADC (interrupt/polling)*/
#define ADC_INTERRUPT_ENABLED 0

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*This enum contains the possible reference voltage for the ADC*/
typedef enum {
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;

/*This enum contains prescaler options for the ADC*/
typedef enum {
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

/*This structure contains required initialization for the ADC module, the reference voltage,
 * and the frequency prescaler
 */
typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * This function is responsible for initializing the ADC module with the
 * required reference voltage and prescaler for the operating frequency.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

#if ADC_INTERRUPT_ENABLED == 0

/*
 * Description :
 * This function is responsible for the digital value the ADC produced after
 * conversion completion on the specified channel.
 */
uint16 ADC_readChannel(uint8 channelNum);

#elif ADC_INTERRUPT_ENABLED == 1

/*
 * Description :
 * This function is responsible for prompting the ADC to start the conversion on
 * the specified channel, when using the ADC in interrupt mode.
 */
void ADC_startConversion(uint8 channelNum);

#endif

#endif /* ADC_H_ */
