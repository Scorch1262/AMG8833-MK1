/*
 * File:   amg8833.c
 * Author: Torben
 *
 * Created on January 21, 2021, 11:09 AM
 */


#include "xc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "amg8833.h"

#define AMG8833_ADDR            0x69  // 0x68

#define AMG88xx_PCTL            0x00
#define AMG88xx_RST             0x01
#define AMG88xx_FPSC            0x02
#define AMG88xx_INTC            0x03
#define AMG88xx_STAT            0x04
#define AMG88xx_SCLR            0x05
#define AMG88xx_AVE             0x07
#define AMG88xx_INTHL           0x08
#define AMG88xx_INTHH           0x09
#define AMG88xx_INTLL           0x0A
#define AMG88xx_INTLH           0x0B
#define AMG88xx_IHYSL           0x0C
#define AMG88xx_IHYSH           0x0D
#define AMG88xx_TTHL            0x0E
#define AMG88xx_TTHH            0x0F
#define AMG88xx_INT_OFFSET      0x10   //0x010 ???
#define T01L  0x80
#define T01H  0x81

// power_modes
#define AMG88xx_NORMAL_MODE     0x00
#define AMG88xx_SLEEP_MODE      0x01
#define AMG88xx_STAND_BY_60     0x20
#define AMG88xx_STAND_BY_10     0x21

// sw_resets
#define AMG88xx_FLAG_RESET      0x30
#define AMG88xx_INITIAL_RESET   0x3F

// frame_rates
#define AMG88xx_FPS_10          0x00
#define AMG88xx_FPS_1           0x01

// int_enables
#define AMG88xx_INT_DISABLED    0x00
#define AMG88xx_INT_ENABLED     0x01

// int_modes
#define AMG88xx_DIFFERENCE      0x00
#define AMG88xx_ABSOLUTE_VALUE  0x01

float DataMatrix[8][8] = {                                  // definiert "DataMatrix"
    {0,0,0,0,0,0,0,0},                                      // 1
    {0,0,0,0,0,0,0,0},                                      // 2
    {0,0,0,0,0,0,0,0},                                      // 3
    {0,0,0,0,0,0,0,0},                                      // 4
    {0,0,0,0,0,0,0,0},                                      // 5
    {0,0,0,0,0,0,0,0},                                      // 6
    {0,0,0,0,0,0,0,0},                                      // 7
    {0,0,0,0,0,0,0,0},                                      // 8
};                                                          //
float Temp_Data[64];                                        // definiert "Temp_Data"
uint8_t readBuffer[3] = {0x00, 0x00, 0x00};                 // definiert "readBuffer"

void AMG8833_Init(void) {                                               // "AMG8833_Init"
    // Set AMG88 sensor registers
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_PCTL, 0x00);           // Normal mode
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_RST, 0x30);            // Flag reset
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_FPSC, 0x00);           // Frame mode 10FPS
    __delay_ms(100);                                                    // warte 100ms

    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_INTHL, 0x30);          // INTHL
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_INTHH, 0x00);          // INTHH

    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_INTLL, 0x15);          // INTLL
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_INTLH, 0x00);          // INTLH

    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_IHYSL, 0x20);          // IHYSL
    I2C_Write1ByteRegister(AMG8833_ADDR, AMG88xx_IHYSH, 0x00);          // IHYSH
    __delay_ms(100);                                                    // warte 100ms
}                                                                       //

void AMG8833_GetData(void) {                                            // "AMG8833_GetData"
    int pointer = 0;                                                    // definiert "pointer"
    int n = 0;                                                          // definiert "n"
    for(int i=0; i<64; i++){                                            // solange "i" kleiner als 64 ist
        readBuffer[0] = I2C_Read1ByteRegister(AMG8833_ADDR,(T01H + pointer)); // Liest "T01H" aus
        readBuffer[1] = I2C_Read1ByteRegister(AMG8833_ADDR,(T01L + pointer)); // Liest "T01L" aus
        pointer = pointer + 2;                                          // "pointer" + 2
        Temp_Data[i] = Wertdetekt();                                    // "Temp_Data" gleich rueckgabe von "Wertdetekt"
        __delay_ms(1);                                                  // warte 1ms
    }                                                                   //
    for(int x=0; x<8; x++){                                             // solange "x" kleiner als 8 ist
        for(int y=0; y<8; y++){                                         // solange "y" kleiner als 8 ist
            DataMatrix[x][y] = Temp_Data[n];                            // 
            n = n + 1;                                                  // n + 1
        }                                                               // 
    }                                                                   // 
}                                                                       // 

float Wertdetekt(void){                                                 // "Wertdetekt"
    uint16_t tempData;                                                  // definiert "tempData"
    float    tempDataAnz;                                               // definiert "tempDataAnz"
    
    tempData = (readBuffer[0] << 8) + readBuffer[1];                    //       
    tempDataAnz = tempData;                                             // "tempDataAnz" gleich "tempData" 
    tempDataAnz = tempDataAnz * 0.25L;                                  // "tempDataAnz" * 0.25L
    return tempDataAnz;                                                 // gibt "tempDataAnz" zurück    
}                                                                       // 
