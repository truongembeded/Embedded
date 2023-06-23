#include<bits/stdc++.h>

using namespace std;

class Car{
    private:
        string Color;
        string DongCo;
        int Km;
    public:
        Car(string color, string dc, int km);
        int ChiPhi();
        void Print();
        int Check();
};

Car::Car(string color, string dc, int km){
    Color = color;
    Km = km;
    DongCo = dc;
}

int Car::ChiPhi(){
    int km = 1000;
    double Money = 10000000;
    int mantain = Km/km;
    double Cost = mantain * Money;
    return Cost;
}

int Car::Check(){
    return Km;
}

void Car::Print(){
    cout << "Mau xe la : "<<Color<<endl;
    cout << "Dong Co: " << DongCo << endl;
    cout <<"kilometer:" <<Km<<endl;
}

int main(int argc, char const *argv[])
{
    Car BWM("Black", "ABC", 4500);
    BWM.Print();
    cout<<"Km di duoc:" << BWM.Check()<<endl;
    cout<<"Chi phi bao tri la :" <<BWM.ChiPhi()<<endl;
    
    return 0;
}
