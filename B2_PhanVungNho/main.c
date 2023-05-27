#include<stdio.h>
char *arr = "hello"; //test
const int a = 10; //test
int a = 10; // datta
int a;// bss
static int a;// bss
static int a = 10; //data

int tong(int a, int b){// a b là input parameter được lưu trong stack
    static int a = 10; // data
    int c;// biến local được lưu trong stack
    c = a + b;
}

int main(int argc, char const *argv[])
{
    tong(7, 8);
    // int a = 7; 0x01
    //int a = 8;  0x02
    // int c;     0x03
    // khi nó kết thúc cái hàm tong thì 3 biến này sẽ được thu hồi vùng nhớ


    return 0;
}
