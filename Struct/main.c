#include<stdio.h>
#include<stdint.h>

typedef struct 
{
    uint8_t ngay;
    uint32_t thang;
    uint16_t nam;
}date;


int main(int argc, char const *argv[])
{
    printf("Size: %d byte", sizeof(date));
    return 0;
}
