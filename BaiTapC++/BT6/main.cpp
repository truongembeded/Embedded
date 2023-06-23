#include<bits/stdc++.h>

using namespace std;

class PhanSo{
    private:
        uint8_t TuSo;
        uint8_t MauSo;
    public:
        PhanSo(uint8_t Tu = 0, uint8_t Mau = 1);
        void setTuSo(uint8_t Tu){
            TuSo = Tu;
        }
        uint8_t getTuSo(){
            return TuSo;
        }
        void setMauSo(uint8_t Mau){
            MauSo = Mau;
        }
        uint8_t getMauSo(){
            return MauSo;
        }


};

PhanSo::PhanSo(uint8_t Tu, uint8_t Mau){
    this->TuSo = Tu;
    this->MauSo = Mau;
}

class PhepToan{
    private :
        PhanSo A;
        PhanSo B;
    public:
        PhepToan(PhanSo a, PhanSo b);
        void Tong();
        void Hieu();
        void Tich();
        void Thuong();

};

PhepToan::PhepToan(PhanSo a, PhanSo b){
    A = a;
    B = b;
}

void PhepToan::Tong(){
    int tongTu = (A.getTuSo()*B.getMauSo() + B.getTuSo()*A.getMauSo()) ;
    int tongMau = (A.getMauSo() * B.getMauSo());
    cout <<"Tong la:"<<tongTu<<"/"<< tongMau<< endl;
 }

void PhepToan::Hieu(){
    int hieuTu = (A.getTuSo()*B.getMauSo() - B.getTuSo()*A.getMauSo()) ;
    int hieuMau = (A.getMauSo() * B.getMauSo());
    cout <<"Hieu la:"<<hieuTu<<"/"<< hieuMau<< endl;
 }

void PhepToan::Tich(){
    int tichTu = (A.getTuSo()*B.getTuSo());
    int tichMau = (A.getMauSo()*B.getMauSo());
    cout <<"Tich la:"<<tichTu<<"/"<< tichMau<< endl;
}

void PhepToan::Thuong(){
    int thuongTu = (A.getTuSo()*B.getMauSo());
    int thuongMau = (A.getMauSo()*B.getTuSo());
    cout <<"Thuong la:"<<thuongTu<<"/"<< thuongMau<< endl;
}
int main(int argc, char const *argv[])
{
    PhanSo ps1(7, 8);
    PhanSo ps2(3, 4);

    PhepToan pheptoan(ps1, ps2);
    pheptoan.Tong();
    pheptoan.Hieu();
    pheptoan.Tich();
    pheptoan.Thuong();
    ps1.setTuSo(9);
    ps1.setMauSo(5);
    ps2.setTuSo(2);
    ps2.setMauSo(7);
    PhepToan pheptoan1(ps1, ps2);
    pheptoan1.Tong();
    pheptoan1.Hieu();
    pheptoan1.Tich();
    pheptoan1.Thuong();
    return 0;
}
