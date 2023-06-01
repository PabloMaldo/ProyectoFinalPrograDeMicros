/*
 * File:   main5.c
 * Author: pablo
 *
 * Created on June 1, 2023, 10:06 AM
 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// LIBRERIAS
#include <xc.h>
#include <stdint.h>

// VARIABLES GLOBALES
//int adc_value_3;
int contador;

// CONSTANTES
#define _XTAL_FREQ 8000000

// PROTOTIPOS DE FUNCION
void setup(void);
int map(int input, int inMin, int inMax, int outMin, int outMax);

// INTERRUPCIONES
//void __interrupt() isr (void)
//{
//    if (INTCONbits.T0IF) // Interrupcion del TMR0
//    {
//        contador++;
//        if (contador < adc_value_3 ) // cuando el valor del contador sea menor al de la conv del pot, enciende LED
//            PORTCbits.RC3 = 1;
//        else
//            PORTCbits.RC3 = 0;
//        TMR0 = 6;
//        INTCONbits.T0IF = 0;
//    }
//}

void main(void) {
    setup();
    
    while(1){
        ADCON0bits.CHS = 0; // SELECCIONANDO EL CANAL 0
        ADCON0bits.GO = 1; // INICIANDO LA CONVERSION
        while(ADCON0bits.GO); // Esperar a que termine la conversión
        int adc_value_1 = ADRESH; // Leer el valor convertido
        int servo1 =  map(adc_value_1, 0, 255, 125, 250);
        CCPR1L = (unsigned char)servo1;
        __delay_ms(10);
        
        ADCON0bits.CHS = 1; // SELECCIONANDO EL CANAL 0
        ADCON0bits.GO = 1; // INICIANDO LA CONVERSION
        while(ADCON0bits.GO); // Esperar a que termine la conversión
        int adc_value_2 = ADRESH; // Leer el valor convertido
        int servo2 =  map(adc_value_2, 0, 255, 125, 250);
        CCPR2L = (unsigned char)servo2;
        __delay_ms(10);
        
        ADCON0bits.CHS = 2; // SELECCIONANDO EL CANAL 0
        ADCON0bits.GO = 1; // INICIANDO LA CONVERSION
        while(ADCON0bits.GO); // Esperar a que termine la conversión
        int adc_value_3 = ADRESH; // Leer el valor convertido
        int servo3 =  map(adc_value_3, 0, 205, 0, 180);
        PORTB = servo3;
        switch (servo3) {
        case 0:
            PORTCbits.RC3 = 1;
            __delay_us(1000);
            PORTCbits.RC3 = 0;
            break;
        case 10:
            PORTCbits.RC3 = 1;
            __delay_us(1055);
            PORTCbits.RC3 = 0;
            break;
        case 20:
            PORTCbits.RC3 = 1;
            __delay_us(1111);
            PORTCbits.RC3 = 0;
            break;
        case 30:
            PORTCbits.RC3 = 1;
            __delay_us(1166);
            PORTCbits.RC3 = 0;
            break;
        case 40:
            PORTCbits.RC3 = 1;
            __delay_us(1222);
            PORTCbits.RC3 = 0;
            break;
        case 50:
            PORTCbits.RC3 = 1;
            __delay_us(1277);
            PORTCbits.RC3 = 0;
            break;
        case 60:
            PORTCbits.RC3 = 1;
            __delay_us(1333);
            PORTCbits.RC3 = 0;
            break;
        case 70:
            PORTCbits.RC3 = 1;
            __delay_us(1388);
            PORTCbits.RC3 = 0;
            break;
        case 80:
            PORTCbits.RC3 = 1;
            __delay_us(1444);
            PORTCbits.RC3 = 0;
            break;
        case 90:
            PORTCbits.RC3 = 1;
            __delay_us(1500);
            PORTCbits.RC3 = 0;
            break;
        case 100:
            PORTCbits.RC3 = 1;
            __delay_us(1555);
            PORTCbits.RC3 = 0;
            break;
        case 110:
            PORTCbits.RC3 = 1;
            __delay_us(1611);
            PORTCbits.RC3 = 0;
            break;
        case 120:
            PORTCbits.RC3 = 1;
            __delay_us(1666);
            PORTCbits.RC3 = 0;
            break;
        case 130:
            PORTCbits.RC3 = 1;
            __delay_us(1722);
            PORTCbits.RC3 = 0;
            break;
        case 140:
            PORTCbits.RC3 = 1;
            __delay_us(1777);
            PORTCbits.RC3 = 0;
            break;
        case 150:
            PORTCbits.RC3 = 1;
            __delay_us(1833);
            PORTCbits.RC3 = 0;
            break;
        case 160:
            PORTCbits.RC3 = 1;
            __delay_us(1888);
            PORTCbits.RC3 = 0;
            break;
        case 170:
            PORTCbits.RC3 = 1;
            __delay_us(1944);
            PORTCbits.RC3 = 0;
            break;
        case 180:
            PORTCbits.RC3 = 1;
            __delay_us(2000);
            PORTCbits.RC3 = 0;
            break;
        default:
            // Manejar caso no válido (opcional)
            break;
        }
        ADCON0bits.CHS = 4; // SELECCIONANDO EL CANAL 0
        ADCON0bits.GO = 1; // INICIANDO LA CONVERSION
        while(ADCON0bits.GO); // Esperar a que termine la conversión
        int adc_value_4 = ADRESH; // Leer el valor convertido
        int servo4 =  map(adc_value_4, 0, 205, 0, 180);
        PORTB = servo4;
        switch (servo4) {
        case 0:
            PORTCbits.RC4 = 1;
            __delay_us(1000);
            PORTCbits.RC4 = 0;
            break;
        case 10:
            PORTCbits.RC4 = 1;
            __delay_us(1055);
            PORTCbits.RC4 = 0;
            break;
        case 20:
            PORTCbits.RC4 = 1;
            __delay_us(1111);
            PORTCbits.RC4 = 0;
            break;
        case 30:
            PORTCbits.RC4 = 1;
            __delay_us(1166);
            PORTCbits.RC4 = 0;
            break;
        case 40:
            PORTCbits.RC4 = 1;
            __delay_us(1222);
            PORTCbits.RC4 = 0;
            break;
        case 50:
            PORTCbits.RC4 = 1;
            __delay_us(1277);
            PORTCbits.RC4 = 0;
            break;
        case 60:
            PORTCbits.RC4 = 1;
            __delay_us(1333);
            PORTCbits.RC4 = 0;
            break;
        case 70:
            PORTCbits.RC4 = 1;
            __delay_us(1388);
            PORTCbits.RC4 = 0;
            break;
        case 80:
            PORTCbits.RC4 = 1;
            __delay_us(1444);
            PORTCbits.RC4 = 0;
            break;
        case 90:
            PORTCbits.RC4 = 1;
            __delay_us(1500);
            PORTCbits.RC4 = 0;
            break;
        case 100:
            PORTCbits.RC4 = 1;
            __delay_us(1555);
            PORTCbits.RC4 = 0;
            break;
        case 110:
            PORTCbits.RC4 = 1;
            __delay_us(1611);
            PORTCbits.RC4 = 0;
            break;
        case 120:
            PORTCbits.RC4 = 1;
            __delay_us(1666);
            PORTCbits.RC4 = 0;
            break;
        case 130:
            PORTCbits.RC4 = 1;
            __delay_us(1722);
            PORTCbits.RC4 = 0;
            break;
        case 140:
            PORTCbits.RC4 = 1;
            __delay_us(1777);
            PORTCbits.RC4 = 0;
            break;
        case 150:
            PORTCbits.RC4 = 1;
            __delay_us(1833);
            PORTCbits.RC4 = 0;
            break;
        case 160:
            PORTCbits.RC4 = 1;
            __delay_us(1888);
            PORTCbits.RC4 = 0;
            break;
        case 170:
            PORTCbits.RC4 = 1;
            __delay_us(1944);
            PORTCbits.RC4 = 0;
            break;
        case 180:
            PORTCbits.RC4 = 1;
            __delay_us(2000);
            PORTCbits.RC4 = 0;
            break;
        default:
            // Manejar caso no válido (opcional)
            break;
        }   


    }
    return;
}

void setup(void){
    // CONFIGURACION DE ENTRADAS Y SALIDAS
    // Pines digitales
    ANSEL = 0;
    ANSELH = 0;
    // Puerto C como salida
    TRISCbits.TRISC3 = 0;
    TRISB = 0;
    PORTB = 0;
    
    // Configuracion oscilador interno
    OSCCONbits.IRCF = 0b111; // 8MHz
    OSCCONbits.SCS = 1;
    
    // Configuracion del TMR0
    OPTION_REGbits.T0CS = 0;    // Temporizador
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b111; // prescaler 1:4
    TMR0 = 100;
    
    //Configuracion de las interrupciones
    INTCONbits.T0IF = 0; // Bandera tmr0
    INTCONbits.T0IE = 1; // Enable tmr0
    INTCONbits.PEIE = 1; // Interrupciones perifericas
    INTCONbits.GIE = 1; // Interrupciones globales
    
    // Configuracion ADC
    ANSELbits.ANS0 = 1;     // CANAL 0
    ANSELbits.ANS1 = 1;     // CANAL 1
    ANSELbits.ANS2 = 1;     // CANAL 2
    ANSELbits.ANS3 = 1;
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    ADCON0bits.ADCS = 0b10; // FOSC/32
    __delay_ms(1);
    ADCON1bits.ADFM = 0; //Justificado a la izquierda
    ADCON1bits.VCFG0 = 0; //Voltaje de ref. a GND
    ADCON1bits.VCFG1 = 0; //Voltaje de ref. a 5v
    ADCON0bits.ADON = 1; // ADC is enabled
    ADIF = 0;
    
    // Configuracion PWM
    // PASO 1
    TRISCbits.TRISC2 = 1;   //RC2/CCP1 como entrada
    TRISCbits.TRISC1 = 1;   //RC1/CCP2 como entrada
    // PASO 2
    PR2 = 250;              // Periodo del tmr2 (2ms)
    // PASO 3
    CCP1CONbits.P1M = 0;    // mode single output (P1A modulated; P1B, P1C, P1D assigned as port pins) CCP1
    CCP1CONbits.CCP1M = 0b00001100;    // Modo PWM CCP1
    CCP2CONbits.CCP2M = 0b00001100;    // Modo PWM CCP2
    // PASO 4
    CCPR1L = 0x0f;          // Duty cycle inicial CCP1
    CCPR2L = 0x0f;          // Duty cycle inicial CCP2
    CCP1CONbits.DC1B1 = 0;  // bits menos significativos CCP1
    CCP1CONbits.DC1B0 = 0;  // bits menos singificativos CCP1
    CCP2CONbits.DC2B1 = 0;  // bits menos singificativos CCP2
    CCP2CONbits.DC2B0 = 0;  // bits menos singificativos CCP2
    // PASO 5  
    PIR1bits.TMR2IF = 0;    
    T2CONbits.T2CKPS = 0b11;    // Prescaler 1:16
    T2CONbits.TMR2ON = 1;       // Prender TMR2
    // PASO 6
    while (!PIR1bits.TMR2IF);   // esperar un ciclo
    PIR1bits.TMR2IF = 0;
    
    TRISCbits.TRISC2 = 0;       // Habilitar salida CCP1
    TRISCbits.TRISC1 = 0;       // Habilitar salida CCP2
    return;
}

// FUNCIONES
int map(int input, int inMin, int inMax, int outMin, int outMax) {
    return (input - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}
