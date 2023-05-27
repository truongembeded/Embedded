#include<stdio.h>


extern void dem();

void test(){
    static int a = 10;// 0x01
    printf("a = %d\n", a);
    a++;
}

int main(int argc, char const *argv[])
{
    test();
    test();
    test();
    dem();
    dem();

    return 0;
}
