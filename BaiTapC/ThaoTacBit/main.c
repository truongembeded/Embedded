#include <stdio.h>
#include <stdint.h>

void ReadByte(uint8_t byte) {
   for (int i = 0; i < 8; i++) {
      uint8_t bit = (byte >>(7 - i)) & 1;
      printf("%d", bit);
   }
   printf("\n");
}

int main() {
   uint8_t a = 0b01000100;
   printf("0b");
   ReadByte(a);
   return 0;
}

