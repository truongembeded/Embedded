/*
 * File: main.cpp
 * Author: Nguyen Van Truong
 * Date: 24/06/2023
 * Description: Chương trình quản lý sinh viên
 */
#include<bits/stdc++.h>
#include"SinhVien.h"
using namespace std;


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
void SinhVien::setName(char name[]){
    strcpy(this->Name, name);
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
SinhVien::SinhVien(char name[], TypeGender gender, uint32_t age, float toan, float ly, float hoa){
    static int id = 100;
    ID = id;
    id++;
    strcpy(this->Name, name);
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
char* SinhVien::GetName(){
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
char* SinhVien::getRankStudent(){
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

void menu::ThemSinhVien(){  
    char name[20];
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    uint8_t key;
    DOWHILE_MENU
    (

        ENTER_INFORMATION("Nhap ten: ", "%s", &name, 0);

    
        int genderChoice;
        ENTER_INFORMATION("Nhap gioi tinh (0 - Nam, 1 - Nu): ", "%d", &genderChoice, genderChoice != 0 && genderChoice != 1);
        gender = static_cast<TypeGender>(genderChoice);

        ENTER_INFORMATION("Nhap tuoi: ", "%d", &age, 0);
        
        ENTER_INFORMATION("Nhap diem Toan: ", "%f", &toan, toan < 0 || toan > 10);

        ENTER_INFORMATION("Nhap diem Ly: ", "%f", &ly, ly < 0 || ly > 10);

        ENTER_INFORMATION("Nhap diem Hoa: ", "%f", &hoa, hoa < 0 || hoa > 10);

        SinhVien newStudent(name, gender, age, toan, ly, hoa);
        Database.push_back(newStudent);
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
    char name[20];
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    uint8_t chonPhim;
    CHECK_ERROR
    (
        "KHONG THE CAP NHAT THONG TIN !\n",

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
                    ENTER_INFORMATION("Nhan Phim :", "%d", &chonPhim, 0);
                    
                        switch (chonPhim){
                            case 1:
                                ENTER_INFORMATION("Nhap ten: ", "%s", &name, 0);

                                Database.at(i).setName(name);
                                break;
                            case 2:
                                ENTER_INFORMATION("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);
                                
                                Database.at(i).setAge(age);
                                break;
                            case 3:
                                int genderChoice;
                                ENTER_INFORMATION("Nhap gioi tinh (0 - Nam, 1 - Nu): ", "%d", &genderChoice, genderChoice != 0 && genderChoice != 1);
                                gender = static_cast<TypeGender>(genderChoice);
                                Database.at(i).setgender(gender);
                                break;
                            case 4:
                                ENTER_INFORMATION("Nhap diem Toan: ", "%d", &toan, toan < 0 || toan > 10);
                                Database.at(i).setScoreMath(toan);
                                break;
                            case 5:
                                ENTER_INFORMATION("Nhap diem Ly: ", "%d", &ly, ly < 0 || ly > 10);

                                Database.at(i).setScorePhysic(ly);
                                
                                break;
                            case 6:
                                ENTER_INFORMATION("Nhap diem Hoa: ", "%d", &hoa, hoa < 0 || hoa > 10);

                                Database.at(i).setScoreChemistry(hoa);
                            case 7:
                                break;
                            default:
                                printf("KHONG DUNG LUA CHON, VUI LONG NHAP LAI\n");
                                break;
                            }

                            haveStudent = true;

                            break;
                        }
                    }
                    
                    if (haveStudent != 1)
                    {
                        printf("KHONG TIM THAY SINH VIEN\n");
                    }  
        );       
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
    CHECK_ERROR
    (
        "KHONG THE XOA SINH VIEN !\n",

        DOWHILE_MENU(
            for (int i = 0; i < Database.size() - 1; i++){
                    if (Database.at(i).GetId() == id)    
                    Database.erase(Database.begin() + i);
                    haveStudent = 1;
                    cout<<"da xoa sinh vien co ID "<<id<<endl;
                    break;
                    }
            if(haveStudent != 1)
            {
                cout<<"Khong co sv nao voi Id la: "<<id<<endl;
            }
        );
    );

}
/*
 * Function: Method searchStudent
 * Description: Tìm kiếm thông tin Sinh vien theo tên
 */
void menu::TimKiemSV_Name(){
    cout << "--TIM KIEM SINH VIEN THEO TEN--"<<endl;
    char Name[20];
    
    TypeGender gender;
    uint32_t age;
    float toan, ly, hoa;
    bool haveStudent = false;
    uint8_t key;
    CHECK_ERROR
    (
        "KHONG THE TIM KIEM SINH VIEN !\n",

        DOWHILE_MENU(

            ENTER_INFORMATION("Nhap ten: ", "%s", &Name, 0);
            for (int index = 0; index < Database.size(); index++)
            {
                if (strcmp(Database.at(index).GetName(), Name) == 0)
                {
                    printf("  ID\t| Ten\t\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
                    PRINT_LIST(Database.at(index));
                    haveStudent = true;

                    break;
                }
            }
            if(haveStudent != 1)
            {
                cout<<"Khong co sv nao voi Ten la: "<<Name<<endl;
            }
        );
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
    CHECK_ERROR
    (
        "KHONG THE SAP XEP SINH VIEN THEO GPA !\n",

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
            cout << "*Da sap xep Danh sach Sinh Vien theo GPA*\n";
            );
    );
    
}
/*
 * Function: SapXepSV_Name
 * Description: Sắp xếp sinh viên theo tên Sinh viên
 */
void menu::SapXepSV_Name(){
    uint8_t key;
    CHECK_ERROR
    (
        "KHONG THE SAP XEP SINH VIEN THEO TEN !\n",

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
            cout << "*Da sap xep Danh sach Sinh Vien theo Ten*\n";
            );
    );
    
}

void menu::HienThi_DSSV(){
    uint8_t key;
    CHECK_ERROR(
        "KHONG THE HIEN THI!\n",

        DOWHILE_MENU(
             printf("\n------------------------------------DANH SACH SINH VIEN-----------------------------------\n");
                printf("  ID\t| Ten\t\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
                for (SinhVien sinhvien : Database) 
                {
                    PRINT_LIST(sinhvien);
                }
        );
    );
        
}

void Program(){
    uint8_t key;
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
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        ENTER_INFORMATION("- Nhan phim de tiep tuc chuong trinh: ", "%d", &key, key > 8 || key < 0);

        switch ((Choose)key)
        {
        case THEM:
            menu.ThemSinhVien();
            break;
        case CAPNHAT:
            menu.CapNhatSV_ID();
            break;
        case XOA:
            menu.XoaSV_ID();
            break;
        case TIMKIEMTEM:
            menu.TimKiemSV_Name();
            break;
        case SAPXEPGPA:
            menu.SapXepSV_GPA();
            break;
        case SAPXEPTEN:
            menu.SapXepSV_Name();
            break;
        case HIENTHI:
            menu.HienThi_DSSV();
            break;
        case THOAT:
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
