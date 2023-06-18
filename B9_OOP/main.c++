#include<iostream>

//tính đa hình

class ToanHoc{
    public:
        void Tong(int a, int b);
        void Tong(int a, int b, int c);
        int Tong(int a, double b);
};

void ToanHoc::Tong(int a, int b){
    printf("Tong a va b: %d\n", a+b);
}

void ToanHoc::Tong(int a, int b, int c){
    printf("Tong a va b: %d\n", a+b+c);
}

int ToanHoc::Tong(int a, double b){
    return a+b;
}

template<typename var, typename var>

var Tong(var a, var b){
    return (var)(a+b);
}



int main(int argc, char const *argv[])
{
    ToanHoc th;
    th.Tong(2, 3);
    th.Tong(2, 3, 4);

    printf("%d\n",th.Tong(2, 5.2));
    return 0;
}
