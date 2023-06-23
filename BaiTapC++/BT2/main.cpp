#include<iostream>
#include<math.h>
using namespace std;

class HinhChuNhat{
    private:
        int Height;
        int Width;
    public:
        HinhChuNhat(int H, int W);
        typedef enum{
            CHUVI,
            DIENTICH,
            DUONGCHEO
        }PHEPTOAN;
        PHEPTOAN PhepToan; 
        uint8_t ChuVi() ;
        uint16_t DienTich();
        uint8_t DuongCheo();
        void Check();
};

    HinhChuNhat::HinhChuNhat(int H, int W){
    HinhChuNhat::Height = H;
    HinhChuNhat::Width = W;
}

uint8_t HinhChuNhat::ChuVi(){
    PhepToan = CHUVI;
    return (Height + Width)*2;
}

uint16_t HinhChuNhat::DienTich(){
    PhepToan = DIENTICH;

    return Height * Width;
}

uint8_t HinhChuNhat::DuongCheo(){
    PhepToan = DUONGCHEO;
    
    return sqrt(pow(Height, 2) + pow(Width, 2));
}

void HinhChuNhat::Check(){
    if (Height == Width)
    {
        cout<<"This is HINH VUONG"<<endl;
    }else{
        cout<<"This is HINH CHU NHAT"<< endl;
    }
    
}

int main(int argc, char const *argv[])
{
    HinhChuNhat HCN(5, 5);
    
    uint16_t area = HCN.ChuVi();
    cout<< "CHU VI:"<<area <<endl;

    area = HCN.DienTich();
    cout<< "DIEN TICH:"<<area<<endl;

    area = HCN.DuongCheo();
    cout<< "DUONG CHEO:"<< area << endl;
    HCN.Check();
    return 0;
}
