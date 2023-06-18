#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdint.h>
typedef enum 
{
    NUMBER,
    OPERATE
}TYPEMATH;

typedef struct 
{
    TYPEMATH key;
    union 
    {
        uint16_t number;
        char operate;
    }value;
    
}TypeMaths;


void stringToDec(char input[], TypeMaths output[]);
int Calculate(TypeMaths output[], uint16_t start, uint16_t end);

#endif
