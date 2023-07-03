#include<bits/stdc++.h>

using namespace std;
/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin Danh Sách Món ăn
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(Stt, object)                                                      \
    printf(" %d\t| %d\t| %s\t\t|   %d\t\n", Stt, object.getId(),                           \
           object.getTenMon(), object.getGia());                                            \

/*
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                            \
    do                                                         \
    {                                                          \
        content                                                \
        printf("- Nhan phim '0' => De Thoat chuc nang\n");     \
        printf("- Nhan phim '1' => De tiep tuc chuc nang\n");  \
        printf("Nhan Phim: ");                                 \
        scanf("%d", &key);                                     \
    } while (key == 1)

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


void Food::setTenMon(char tenmon[]){
    strcpy(Food::TenMon, tenmon) ;
}

void Food::setGia(int gia){
    Gia = gia;
}

Food::Food(char tenmon[], int gia){
    //// Tự động tạo ID tự động
    static uint8_t id = 100;
    Id = id;
    id++;
    strcpy(Food::TenMon, tenmon) ;
    Gia = gia;

}


int Food::getId(){
    return Id;
}



int Food::getGia(){
    return Gia;
}

char* Food::getTenMon(){
    return TenMon;
}

/*-----------------------------------------------------CLASS QUANLY--------------------------------------------------------*/
/*
 * Function: Class Người Quản lý 
 * Description: Chứa Property & Method tương tác với class Food
 */
class QuanLy{
    private:
        vector<Food> Database;
        int Soban = 0;
    public:

        void setSoBan(int soban);
        int getSoBan();
        vector<Food> getListFood();
        void ThemMon();
        void SuaMon();
        void XoaMon();
        void DanhSachMon();
};

void QuanLy::setSoBan(int soban){
    this->Soban = soban;
}

int QuanLy::getSoBan(){
    return Soban;
}

vector<Food> QuanLy::getListFood(){
    return Database;
}
/*
 * Function: ThemMon
 * Description: Thêm món ăn vào danh sách
 */
void QuanLy::ThemMon(){
    char TenMon[20];
    int Gia;
    uint8_t key;
    
    DOWHILE_METHODMENU
    (
        cout<<"---THEM MON AN MOI---"<<endl;
    do
    {
        printf("Nhap ten mon an: ");
        scanf("%s", &TenMon);
    } while (0);

    do
    {
        
        cout<<"Nhap Gia: ";
        cin>>Gia;
        cin.ignore();
    } while (Gia < 0);

    Food food(TenMon, Gia);
    Database.push_back(food);
    cout << "Them thanh cong"<<endl;
    ); 
}
/*
 * Function: SuaMon
 * Description: Sửa món theo ID của món ăn
 */
void QuanLy::SuaMon(){
    
    uint8_t key;
    char TenMon[20];
    int Gia;
    int id;
    bool Havefood = false;
    if(Database.empty())
    {
        cout<<"Danh sach Mon An trong!\n";
        cout<<"KHONG THE SUA MON!\n";

    }else
    {
        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : Database) 
        {
            PRINT_INFORMATION(Stt, food);
            Stt++;
        }
        DOWHILE_METHODMENU
        (
            cout<<"--SUA MON AN THEO ID--"<<endl;
            cout <<"Nhap Id Mon an can SUA:";
            cin>> id; 
            for(int i = 0; i < Database.size(); i++){

                if(Database.at(i).getId() == id)
                {
                    do
                    {
                        printf("Sua mon an:");
                        scanf("%s", &TenMon);
                    } while (0);
                    do
                    {
                        cout<<"Sua Gia Tien:";
                        cin>>Gia;
                    } while (Gia < 0);
                    Database.at(i).setTenMon(TenMon);
                    Database.at(i).setGia(Gia);

                Havefood = 1;   
                break;
                };           
                
            };

            if(Havefood != 1)
            {
                cout<<"KHoong tim thay mon an"<<endl;
            }
        );
    };
}
/*
 * Function: XoaMon
 * Description: xoá món theo ID của món
 */
void QuanLy::XoaMon(){

    cout<< "--XOA MON AN THEO ID--"<<endl;
    bool Havefood = false;
    int id;
    uint8_t key;
    
    if(Database.empty()){

        cout<<"DANH SACH MON AN TRONG!"<<endl;
        cout<<"KHong THE XOA MON!"<<endl;
    }else{
        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : Database) 
        {
            PRINT_INFORMATION(Stt, food);
            Stt++;
        }

        DOWHILE_METHODMENU
        (
            printf("Nhap Id Mon An:");
            scanf("%d", &id);

            for (int i = 0; i < Database.size(); i++)
            {
                if(Database.at(i).getId() == id){

                    Database.erase(Database.begin() + i);
                    Havefood = 1;
                    break;  
                    cout<<"DA XOA MON AN!"<<endl;    
                }
                
                
            }
            if(!Havefood)
            {
                cout<<"KHoong tim thay Id mon an"<<endl;
            }  
        );
    };

}
/*
 * Function: DanhSachMon
 * Description: hiễn thị danh sách món mà qyarn lý đã set up
 */
void QuanLy::DanhSachMon(){
    uint8_t key;
    if(Database.empty())
    {

        cout<<"DANH SACH MON AN TRONG!"<<endl;
        cout<<"KHong the hien thi danh sach!"<<endl;
    }
    else
    {
        DOWHILE_METHODMENU
        (
            printf("\n--------------------------DANH SACH MON AN---------------------------\n");
                                    printf("STT\t| ID\t| Ten Mon\t|  Gia\n");
                        uint8_t Stt = 1;
                        for (Food food : Database) 
                        {
                            PRINT_INFORMATION(Stt, food);
                            Stt++;
                        }
        );
    };
}
/*
 * Function: ChuongTrinhQuanLy
 * Description: Chương trình của quản lý
 */
void ChuongTrinhQuanLy(QuanLy *ql){

    uint8_t key;
    int soban;
    QuanLy *quanly = ql;
    do
    {
        printf("------QUAN LY------\n");
        printf("1. Them mon\n");
        printf("2. Sua mon\n");
        printf("3. Xoa mon\n");
        printf("4. Danh sach mon an\n");
        printf("5. Thiet lap so ban\n");
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        do
        {
            printf("Nhan Phim de tiep tuc: ");
            scanf("%d", &key);
        } while (key > 5 || key < 0);
        switch (key)
        {
        case 1:
            ql->ThemMon();
            break;

        case 2:
            ql->SuaMon();
            break;

        case 3:
            ql->XoaMon();
            break;
        case 4:
            ql->DanhSachMon();
            break;

        case 5:
            printf("Nhap so luong ban: ");
            scanf("%d",&soban);
            ql->setSoBan(soban);
            break;

        case 0:
            return;
        
        default:
            break;
        }
    } while (key);
    
}
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
/*
 * Function: Constructor GoiMonAn
 * Description: Khởi tạo dữ liệu cho mỗi món ăn đã gọi
 * Input:
 *   id - int 
 *   nameFood - char*
 *   priceFood - int
 *   quantity - int
 */
GoiMonAn::GoiMonAn(int id, const char tenmon[], const int gia, const int soluong){

    this->Id=id;
    strcpy(this->TenMon,tenmon);
    this->Gia=gia;
    this->SoLuong = soluong;
}
/*
 * Function: Method setSoMonAn
 * Description: Set số lượng của mỗi món ăn
 * Input:
 *  quantity - int 
 */
void GoiMonAn::setSoMonAn(const int soluong){
    this->SoLuong = soluong;
}
/*
 * Function: Method getSoMonAn
 * Description: Lấy số lượng của mỗi món ăn
 * Output:
 *  quantity - int 
 */
int GoiMonAn::getSoMonAn(){
    return SoLuong;
}
/*
 * Function: Method getTenMonDuocGoi
 * Description: Lấy tên của món ăn đã gọi
 * Output:
 *  nameFood - char*
 */
char* GoiMonAn::getTenMonDuocGoi(){
    return TenMon;
}
/*
 * Function: Method getIdMonDuocGoi
 * Description: Lấy ID của món ăn đã gọi
 * Output:
 *  idFood - int 
 */
int GoiMonAn::getIdMonDuocGoi(){
    return Id;
}
/*
 * Function: Method getGiaMonDuocGoi
 * Description: Lấy giá của món ăn đã gọi
 * Output:
 *  priceFood - int
 */
int GoiMonAn::getGiaMonDuocGoi(){
    return Gia;
}

/*-----------------------------------------------------CLASS BANAN--------------------------------------------------------*/
/*
 * Function: Class BanAn
 * Description: Chứa Property & Method sử dụng cho class Employee
 */
class BanAn{
    private :
        int SoBanHienTai = 0;
        int ThanhToan = 0;
        vector<GoiMonAn> goimon;
        vector<Food> copyfood;
    public:
        BanAn(QuanLy quanly);
        void GoiMon();
        void HienThiDSGoiMon();
        void getThanhToan();
        int getSoBanHienCo();
        void CapNhatLaiMonAn(QuanLy quanly);
};

BanAn::BanAn(QuanLy quanly) {
    for(auto food : quanly.getListFood()){
        copyfood.push_back(food);
    }
}

void BanAn::GoiMon(){
    uint8_t key;
    int id;
    int soluong = 0;
    bool Havefood = false;


    if(copyfood.empty())
    {
        cout<<"DANH SACH MON AN TRONG!"<<endl;
        cout<<"KHONG THE GOI MON!"<<endl;

    }else
    {
        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : copyfood) 
        {
            PRINT_INFORMATION(Stt, food);
            Stt++;
        }

        DOWHILE_METHODMENU
        (
            cout<<"--GOI MON AN!--"<<endl;
            cout <<"Nhap Id Mon an: ";
            cin>> id; 
            for(int i = 0; i < copyfood.size(); i++){

                if((copyfood.at(i)).getId() == id)
                {
                    do
                    {
                        printf("Nhap so luong: ");
                        scanf("%d", &soluong);
                        
                    } while (soluong < 0);
                    GoiMonAn food((copyfood.at(i)).getId(), (copyfood.at(i)).getTenMon(), (copyfood.at(i)).getGia(), soluong);
                        goimon.push_back(food);
                        SoBanHienTai = 1;
                        Havefood = 1;
                        break;
                };
            };
            if(Havefood != 1)
            {
                printf("KHONG TIM THAY MON AN CAN GOI\n");
            }
        );
    };
}

void BanAn::HienThiDSGoiMon(){
    uint8_t key;
    bool Havefood = false;
    if(copyfood.empty())
    {
        cout<<"DANH SACH GOI MON TRONG!"<<endl;
        cout<<"KHONG THE HIEN THI!"<<endl;

    }
    else
    {
        DOWHILE_METHODMENU
        (
            printf("\n---------------DANH SACH GOI MON AN------------\n");
                        printf("  STT\t| ID\t| Ten Mon\t|  So Luong\n");
            uint8_t Stt = 1;           
            for (GoiMonAn food : goimon) 
            {
                printf(" %d\t| %d\t| %s\t\t|  %d\t\n",Stt, food.getIdMonDuocGoi(), food.getTenMonDuocGoi(), food.getSoMonAn());
                Stt++;
            }
        );
    }
}

void BanAn::getThanhToan(){


    uint8_t key;
    bool Havefood = false;
    if(copyfood.empty())
    {
        cout<<"DANH SACH GOI MON TRONG!"<<endl;
        cout<<"KHONG THE THANH TOAN!"<<endl;
    }
    else
    {
        
        printf("\n---------------DANH SACH GOI MON AN------------\n");
                    printf("STT\t|  ID\t|  Ten Mon\t|  So Luong\n");
        uint8_t Stt = 1;           
        for (GoiMonAn food : goimon) 
        {
            printf(" %d\t| %d\t| %s\t\t|  %d\t\n",Stt, food.getIdMonDuocGoi(), food.getTenMonDuocGoi(), food.getSoMonAn());
            Stt++;
        }
        DOWHILE_METHODMENU
        (
            for(GoiMonAn orther : goimon){
                BanAn::ThanhToan +=   orther.getGiaMonDuocGoi() * orther.getSoMonAn();
                cout<<"Tong thanh toan la : "<< ThanhToan<<(" VNĐ")<<endl;
                goimon.clear();
                SoBanHienTai = 0;
            }
        );
    };
}

int BanAn::getSoBanHienCo(){
    return SoBanHienTai;
}

void BanAn::CapNhatLaiMonAn(QuanLy quanly){
    copyfood.clear();
    for(auto data : quanly.getListFood())
    {
        copyfood.push_back(data);
    }
}
/*-----------------------------------------------------CLASS EMPLOYEE--------------------------------------------------------*/
/*
 * Function: Class Nhân viên
 * Description: Chứa Property & Method sử dụng cho chương trình của nhân viên
 */
class NhanVien{
    private:
        vector<BanAn> DanhSachBanAn;
        int SoBanAn = 0;
    public:
        void HienThiDSBan();
        void ChonBanAn(int choice);
        int getSoBan();
        void getDataTuQuanLy(QuanLy *quanly);
        void CapNhatDataTuQuanLy(QuanLy *quanly);
};
/*
 * Function: Method getSoBan
 * Description: Lấy số bàn Quản lý đã setup
 * Output:
 *  SoBanAn - int 
 */
int NhanVien::getSoBan(){
    return this -> SoBanAn ;
}

/*
 * Function: Method getDataTuQuanLy
 * Description: Lấy data danh sách món ăn và số bàn mà Quản lý đã setup
 * Input:
 *  QuanLy :*quanly
 */
void NhanVien::getDataTuQuanLy(QuanLy *quanly){

    NhanVien::SoBanAn = quanly->getSoBan();
    for (int i = 0; i < NhanVien::SoBanAn; i++)
    {
        BanAn banan(*quanly);
        DanhSachBanAn.push_back(banan);
    }
    
}
/*
 * Function: Method CapNhatDataTuQuanLy
 * Description: Cập nhât data danh sách món ăn và số bàn mà Quản lý đã setup
 * Input:
 *  QuanLy :*quanly
 */
void NhanVien::CapNhatDataTuQuanLy(QuanLy *quanly){

    int SoBanConLai = NhanVien::SoBanAn;
    NhanVien::SoBanAn = quanly->getSoBan();
    for (int i = 0; i < SoBanAn; i++)
    {
        BanAn banan(*quanly);
        DanhSachBanAn.at(i).CapNhatLaiMonAn(*quanly);//cập nhập thông tin danh sách món ăn
    }
    for (int i = SoBanConLai; i < NhanVien::SoBanAn; i++)
    {
        BanAn banan(*quanly);
        DanhSachBanAn.push_back(banan);// cập nhật thêm bàn từ quản lí nếu có set up thêm
    }
}
/*
 * Function: Method HienThiDSBan
 * Description: Hiển thị trạng thái bàn 
 */
void NhanVien::HienThiDSBan(){
    int key;
    if(DanhSachBanAn.empty())
    {
        cout<<"Ban an chua duoc Quan Ly setup!\n";
        cout<<"KHONG THE HIEN THI DANH SACH BAN AN!\n";
    }
    else
    {
        printf("-------Trang thai ban------\n");
            printf("Ban:     |");
            for (int i = 1; i <= NhanVien::SoBanAn; i++)
            {
                printf(" %d |",i);
            }
            printf("\nT.Thai:  |");
            for (int i = 0; i < NhanVien::SoBanAn; i++)
            {
                if(DanhSachBanAn.at(i).getSoBanHienCo() == 1){
                    printf(" X |");
                }else{
                    printf(" O |");
                }
            }
    }
}
/*
 * Function: Method ChonBanAn
 * Description: Lựa chọn bàn ăn và gọi món
 * Input:
 *   choice - int
 */
void NhanVien::ChonBanAn(int choice){
    int key;
    if(DanhSachBanAn.empty())
    {
        cout<<"Ban an chua duoc setup!\n";
        cout<<"KHONG THE CHON BAN AN!\n";
    }  
    else
    {

        printf("------BAN %d------\n",choice + 1);
        printf("1. Goi mon\n");
        printf("2. Danh sach mon da goi\n");
        printf("3. Tinh tien\n");
        printf("0. Thoat\n");
        do
        {
            printf("Nhan Phim: ");
            scanf("%d", &key);
        }while (key > 3 || key < 0);

        switch (key)
        {
        case 1:
            DanhSachBanAn.at(choice).GoiMon();
            break;
        case 2:
            DanhSachBanAn.at(choice).HienThiDSGoiMon();
            break;
        case 3:
            DanhSachBanAn.at(choice).getThanhToan();
            break;
        case 0:
            return;
        default:
            break;
        }

        
    }
}
/*
 * Function: ChuongTrinhNhanVien
 * Description: Chương trình dành cho Nhân Viên
 * Input:
 *  NhanVien - nhanvien*
 */
void ChuongTrinhNhanVien(NhanVien *nhanvien){

    int key;

    do
    {
        printf("------NHAN VIEN------\n");
        nhanvien->HienThiDSBan();
        printf("\n0. Thoat\n");
        printf("-------------------------------------------\n");
        do
        {
            printf("Chon Ban: ");
            scanf("%d",&key);
        } while (key > nhanvien->getSoBan()  || key < 0);

        switch (key)
        {
        case 0:
            return;
        default:
            nhanvien->ChonBanAn(key - 1);
            break;
        }
    } while (1);
    
}
/*
 * Function: ChuongTrinhMain
 * Description: Chương trình của Nhà Hàng Quản Lý
 */
void ChuongTrinhMain(){
    int key;
    QuanLy quanly;
    NhanVien nhanvien;
    do
    {
        printf("------CHUONG TRINH QUAN LY ORDER MON AN------\n");
        printf("1. Quan ly\n");
        printf("2. Nhan Vien\n");
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        do
        {
            printf("Nhan Phim: ");
            scanf("%d",&key);
        } while (key > 2 || key < 0);
        switch (key)
        {
        case 1:
            ChuongTrinhQuanLy(&quanly);
            nhanvien.getDataTuQuanLy(&quanly);
            break;
        case 2:
            nhanvien.CapNhatDataTuQuanLy(&quanly);
            ChuongTrinhNhanVien(&nhanvien);
            break;
        case 0:
            exit(0);
        
        default:
            break;
        }
        
    } while (1);
    
}
/*-----------------------------------------------------MAIN--------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    ChuongTrinhMain();
    
    
    return 0;
}
