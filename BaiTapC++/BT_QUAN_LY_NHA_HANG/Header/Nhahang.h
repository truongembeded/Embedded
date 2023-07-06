#ifndef NHAHANG_H
#define NHAHANG_H

#include<bits/stdc++.h>

using namespace std;
/*
 * Function: enum Menu
 * Description: liệt kê các hàm của quản lý truy cập vào
 */
typedef enum{
    OUT,
    THEMMON,
    SUAMON,
    XOAMON,
    DANHSACH,
    SOBAN
}Menu;
/*
 * Function: enum Other
 * Description: liệt kê các hàm của nhân viên truy cập vào
 */
typedef enum{
    EXIT,
    GOIMON,
    DANHSACHMON,
    THANHTOAN
}Other;
/*
 * Function: enum Restaurant
 * Description: liệt kê các hàm của nhà hàng truy cập vào 
 */
typedef enum{
    THOAT,
    QUAN_LY,
    NHAN_VIEN  
}Restaurant;

/*
 * Function: MACRO ENTER_INFORMATION
 * Description: Macro phần nhập thông tin món ăn
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
 * Description: Macro phần hiển thị thông tin Danh Sách Món ăn
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_LIST(Stt, object)                                                             \
    printf(" %d\t| %d\t| %s\t\t|   %d\t\n", Stt, object.getId(),                            \
           object.getTenMon(), object.getGia());                                            \

/*
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                             \
    do                                                          \
    {                                                           \
        content                                                 \
        printf("Nhan phim '0' => De Thoat chuc nang\n");        \
        printf("Nhan phim '1' => De tiep tuc chuc nang\n");     \
        printf("Nhan Phim: ");                                  \
        scanf("%d", &key);                                      \
    } while (key == 1)

/*
 * Function: MACRO CHECK_LIST
 * Description: Macro kiểm tra danh sách có món ăn chưa
 * Input:
 *   notification - Nội dung thông báo
 *   content - Nội dung Method Menu
 */
#define CHECK_ERROR(list, notification1, notification2, content)                \
    if (list.empty())                                                           \
    {                                                                           \
        printf(notification1);                                                  \
        printf(notification2);                                                  \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        content                                                                 \
    }

/*-----------------------------------------------------CLASS FOOD--------------------------------------------------------*/
/*
 * Function: Class Món ăn
 * Description: Chứa Property & Method sử dụng cho class Món ăn
 */
class Food{
    private:
        int Id;
        char TenMon[20];
        int Gia;
    public:
        Food(char tenmon[], int gia);

        void setTenMon(char tenmon[]);
        void setGia(int gia);

        int getId();
        char* getTenMon();
        int getGia(); 
    
};
/*-----------------------------------------------------CLASS QUANLY--------------------------------------------------------*/
/*
 * Function: Class Người Quản lý 
 * Description: Chứa Property & Method tương tác với class Food
 */
class QuanLy{
    private:
        list<Food> Database;
        int Soban = 0;
        void setSoBan(int soban);
        void ThemMon();
        void SuaMon();
        void XoaMon();
        void DanhSachMon();
    public:
        void ChuongTrinhQuanLy(QuanLy *quanly);
        int getSoBan();
        list<Food> getListFood();
        
};
/*-----------------------------------------------------CLASS GOIMONAN--------------------------------------------------------*/
/*
 * Function: Class GoiMonAn
 * Description: Quản lý thông tin những món đã được Order
 */
class GoiMonAn{
    private:
        int SoLuong = 0;
        char TenMon[20];
        int Gia;
        int Id;
    public:
        GoiMonAn(int id,const char tenmon[], const int gia, const int soluong);

        void setSoMonAn(const int Soluong);

        int getSoMonAn();
        char* getTenMonDuocGoi();
        int getIdMonDuocGoi();
        int getGiaMonDuocGoi();
        
};
/*-----------------------------------------------------CLASS BANAN--------------------------------------------------------*/
/*
 * Function: Class BanAn
 * Description: Chứa Property & Method sử dụng cho class Employee
 */
class BanAn{
    private :
        int SoBanHienTai = 0;
        int ThanhToan = 0;
        list<GoiMonAn> goimon;
        list<Food> copyfood;
    public:
        BanAn(QuanLy quanly);
        void GoiMon();
        void HienThiDSGoiMon();
        void getThanhToan();
        bool getSoBanHienCo();
        void CapNhatLaiMonAn(QuanLy quanly);
};
/*-----------------------------------------------------CLASS EMPLOYEE--------------------------------------------------------*/
/*
 * Function: Class Nhân viên
 * Description: Chứa Property & Method sử dụng cho chương trình của nhân viên
 */
class NhanVien{
    private:
        list<BanAn> DanhSachBanAn;
        int SoBanAn = 0;
    public:
        void HienThiDSBan();
        void ChonBanAn(int choice);
        int getSoBan();
        void getDataTuQuanLy(QuanLy *quanly);
        void CapNhatDataTuQuanLy(QuanLy *quanly);
};



#endif