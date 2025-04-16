#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include "mcc_generated_files/spi/mssp2.h"

/*
    Main application
*/


uint8_t spiBuffer[8];

void send_message(){
       spiBuffer[0] = 0;
       spiBuffer[1] = 0;
       spiBuffer[2] = 1;
       spiBuffer[3] = 1;
       spiBuffer[4] = 1;
       spiBuffer[5] = 1;
       spiBuffer[6] = 1;
       spiBuffer[7] = 0;
               
               SPI1_BufferWrite(spiBuffer,7);
               _delay(300);
        }

int main(void)
{
    SYSTEM_Initialize();
    SPI1_Initialize();
    SPI1_Open(HOST_CONFIG);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    IO_RB3_SetHigh();
    
    IO_RB5_SetInterruptHandler(send_Message);
    
    while(1)
    {
       
        IO_RB3_SetLow(); 
        IO_RB1_SetHigh();
        _delay(300);
        send_message();
        
       
    }    
}