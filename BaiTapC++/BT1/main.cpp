#include<iostream>
#include<math.h>
using namespace std;

class Diem{
    private:
        int8_t ToaDoX;
        int8_t ToaDoY;
    public:
        Diem(int8_t X = 0, int8_t Y = 0);

        void setToaDoX(int X){
            ToaDoX = X;
        }
        int8_t getToaDoX(){
            return ToaDoX;
        }
        void setToaDoY(int Y){
            ToaDoY = Y;
        }
        int8_t getToaDoY(){
            return ToaDoY;
        }
};

Diem::Diem(int8_t X, int8_t Y){
    ToaDoX = X;
    ToaDoY = Y;
}


class PhepToanOXY{
    private:
        Diem A;
        Diem B;
        Diem C;
    public:
        PhepToanOXY(Diem DiemA, Diem DiemB);
        PhepToanOXY(Diem DiemA, Diem DiemB, Diem DiemC);
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH_BA_DIEM
        }TypePhepToan;
        TypePhepToan PhepToan;
        float getKhoangCach();
        float getDienTich();
};
PhepToanOXY::PhepToanOXY(Diem DiemA, Diem DiemB){
    PhepToan = KHOANG_CACH;
    A = DiemA  ;
    B = DiemB  ;
}

PhepToanOXY::PhepToanOXY(Diem DiemA, Diem DiemB, Diem DiemC){
    PhepToan = DIEN_TICH_BA_DIEM;
    A = DiemA  ;
    B = DiemB  ;
    C = DiemC  ;
}

float PhepToanOXY::getKhoangCach(){
     if (PhepToan == KHOANG_CACH) {
        float deltaX = B.getToaDoX() - A.getToaDoX();
        float deltaY = B.getToaDoY() - A.getToaDoY();
        return sqrt(deltaX * deltaX + deltaY * deltaY);
     }else{
        cout<<"ERROR"<<endl;
     }
     return 0.0f;
}

float PhepToanOXY::getDienTich(){
    if(PhepToan == DIEN_TICH_BA_DIEM){
        float a = sqrt(pow(B.getToaDoX() - C.getToaDoX(), 2) + pow(B.getToaDoY() - C.getToaDoY(), 2));
        float b = sqrt(pow(A.getToaDoX() - C.getToaDoX(), 2) + pow(A.getToaDoY() - C.getToaDoY(), 2));
        float c = sqrt(pow(A.getToaDoX() - B.getToaDoX(), 2) + pow(A.getToaDoY() - B.getToaDoY(), 2));

        float p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }else{
        cout<<"ERROR"<<endl;
    }
     return 0.0f;
}


int main(int argc, char const *argv[])
{
    Diem p1(3, 2);
    Diem p2(8, 6);

    PhepToanOXY KhoangCach(p1, p2 );
    float result = KhoangCach.getKhoangCach();
    cout << "Khoang cach cua tam giac la: " << result << endl;
    Diem p3(7, 3);
    p1.setToaDoX(8);
    p1.setToaDoY(5);
    p2.setToaDoX(4);
    p2.setToaDoY(9);
    PhepToanOXY DienTich(p1, p2, p3);
    float result2 = DienTich.getDienTich();
    cout << "Dien tich hai diem " << result2 << endl;

    return 0;
}
