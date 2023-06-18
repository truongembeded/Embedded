#include<iostream>
#include<string.h>
using namespace std;
//tính kế thừa
class DoiTuong{
    public:
        void setThongTin(string name, int age);
        void hienThi();
    protected:
        int AGE;
        string NAME;
};

void DoiTuong::hienThi(){
    cout <<"day la class DoiTuong"<<endl;
    cout<<"age:"<<AGE<<endl;
    cout<<"name:"<<NAME<<endl;
}

void DoiTuong::setThongTin(string name, int age){
    AGE = age;
    NAME = name;
}

class SinhVien : public DoiTuong{
    public:
        void setThongTin(string name, int age, int mssv);
        void hienThi();
    private:
        int MSSV;
};

void SinhVien::hienThi(){
    cout <<"day la class SinhVien"<<endl;
    cout<<"age:"<<AGE<<endl;
    cout<<"name:"<<NAME<<endl;
    cout<<"mssv:"<<MSSV<<endl;
}

void SinhVien::setThongTin(string name, int age, int mssv){
    DoiTuong::setThongTin(name, age);
    MSSV = mssv;

}

int main(int argc, char const *argv[])
{
    
    DoiTuong dt;
    dt.setThongTin("Truong", 23);
    dt.hienThi();

    SinhVien sv;

    sv.setThongTin("Hoang", 20, 19436851);
    sv.hienThi();
    return 0;
}
