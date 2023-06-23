#include<bits/stdc++.h>

using namespace std;

class BirthDay{
    private:
        uint8_t Day;
        uint16_t Month;
        int Year;
    public:
        BirthDay(uint8_t Ngay, uint16_t Thang, int Nam);
        uint32_t TinhTuoi();
        uint8_t check_date(uint8_t day, uint16_t month);
        uint8_t check_month(uint16_t month);
        uint8_t check_year(int year);
        
};

BirthDay::BirthDay(uint8_t Ngay, uint16_t Thang, int Nam){
    Day = Ngay;
    Month = Thang;
    Year = Nam;
}

uint8_t BirthDay::check_date(uint8_t day, uint16_t month){
    Day = day;
    Month = month;
     if ((month!=2) && (day<=0) && (day>29)){
    return 0;
 }
 if ((
 (month!=1) ||
 (month!=3) ||
 (month!=5) ||
 (month!=7) ||
 (month!=8) ||
 (month!=10)||
 (month!=12)
 ) && ((day<=0) && (day>31)))
 {
    return 0;
 }
 if ((
 (month!=4) ||
 (month!=6) ||
 (month!=9) ||
 (month!=11)
 ) && ((day<=0) && (day>30)))
 {
    return 0;
 }
    return 1;
}

uint8_t BirthDay::check_month(uint16_t month){
    Month = month;
    if ((month<=0) && (month>12)){
        return 0;
    }else{
        return 1;
    }
}

uint8_t BirthDay::check_year(int year){
    if ((year<=999) && (year > 2022)){
        return 0;
    }else{
 
        return 1;
    }
}

uint32_t BirthDay::TinhTuoi(){
    int namhientai = 2023;
    if(Month < 12){
            namhientai= namhientai;

        }else {
           namhientai+=1;
        }
 
    return namhientai - Year;
}

class Checker{
    private:
        uint32_t Day; 
        uint16_t Month;
        map<pair<uint32_t, uint16_t>, bool> holidays;
    public:
        
        Checker(uint32_t day, uint16_t month);
        void Check_Holiday();
        void AddHoliday(int day, int month);

};
Checker::Checker(uint32_t day, uint16_t month){
    Day = day;
    Month = month;
}

void Checker::AddHoliday(int day, int month) {
    holidays[make_pair(day, month)] = true;
}

void Checker::Check_Holiday(){
    auto it = holidays.find(make_pair(Day, Month));
    if (it != holidays.end()){
        cout << "This is the Holiday." << endl;
    } else {
        cout << "This is not the Holiday." << endl;
    }
}

int main(int argc, char const *argv[])
{
    BirthDay Truong(20, 10, 2001);
    cout << "Tuoi: "<<Truong.TinhTuoi()<<endl;
    BirthDay Nam(21, 7, 2000);
    cout << "Tuoi: "<<Nam.TinhTuoi()<<endl;

    Checker holiday(24,12);
    holiday.AddHoliday(1,1);
    holiday.AddHoliday(2,9);
    holiday.AddHoliday(14,2);
    holiday.AddHoliday(8,3);
    holiday.AddHoliday(1,5);
    holiday.AddHoliday(24,12);
    holiday.AddHoliday(20,10);
    holiday.AddHoliday(20,11);
    holiday.AddHoliday(30,4);
    holiday.Check_Holiday();
    return 0;
}
