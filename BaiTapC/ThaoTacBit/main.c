#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000100;

void ReadByte(uint8_t byte) {
   for (int i = 0; i < 8; i++) {
      uint8_t bit = (byte >>(7 - i)) & 1;
      printf("%d", bit);
   }
   printf("\n");
}

typedef enum{
   PIN0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7
}pins;

typedef enum{
   LOW,
   HIGH
}digital;

void PinHigh(pins pin){
   PORTA = PORTA | ( 1 << 7 - pin );

}
void PinLow(pins pin){
   PORTA = PORTA & ~( 1 << 7 - pin );
}

void DigitalWrite(pins pin, digital result){
   switch (result) {
        case LOW:
            PinLow(pin);
            break;
        case HIGH:
            PinHigh(pin);
            break;
        default:
            printf("ERROR\n");
            break;
    }
}


int main() {
   uint8_t a =9;
   
   
   // DigitalWrite(PIN5, LOW);
   // DigitalWrite(PIN5, HIGH);
   // DigitalWrite(PIN5, LOW);
   // DigitalWrite(PIN5, HIGH);
   // DigitalWrite(PIN5, LOW);
   // printf("0b");
   //ReadByte(PORTA);
ReadByte(a);
   return 0;
}

