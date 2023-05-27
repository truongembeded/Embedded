#include<stdio.h>

#define MAX 10

#define sum(a, b) a + b

#define CREATE_FUNC(ten_ham, noi_dung)  \
void ten_ham(){                         \
    printf("%s\n", noi_dung);           \
}

CREATE_FUNC(test, "this is test\n")

int main(int argc, char const *argv[])
{
    printf("MAX: %d\n", MAX);
    int a = MAX + 5;

    printf("Tong a va b : %d\n", SUM(5, 7));

    test();
    return 0;
}
