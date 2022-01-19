/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "amg8833.h"

extern float DataMatrix[8][8];                                                  // definiert "DataMatrix" 
extern float Temp_Data[64];                                                     // definiert "Temp_Data"

/*
                         Main application
 */
void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    AMG8833_Init();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1){                                                      // Endlosschleife
        AMG8833_GetData();                                          // 
        /*
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[0],Temp_Data[1],Temp_Data[2],Temp_Data[3],Temp_Data[4],Temp_Data[5],Temp_Data[6],Temp_Data[7]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[8],Temp_Data[9],Temp_Data[10],Temp_Data[11],Temp_Data[12],Temp_Data[13],Temp_Data[14],Temp_Data[15]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[16],Temp_Data[17],Temp_Data[18],Temp_Data[19],Temp_Data[20],Temp_Data[21],Temp_Data[22],Temp_Data[23]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[24],Temp_Data[25],Temp_Data[26],Temp_Data[27],Temp_Data[28],Temp_Data[29],Temp_Data[30],Temp_Data[31]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[32],Temp_Data[33],Temp_Data[34],Temp_Data[35],Temp_Data[36],Temp_Data[37],Temp_Data[38],Temp_Data[39]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[40],Temp_Data[41],Temp_Data[42],Temp_Data[43],Temp_Data[44],Temp_Data[45],Temp_Data[46],Temp_Data[47]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[48],Temp_Data[49],Temp_Data[50],Temp_Data[51],Temp_Data[52],Temp_Data[53],Temp_Data[54],Temp_Data[55]);
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",Temp_Data[56],Temp_Data[57],Temp_Data[58],Temp_Data[59],Temp_Data[60],Temp_Data[61],Temp_Data[62],Temp_Data[63]);
        printf("\r\n");                                            // schreibt "Enter" an UART
        printf("\r\n");                                            // schreibt "Enter" an UART
        printf("\r\n");                                            // schreibt "Enter" an UART
        */
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[0][0],DataMatrix[0][1],DataMatrix[0][2],DataMatrix[0][3],DataMatrix[0][4],DataMatrix[0][5],DataMatrix[0][6],DataMatrix[0][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[1][0],DataMatrix[1][1],DataMatrix[1][2],DataMatrix[1][3],DataMatrix[1][4],DataMatrix[1][5],DataMatrix[1][6],DataMatrix[1][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[2][0],DataMatrix[2][1],DataMatrix[2][2],DataMatrix[2][3],DataMatrix[2][4],DataMatrix[2][5],DataMatrix[2][6],DataMatrix[2][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[3][0],DataMatrix[3][1],DataMatrix[3][2],DataMatrix[3][3],DataMatrix[3][4],DataMatrix[3][5],DataMatrix[3][6],DataMatrix[3][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[4][0],DataMatrix[4][1],DataMatrix[4][2],DataMatrix[4][3],DataMatrix[4][4],DataMatrix[4][5],DataMatrix[4][6],DataMatrix[4][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[5][0],DataMatrix[5][1],DataMatrix[5][2],DataMatrix[5][3],DataMatrix[5][4],DataMatrix[5][5],DataMatrix[5][6],DataMatrix[5][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[6][0],DataMatrix[6][1],DataMatrix[6][2],DataMatrix[6][3],DataMatrix[6][4],DataMatrix[6][5],DataMatrix[6][6],DataMatrix[6][7]);// schreibt "" an UART
        //printf("\r\n");                                            // schreibt "Enter" an UART
        printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\r\n",DataMatrix[7][0],DataMatrix[7][1],DataMatrix[7][2],DataMatrix[7][3],DataMatrix[7][4],DataMatrix[7][5],DataMatrix[7][6],DataMatrix[7][7]);// schreibt "" an UART
        printf("\r\n");                                            // schreibt "Enter" an UART
        printf("\r\n");                                            // schreibt "Enter" an UART
        printf("\r\n");                                            // schreibt "Enter" an UART
        __delay_ms(1000);
    }                                                               // 
}                                                                   // 
/**
 End of File
*/