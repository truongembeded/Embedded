#include<bits/stdc++.h>

using namespace std;

class Books{
    private:
        string Name;
        string Auhtor;
        int Year;
        uint16_t SoLuong;
    public:
        Books(string name, string author, int year, uint32_t soluong);
        void HienThi();
        void MuonSach(uint32_t sl);
        void TraSach(uint32_t SL);
};

Books::Books(string name, string author, int year, uint32_t soluong){
    Name = name;
    Auhtor=author;
    Year = year;
    SoLuong = soluong;
}
void Books::HienThi(){
    cout<<"Name : "<<Name<<endl;
    cout<<"Author :"<<Auhtor<<endl;
    cout<<"Year:"<<Year<<endl;
    cout<<"Number of books :" <<SoLuong<<endl;
}
void Books::MuonSach(uint32_t sl) {
    if (sl > SoLuong ) {
        cout <<"Sorry! We don't have enough book!"<< endl;
        cout<<"Number of books :" <<SoLuong<<endl;
    }else{
        SoLuong -= sl;
        }
   
}
void Books::TraSach(uint32_t SL){
    if (SL < SoLuong ){
        SoLuong += SL;
        cout<<"Number of books :" <<SoLuong<<endl;
        } else {
        cout <<"Sorry !you have to return exactly number of books" <<endl;
        }
}

int main(int argc, char const *argv[])
{
    Books Book("Hai So Phan", "Jeffrey Archer", 1971, 10);
    Book.HienThi();
    Book.MuonSach(5);
    Book.TraSach(3);
    Book.TraSach(2);

    return 0;
}
