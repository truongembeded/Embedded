#include<bits/stdc++.h>

using namespace std;

class HinhTron{
    private:
        uint8_t R;
        float Pi ;
    public:
        HinhTron(uint8_t r, float P);
        float ChuVi();
        float DienTich();
};

HinhTron::HinhTron(uint8_t r, float P){
    R = r;
    Pi = P;
}

float HinhTron::ChuVi(){
    return 2 * Pi * R;
}

float HinhTron::DienTich(){
    return Pi * R * R;
}

int main(int argc, char const *argv[])
{
    HinhTron HT(5, 3.14);
    float PhepTinh = HT.ChuVi();
    cout<<"chu vi cua hinh tron la "<<PhepTinh<<endl;
    PhepTinh = HT.DienTich();
    cout<<"dien tich cua hinh tron la "<<PhepTinh<<endl;
    return 0;
}
