#include<iostream>
using namespace std;
class SinhVien{
    public:
        SinhVien(int age, int lop);
        int age; // property
        int lop;
        void hienthi();// method
    private:
        int age;
        int lop;
};

void SinhVien::hienthi(){
    cout<<"age: "<<age<<endl;
    cout<<"lop: "<<lop<<endl;
}

SinhVien::SinhVien(int age, int lop){
    SinhVien::age = age;
    SinhVien::lop = lop;
}

int main(int argc, char const *argv[])
{
    SinhVien sv(22, 12);// object
    
    sv.hienthi();
    return 0;
}
