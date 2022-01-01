/*
 * File:   main.c
 */
#include <xc.h>
 
// PIC12F1822 Configuration Bit Settings
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)
 
 
// クロック周波数指定
// __delay_ms()関数が使用する
#define _XTAL_FREQ 1000000
 
void main(void) {
    
 
    // PICマイコン設定
    OSCCON = 0b01011010;  // 内部クロック周波数を1MHzに設定
    ANSELA = 0b00000000;  // すべてのピンをデジタルモードに設定
    TRISA  = 0b00001000;  // すべてのピンを出力モードに設定(ただしRA3ピンは常に入力モード)
 
    LATA5 = 0;
     
    while(1){
        // LEDを950ms消灯する
        LATA5 = 0;
        __delay_ms(950);            
        // LEDを50ms点灯する
        LATA5 = 1;
        __delay_ms(950);
    }
 
    return;
 
}