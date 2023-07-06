#ifndef SINHVIEN_H
#define SINHVIEN_H
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
 * Function: MACRO ENTER_INFORMATION
 * Description: Macro phần nhập thông tin sinh viên
 * Input:
 *   content - Nội dung cần nhập
 *   format - định dạng kiểu dữ liệu
 *   variable - biến cần nhập vào
 *   condition - điều kiện để nhập
 */
#define ENTER_INFORMATION(content, format, variable, condition) \
    do                                                          \
    {                                                           \
        printf(content);                                        \
        scanf(format, variable);                                \
    } while (condition)                                         

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin Danh Sách Sinh viên
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_LIST(object)                                                                  \
     printf(" %d\t| %s\t\t| %d\t|   %d\t\t|", object.GetId(), object.GetName(),             \
           object.GetAge(), object.Getgender());                                            \
    printf(" %.2f\t| %.2f\t| %.2f\t|", object.getScoreMath(), object.getScorePhysic(),      \
           object.getScoreChemistry());                                                     \
    printf("   %.2f\t|   %s\n", object.getScoreAvarge(), object.getRankStudent())

/*
 * Function: MACRO CHECK_LIST
 * Description: Macro kiểm tra danh sách có sinh viên chưa
 * Input:
 *   notification - Nội dung thông báo
 *   content - Nội dung Method Menu
 */
#define CHECK_ERROR(notification, content)                                      \
    if (Database.empty())                                                       \
    {                                                                           \
        printf(notification);                                                   \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        content                                                                 \
    }

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
 * Function: enum Choose
 * Description: liệt kê các các hàm của chương trình  
 */
typedef enum{
    THOAT,
    THEM,
    CAPNHAT,
    XOA,
    TIMKIEMTEM,
    SAPXEPGPA,
    SAPXEPTEN,
    HIENTHI
}Choose;
/*
 * Function: Class Sinh viên
 * Description: Chứa Property & Method sử dụng cho class sinh viên
 */

class SinhVien{
    private:
        int ID;
        char Name[20];
        TypeGender Gender;
        uint32_t Age;
        float scoreMath;
        float scorePhysic;
        float scoreChemistry;
        TypeHocLuc Hoc_Luc;

    public : 
        SinhVien(char name[], TypeGender gender, uint32_t age, float toan, float ly, float hoa);

        void setgender(TypeGender gender);
        void setName(char name[]);
        void setAge(uint32_t age);
        void setScoreMath(float math);
        void setScorePhysic(float physic);
        void setScoreChemistry(float chemistry);

        int GetId();
        TypeGender Getgender();
        char* GetName();
        uint32_t GetAge();
        float getScoreAvarge();
        char* getRankStudent();
        float getScoreMath();
        float getScorePhysic();
        float getScoreChemistry();
};

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

#endif