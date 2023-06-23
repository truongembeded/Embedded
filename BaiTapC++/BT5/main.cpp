#include<bits/stdc++.h>

using namespace std;

class Person{
    private:
        string Name;
        int birthYear;
        string Address;
    public:
        Person(string Ten, int NamSinh, string DiaChi);
        void Print();
        uint32_t TinhTuoi();
};

Person::Person(string Ten, int NamSinh, string DiaChi){
    Name = Ten;
    birthYear = NamSinh;
    Address=DiaChi;
}

void Person::Print(){
    cout << "Ten : "<<Name<<endl;
    cout <<"birthYear:" <<birthYear<<endl;
    cout <<"Diachi:"<<Address<<endl;
}

uint32_t Person::TinhTuoi(){
    int currentYear = 2023;
    return currentYear - birthYear;
}

int main(int argc, char const *argv[])
{
    Person person("Truong", 2001, "Vung Tau");
    person.Print();
    cout<<"Age:"<<person.TinhTuoi()<<" "<<"Tuoi"<<endl;
    return 0;
}
