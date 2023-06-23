#include<bits/stdc++.h>

using namespace std;

class ATM{
    private:
        int STK;
        string Name;
        int SoDu;
    public:
        ATM(int stk, string name, int sodu);
        void RutTien(int money);
        void NapTien(int Money);
        int Check_Stk();
};

ATM::ATM(int stk, string name, int sodu){
    STK = stk;
    Name = name;
    SoDu = sodu;
}

void ATM::RutTien(int money){
    if (SoDu < 50000) {
        cout<<"Khong đu tien đe rut!"<<endl;
        }else{
            SoDu -= money;
            cout << "Ban da rut thanh cong" <<":"<<money<< endl;
            }
}

void ATM::NapTien(int Money) {
    
    if(Money <= 10000){
        cout <<"Khong du tien de nap:"<<endl;
    }else{
        SoDu += Money;
        cout << "Ban da nap thanh cong" <<":"<<Money<< endl;
    }
}

int ATM::Check_Stk(){

    return SoDu;
}
        


int main(int argc, char const *argv[])
{
    ATM atm(38793817, "Truong", 5000000 );
    atm.NapTien(100000);
    cout<< "So du con lai :"<<atm.Check_Stk()<<endl;
    atm.RutTien(10000);
    cout<< "So du con lai :"<<atm.Check_Stk()<<endl;
    
    return 0;
}
