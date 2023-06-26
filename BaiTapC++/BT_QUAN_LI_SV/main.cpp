/*
 * File: main.cpp
 * Author: Nguyen Van Truong
 * Date: 24/06/2023
 * Description: Chương trình quản lý sinh viên
 */
#include<bits/stdc++.h>

using namespace std;

/*
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_MENU(content)                                       \
    do                                                              \
    {                                                               \
        content                                                     \
        printf("- Nhan phim '0' => De Thoat chuc nang\n");          \
        printf("- Nhan phim '1' => De tiep tuc chuc nang\n");       \
        printf("Nhan Phim:");                                       \
        scanf("%d", &key);                                          \
    } while (key == 1)

/*
 * Function: enum TypeGender
 * Description: liệt kê giới tính 
 */
typedef enum{
    NAM,
    NU
}TypeGender;
/*
 * Function: enum TypeHocLuc
 * Description: liệt kê các mức học lực  
 */
typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;
/*
 * Function: Class Sinh viên
 * Description: Chứa Property & Method sử dụng cho class sinh viên
 */
class SinhVien{
    private:
        int ID;
        string Name;
        TypeGender Gender;
        uint32_t Age;
        float scoreMath;
        float scorePhysic;
        float scoreChemistry;
        TypeHocLuc Hoc_Luc;

    public : 
        SinhVien(string name, TypeGender gender, uint32_t age, float toan, float ly, float hoa);

        void setgender(TypeGender gender);
        void setName(string name);
        void setAge(uint32_t age);
        void setScoreMath(float math);
        void setScorePhysic(float physic);
        void setScoreChemistry(float chemistry);

        int GetId();
        TypeGender Getgender();
        string GetName();
        uint32_t GetAge();
        float getScoreAvarge();
        string getRankStudent();
        float getScoreMath();
        float getScorePhysic();
        float getScoreChemistry();
};
/*
 * Function: Method setgender
 * Description: Đặt giới tính cho sinh viên
 * Input:
 *   gender - chuỗi kí tự chứa giới tính
 */
void SinhVien::setgender(TypeGender gender){
    Gender = gender;
}
/*
 * Function: Method setName
 * Description: Đặt tên cho sinh viên
 * Input:
 *   name - chuỗi kí tự chứa tên
 */
void SinhVien::setName(string name){
    Name = name;
}
/*
 * Function: Method setAge
 * Description: Đặt tuổi cho sinh viên
 * Input:
 *   ageStudent - uint32_t age
 */
void SinhVien::setAge(uint32_t age){
    Age = age;
}
/*
 * Function: Method setScoreMath
 * Description: Đặt điểm toán cho sinh viên
 * Input:
 *   scoreMath - float điểm toán
 */
void SinhVien::setScoreMath(float math){
    scoreMath = math;
}
/*
 * Function: Method setScoreMath
 * Description: Đặt điểm lý cho sinh viên
 * Input:
 *   scoreMath - float điểm lý
 */
void SinhVien::setScorePhysic(float physic){
    scorePhysic = physic;
}
/*
 * Function: Method setScoreChemistry
 * Description: Đặt điểm hóa cho sinh viên
 * Input:
 *   scoreChemistry - float điểm hóa
 */
void SinhVien::setScoreChemistry(float chemistry){
    scoreChemistry = chemistry;
}
/*
 * Function: Constructor Student
 * Description: Khởi tạo dữ liệu cho mỗi Sinh viên
 * Input:
 *   name - Mảng chuỗi kí tự chứa tên
 *   gender - Mảng chuỗi kí tự chưa giới tính
 *   age - uint8_t tuổi
 *   toan - float điểm toán
 *   hoa - float điểm hóa
 *   ly - float điểm lý
 */
SinhVien::SinhVien(string name, TypeGender gender, uint32_t age, float toan, float ly, float hoa){
    static int id = 100;
    ID = id;
    id++;
    this->Name = name;
    this->Age = age;
    this->Gender = gender;
    this->scoreMath = toan;
    this->scorePhysic = ly;
    this->scoreChemistry = hoa;
}
/*
 * Function: Method getID
 * Description: Lấy ID của Sinh viên
 * Output:
 *   ID - int id
 */
int SinhVien::GetId(){
    return ID;
}
/*
 * Function: Method getNameStudent
 * Description: Lấy tên của Sinh viên
 * Output:
 *   Name - string tên
 */
string SinhVien::GetName(){
    return Name;
}
/*
 * Function: Method getGender
 * Description: Lấy giới tính của Sinh viên
 * Output:
 *   Gender -  TypeGender giới tính
 */
TypeGender SinhVien::Getgender(){
    return Gender;
}
/*
 * Function: Method getAge
 * Description: Lấy tuổi của Sinh viên
 * Output:
 *   Age - uint32_t tuổi
 */
uint32_t SinhVien::GetAge(){
    return Age;
}
/*
 * Function: Method getScoreMath
 * Description: Lấy điểm toán của Sinh viên
 * Output:
 *   scoreMath - float điểm toán
 */
float SinhVien::getScoreMath(){
    return scoreMath;
}
/*
 * Function: Method getScorePhysic
 * Description: Lấy điểm lý của Sinh viên
 * Output:
 *   scorePhysic - float điểm lý
 */
float SinhVien::getScorePhysic(){
    return scorePhysic;
}
/*
 * Function: Method getScoreChemistry
 * Description: Lấy điểm hóa của Sinh viên
 * Output:
 *   scoreChemistry - float điểm hóa
 */
 float SinhVien::getScoreChemistry(){
     return scoreChemistry;
}
/*
 * Function: Method getScoreAvarge
 * Description: Tính toán và Lấy điểm toán của Sinh viên
 * Output:
 *   scoreAvarge - float điểm Trung Binh
 */
float SinhVien::getScoreAvarge(){
    float Avarge = (scoreMath + scorePhysic + scoreChemistry) / 3;
    return Avarge;
}
/*
 * Function: Method getRankStudent
 * Description: Xét học lực dựa vào điểm TB
 * Output:
 *   getRankStudent - string TypeHocLuc
 */
string SinhVien::getRankStudent(){
    if (getScoreAvarge() >= 8 ) {
        Hoc_Luc == GIOI;
        return "GIOI";
    }
    else if (getScoreAvarge() >= 6.5 ){
        Hoc_Luc == KHA;
        return "KHA";
        }else if(getScoreAvarge()  >= 5 ){
        Hoc_Luc == TRUNG_BINH;  
        return "TRUNG_BINH";
    }else {
        Hoc_Luc == YEU;
        return "YEU";
    }
}
/*
 * Function: Class Menu
 * Description: Chứa Property & Method sử dụng cho chương trình quản lý sinh viên
 */
class menu{
    private:
        vector<SinhVien> Database;
        
        
    public:
        void ThemSinhVien();
        void CapNhatSV_ID();
        void XoaSV_ID();
        void TimKiemSV_Name();
        void SapXepSV_GPA();
        void SapXepSV_Name();
        void HienThi_DSSV();

};

void menu::ThemSinhVien(){  
    string name;
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    uint8_t key;
    DOWHILE_MENU
    (
    do {
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, name);
    } while (name.empty());

    int genderChoice;
    do {
        cout << "Nhap gioi tinh (0 - Nam, 1 - Nu): ";
        cin >> genderChoice;
        cin.ignore();
    } while (genderChoice != 0 && genderChoice != 1);

    gender = static_cast<TypeGender>(genderChoice);

    cout << "Nhap tuoi: ";
    cin >> age;
    cin.ignore();

    do {
        cout << "Nhap diem Toan: ";
        cin >> toan;
        cin.ignore();
    } while (toan < 0 || toan > 10);

    do {
        cout << "Nhap diem Ly: ";
        cin >> ly;
        cin.ignore();
    } while (ly < 0 || ly > 10);

    do {
        cout << "Nhap diem Hoa: ";
        cin >> hoa;
        cin.ignore();
    } while (hoa < 0 || hoa > 10);

    SinhVien newStudent(name, gender, age, toan, ly, hoa);
    Database.push_back(newStudent);
    cout<<newStudent.GetId()<<endl;
    cout<<"Them thanh cong"<<endl;
    );
}
/*
 * Function: Method CapNhatSV_ID
 * Description: Cập nhật thông tin Sinh viên theo ID
 */
void menu::CapNhatSV_ID() {
    uint8_t key;
    
    cout << "-CAP NHAT THONG TIN SINH VIEN-"<<endl;
    bool haveStudent = false;
    int id;
    cout <<"Nhap ma id SV can CAP NHAT:";
    cin>> id;       
    string name;
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    uint8_t chonPhim;
DOWHILE_MENU(
    for (int i = 0; i < Database.size(); i++) {
        if (Database.at(i).GetId() == id) {
            printf("------CHON THONG TIN CAN CAP NHAT------\n");
            printf("1. TEN\n");
            printf("2. TUOI\n");
            printf("3. GIOI TINH\n");
            printf("4. DIEM TOAN\n");
            printf("5. DIEM LY\n");
            printf("6. DIEM HOA\n");
            printf("7. Thoat\n");
            printf("-------------------------------------------\n");
            do
            {
                printf("Nhan Phim :");
                scanf("%d", &chonPhim);
            } while (0);
                switch (chonPhim){
                    case 1:
                        do{
                            cin.ignore();
                            cout << "Nhap ten sinh vien: ";
                            getline(cin, name);
                        }while (name.empty());
                        Database.at(i).setName(name);
                        break;
                    case 2:
                        do {
                            cout << "Nhap tuoi : ";
                            cin>> age;
                        } while (age > 100 || age < 1);
                        Database.at(i).setAge(age);
                        break;
                    case 3:
                        int genderChoice;
                        do {
                            cout << "Nhap gioi tinh (0 - Nam, 1 - Nu): ";
                            cin >> genderChoice;
                            cin.ignore();
                        } while (genderChoice != 0 && genderChoice != 1);
                        gender = static_cast<TypeGender>(genderChoice);
                        Database.at(i).setgender(gender);
                        break;
                    case 4:
                        do {
                            cout << "Nhap diem Toan: ";
                            cin >> toan;
                            cin.ignore();
                        } while (toan < 0 || toan > 10);
                        Database.at(i).setScoreMath(toan);
                        break;
                    case 5:
                        do {
                            cout << "Nhap diem Ly: ";
                            cin >> ly;
                            cin.ignore();
                        } while (ly < 0 || ly > 10);
                        Database.at(i).setScorePhysic(ly);
                        
                        break;
                    case 6:
                        do {
                            cout << "Nhap diem Toan: ";
                            cin >> toan;
                            cin.ignore();
                        } while (hoa < 0 || hoa > 10);
                        Database.at(i).setScoreChemistry(hoa);
                    case 7:
                        break;
                    default:
                        printf("KHONG DUNG LUA CHON, VUI LONG NHAP LAI\n");
                        break;
                    }

                    haveStudent = 1;

                    break;
                }
            }
            
            if (haveStudent != 1)
            {
                printf("KHONG TIM THAY SINH VIEN\n");
            }  
    );       
}

/*
 * Function: Method eraseStudent
 * Description: Xóa Sinh viên theo ID
 */
void menu::XoaSV_ID(){
    cout << "-XOA SINH VIEN THEO ID-"<<endl;
    bool haveStudent = false;
    int id;
        cout <<"Nhap ma SV can XOA:";
        cin>> id;
    uint8_t key;
DOWHILE_MENU(
   for (int i = 0; i < Database.size() - 1; i++){
        if (Database.at(i).GetId() == id)    
        Database.erase(Database.begin() + i);
        haveStudent = 1;
        cout<<"da xoa sinh vien co ID "<<id<<endl;
        break;
        }
    if(haveStudent != 1){
        cout<<"Khong co sv nao voi Id la: "<<id<<endl;
       }
    );
}
/*
 * Function: Method searchStudent
 * Description: Tìm kiếm thông tin Sinh vien theo tên
 */
void menu::TimKiemSV_Name(){
    cout << "--TIM KIEM SINH VIEN THEO TEN--"<<endl;
    string Name;
    cin.ignore();
    cout <<"Nhap TEN SV can TIM KIEM:";
    getline(cin, Name);
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    bool haveStudent = false;
    uint8_t key;
DOWHILE_MENU(
    for(auto temp : Database){
        if (temp.GetName().compare(Name)== 0 ){
            cout<< "Id: "<< temp.GetId() <<endl;
            cout<< "Name:"<< temp.GetName() <<endl;
            cout<< "Age:"<< temp.GetAge()<<endl;
            cout<< "GioiTinh:"<< temp.Getgender()<<endl;
            cout<< "Toan:"<< temp.getScoreMath()<<endl;
            cout<<"Ly:"<< temp.getScorePhysic()<<endl;
            cout<< "Hoa:"<< temp.getScoreChemistry()<<endl;
            cout<< "Diem TB:"<< temp.getScoreAvarge()<<endl;
            cout<<"HocLuc:"<<temp.getRankStudent()<<endl;
            cout<< "----------------------------------"<<endl;
            haveStudent = 1;
    }
        break;
       }
       if(haveStudent != 1){
        cout<<"Khong co sv nao voi Ten la: "<<Name<<endl;
       }
    );
}
/*
 * Function: swap
 * Description: Đổi chỗ 2 sinh viên dùng cho thuật toán sắp xếp
 * Input:
 *   student1 - Con trỏ kiểu Student
 *   student2 - Con trỏ kiểu Student
 */    
void swap(SinhVien *Sinhvien1, SinhVien *Sinhvien2){
    SinhVien Sinhvien = *Sinhvien1;
    *Sinhvien1 = *Sinhvien2;
    *Sinhvien2 = Sinhvien;
}
/*
 * Function: Method SapXepSV_GPA
 * Description: Sắp xếp sinh viên theo điểm TB
 */
void menu::SapXepSV_GPA(){
    uint8_t key;
    DOWHILE_MENU(
    for (int i = 0; i < Database.size() - 1; i++)
    {
        SinhVien *SinhVien1 = &Database.at(i);
        for (int j = 1; j < Database.size(); j++)
        {
            SinhVien *Sinhvien2 = &Database.at(j);
            if(SinhVien1->getScoreAvarge() > Sinhvien2->getScoreAvarge())
            {
                swap(SinhVien1, Sinhvien2);
            }
        }
        
    }
    cout << "Da Sap xep Thanh cong!"<<endl;
    );
}
/*
 * Function: SapXepSV_Name
 * Description: Sắp xếp sinh viên theo tên Sinh viên
 */
void menu::SapXepSV_Name(){
    uint8_t key;
    DOWHILE_MENU(
    for (int i = 0; i < Database.size() - 1; i++)
    {
        SinhVien *Sinhvien1 = &Database.at(i);
        for (int j = 1; j < Database.size(); j++)
        {
            SinhVien *Sinhvien2 = &Database.at(j);
            if(Sinhvien1->GetName() > Sinhvien2->GetName()){
                swap(Sinhvien1, Sinhvien2);
            }
        }
        
    }
    cout << "Da Sap xep Thanh cong!"<<endl;
    );
}

void menu::HienThi_DSSV(){
    uint8_t key;
    if(Database.empty()){
        cout << "DANH SACH SINH VIEN TRONG!"<<endl;
    }else
    {
        DOWHILE_MENU(
            printf("\n------------------DANH SACH SINH VIEN----------------\n");
            for(SinhVien temp : Database){
                cout<< "Id: "<< temp.GetId() <<endl;
                cout<< "Name:"<< temp.GetName() <<endl;
                cout<< "Age:"<< temp.GetAge()<<endl;
                cout<< "GioiTinh:"<< temp.Getgender()<<endl;
                cout<< "Toan:"<< temp.getScoreMath()<<endl;
                cout<<"Ly:"<< temp.getScorePhysic()<<endl;
                cout<< "Hoa:"<< temp.getScoreChemistry()<<endl;
                cout<< "Diem TB:"<< temp.getScoreAvarge()<<endl;
                cout<<"HocLuc:"<<temp.getRankStudent()<<endl;
                cout<< "----------------------------------"<<endl;
            }
        );
    }
}

void Program(){
    uint8_t temp;
    menu menu;
    do
    {
        printf("------CHUONG TRINH QUAN LY SINH VIEN------\n");
        printf("1. Them Sinh Vien\n");
        printf("2. Cap nhat Thong Tin Sinh Vien\n");
        printf("3. Xoa Sinh Vien boi ID\n");
        printf("4. Tim kiem Thong Tin theo Ten \n");
        printf("5. Sap Xep Sinh Vien theo GPA\n");
        printf("6. Sap Xep Sinh Vien theo Ten\n");
        printf("7. Hien thi Danh Sach Sinh Vien\n");
        printf("8. Thoat\n");
        printf("-------------------------------------------\n");
        do
        {
            printf("Nhan Phim de tiep tuc:");
            scanf("%d", &temp);
        } while (temp > 8 || temp < 1);

        switch (temp)
        {
        case 1:
            menu.ThemSinhVien();
            break;
        case 2:
            menu.CapNhatSV_ID();
            break;
        case 3:
            menu.XoaSV_ID();
            break;
        case 4:
            menu.TimKiemSV_Name();
            break;
        case 5:
            menu.SapXepSV_GPA();
            break;
        case 6:
            menu.SapXepSV_Name();
            break;
        case 7:
            menu.HienThi_DSSV();
            break;
        case 8:
            exit(0);
        default:
            break;
        }
        
    } while (1);
    
}

int main(int argc, char const *argv[])
{
    Program();

    return 0;
}
