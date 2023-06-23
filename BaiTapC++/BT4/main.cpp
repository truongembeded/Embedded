#include<bits/stdc++.h>

using namespace std;

class Animals{
    private:
        uint8_t Age;
        string Name;
        float Kg;
        float Height;
    public:
        Animals(uint16_t Tuoi, string Ten, float Kilogram, float H);
        float BMI();
        void Compare(Animals animal);
};

Animals::Animals(uint16_t Tuoi, string Ten, float Kilogram, float H){
    Age = Tuoi;
    Name = Ten;
    Kg = Kilogram;
    Height = H;
}

float Animals::BMI(){
    return Kg / (Height * Height);
}

void Animals::Compare(Animals animal){
    if(Age > animal.Age && Kg > animal.Kg){
        cout << "This animal is older and heavier." << endl;
    }else if (Age < animal.Age && Kg < animal.Kg) {
            cout << "This animal is younger and thinner." << endl;
        } else {
            cout << "Both animals are of the same age and the same weight." << endl;
        }
}

int main(int argc, char const *argv[])
{
    Animals Meo(3, "Meo", 2, 0.35);
    Animals Cho(4,"Cho", 6, 1);

    cout<< "BMI :"<<Meo.BMI()<<endl;
    cout<<"BMI:"<<Cho.BMI()<< endl;

    Meo.Compare(Cho);
    return 0;
}


