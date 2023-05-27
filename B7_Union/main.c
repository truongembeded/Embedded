#include<stdio.h>
#include<stdint.h>
#include<string.h>


typedef union 
{
    char test1[6];
    char test2[3];
}typedata;



int main(int argc, char const *argv[])
{
   typedata data;
    strcpy(data.test1, (char*)"hello");
    data.test1[5] = '\0';

    strcpy(data.test2, (char*)"hi");
    data.test2[2] = '\0';
    for (int i = 0; i < 6; i++)
    {
        printf("%c\n",data.test1[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        data.test1[i] = i;
    }

    for (int i = 0; i < 3; i++)
    {
        data.test2[i] = 2*i;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("test1: %d\n", data.test1[i]);
    }
    
    
    
    
   
    return 0;
}
