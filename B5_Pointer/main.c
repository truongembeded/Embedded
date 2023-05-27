#include<stdio.h>

void tong (int a, int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

void hieu (int a, int b){
    printf("tong %d va %d = %d\n", a, b, a - b);
}

void tich1 (int a, int b){
    printf("tong %d va %d = %d\n", a, b, a * b);
}

void thuong (int a, int b){
    printf("tong %d va %d = %d\n", a, b, (float)a / b);
}

void pheptoan(int a, int b, void(*ptr)(int, int)){
    printf("chuong trinh\n");
    ptr(a, b);
}

int tich(int a, int b){
    return a*b;
}

int main(int argc, char const *argv[])
{
    //int *ptr = NULL;
    void(*ptr)(int, int) = NULL;
    ptr = &tong;
    ptr(9, 7);
    pheptoan(9, 5, tich1);
    
    int(*ptr_t)(int, int) = &tich;
    printf("tich : %d\n", ptr_t(6, 7));
    
    char *arr = "hello";

    char arr1[] = "hello";

    char *arr2[] = {"Hi", "Hello", "World"};

    printf("test : %c\n", *(*arr2 + 1));

    
    return 0;
}
