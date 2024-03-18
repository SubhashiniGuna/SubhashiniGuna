#include<LPC21XX.H>
#include"4bit lcd.h"

#define NUMBER "+919488289487" // Define recipient phone number //In atd mode remove +91

// Function prototypes
void UART0_INIT(void);
void UART0_TX(unsigned char);
void UART0_STR(const unsigned char *);
void GSM_SMS(unsigned char *, unsigned char *);
unsigned char UART0_RX(void);

int main() {
    // Initialize UART0
    UART0_INIT();

    // Send SMS
    GSM_SMS(NUMBER, "Welcome to the sibhu World");

    // Infinite loop to prevent the program from exiting
    while (1);
}

// Send SMS using GSM module
void GSM_SMS(unsigned char *num1, unsigned char *msg) {
 delay_milisec(1000); 
    // Send "AT" command to check connection
    UART0_STR("AT\r\n");
    delay_milisec(1000); // Delay to allow GSM module to process command
	
// UART0_STR("ATD");
// while (*num1)
// UART0_TX(*num1++); // Send each character of the phone number
// UART0_TX(';'); // End of phone number
// UART0_STR("\r\n");
// delay_milisec(2000);
	
    // Set SMS text mode
    UART0_STR("AT+CMGF=1\r\n");
    delay_milisec(1000);

    // Send recipient's phone number
 UART0_STR("AT+CMGS=\"");
    while (*num1)
        UART0_TX(*num1++); // Send each character of the phone number
    UART0_STR("\"\r\n"); // End of phone number
    delay_milisec(1000);

    // Send message content
     while (*msg)
         UART0_TX(*msg++); // Send each character of the message
     UART0_TX(0x1A); // End of message transmission (Ctrl+Z)
     delay_milisec(1000);
	
}

// Initialize UART0
void UART0_INIT(void) {
    PINSEL0 = 0x05; // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83; // Set DLAB to access DLL and DLM registers
    U0DLL = 97; // Set baud rate to 9600 (for 15MHz PCLK)
    U0LCR = 0x03; // Clear DLAB to lock baud rate setting
}

// Transmit a character via UART0
void UART0_TX(unsigned char D) {
    while (!(U0LSR & (1 << 5))); // Wait until THR is empty
    U0THR = D; // Transmit the character
}

// Transmit a string via UART0
void UART0_STR(const unsigned char *S) {
    while (*S != '\0') {
        UART0_TX(*S++); // Transmit each character of the string
    }
}
// Receive a character via UART0
unsigned char UART0_RX(void) {
    while (!(U0LSR & (1 << 0))); // Wait until RBR has valid data
    return U0RBR; // Return received character
}

