#include<stdio.h>
#include<stdint.h>
#include"main.h"

void stringToDec(char input[], TypeMaths output[]){
    uint16_t number = 0;
    uint8_t i = 0;
    while (*input != '\0')
    {
        
        if (*input >= '0' && *input <= '9')
        {
            uint8_t temp = *input - '0';
            number = 10*number + temp;
            input++;
            continue;
        }else if(*input == '+' || *input == '-' || *input == '*' || *input == '/'){
            output[i].key = OPERATE;
            output[i].value.operator = *input;
            i++;
            input++;
            continue;
        }else
        {
            if (number != 0)
            {
                output[i].key = NUMBER;
                output[i].value.number = number;
                number = 0;
                i++;
            }
            
        }
       input++;
    }
    output[i].key = NUMBER;
    output[i].value.number = number;

    output[i + 1].key = NUMBER;
    output[i + 1].value.number = 0;
}

int Calculate(TypeMaths output[], uint16_t start, uint16_t end) {
    uint16_t i = start;
    uint32_t result = 0;
    uint16_t left , right;
    char calculate;
    while (start <= end)
    {
        if (output[i].key == OPERATE && output[i].value.operator == '*' || output[i].value.operator == '/')
        {
            char calculate = output[i].value.operator;
            left = output[i - 1].value.number;
            right = output[i + 1].value.number;

            if (calculate == '*')
            {
                result = left * right;
            }
            else if (calculate == '/')
            {
                result = left / right;
            }
            output[i].key = NUMBER;
            output[i].value.number = result;
            for (int j = i - 1; j < end - 2; j++)
            {
                output[j] = output[j + 2];
                end -= 2;
            }
            
        }else
        {
            i++;
        }
    }
// xử lý phép + -
    result = output[start].value.number;
    for ( i = start; i <= end; i+= 2)
    {
        calculate = output[i].value.operator;
        right = output[i + 1].value.number;
        if (calculate == '+')
        {
            result += right;
        }else if(calculate == '-'){
            result -= right;
        }  
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    char input[] = "1 + 2 + 3 + 41 - 5 * 6";
    TypeMaths output[20];
    stringToDec(input, output);

     for (int i = 0; i< 11; i++)
    {
        if (output[i].key == NUMBER)
        {
            printf("key: NUMBER %d\n", output[i].value.number);
        }else{
            if (output[i].key == OPERATE)
            {
                printf("key: OPERATOR %c\n", output[i].value.operator);
            }
            
            
        }
        
    }

    uint32_t result = Calculate(output, 0, 11);
    printf("result = %d\n", result);
    return 0;
}
