#include<bits/stdc++.h>
#include"Nhahang.h"
using namespace std;

/*
 * Function: Method setTenMon
 * Description: Đặt tên cho món ăn
 * Input:
 *   tenmon - char*
 */
void Food::setTenMon(char tenmon[]){
    strcpy(Food::TenMon, tenmon) ;
}
/*
 * Function: Method setGia
 * Description: Đặt giá cho món ăn
 * Input:
 *   gia - int
 */
void Food::setGia(int gia){
    Gia = gia;
}
/*
 * Function: Constructor Food
 * Description: Khởi tạo dữ liệu cho mỗi món ăn
 * Input:
 *   tenmon - char* tên món ăn
 *   gia - int giá món ăn
 */
Food::Food(char tenmon[], int gia){
    //// Tự động tạo ID tự động
    static uint8_t id = 100;
    Id = id;
    id++;
    strcpy(Food::TenMon, tenmon) ;
    Gia = gia;

}
/*
 * Function: Method getId
 * Description: Lấy ID của Món ăn
 * Output:
 *   Id - int
 */
int Food::getId(){
    return Id;
}
/*
 * Function: Method getGia
 * Description: Lấy giá của Món ăn
 * Output:
 *   Gia - int
 */
int Food::getGia(){
    return Gia;
}
/*
 * Function: Method getTenMon
 * Description: Lấy tên của Món ăn
 * Output:
 *   TenMon - char*
 */
char* Food::getTenMon(){
    return TenMon;
}
/*
 * Function: Method setSoBan
 * Description: Đặt số lượng bàn
 */
void QuanLy::setSoBan(int soban){
    printf("Nhap so luong ban: ");
    scanf("%d",&soban);
    this->Soban = soban;
}
/*
 * Function: Method getSoBan
 * Description: Lấy số lượng bàn
 * Output:
 *   Soban - int
 */
int QuanLy::getSoBan(){
    return Soban;
}
/*
 * Function: Method getListFood
 * Description: Lấy data danh sách món ăn đã tạo
 * Output:
 *   Database - list<Food>
 */
list<Food> QuanLy::getListFood(){
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
        ENTER_INFORMATION("Nhap ten mon an: ", "%s", &TenMon, 0);
        ENTER_INFORMATION("Nhap Gia: ", "%d", &Gia, Gia < 0);

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
    CHECK_ERROR
    (
        Database,
        "Danh sach Mon An trong!\n",
        "KHONG THE SUA MON!\n",

        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : Database) 
        {
            PRINT_LIST(Stt, food);
            Stt++;
        }
        DOWHILE_METHODMENU
        (
            cout<<"--SUA MON AN THEO ID--"<<endl;
            cout <<"Nhap Id Mon an can SUA:";
            cin>> id; 
            for (auto it = Database.begin(); it != Database.end(); ++it){

                if(it->getId() == id)
                {
                    ENTER_INFORMATION("Sua mon an: ", "%s", &TenMon, 0);
                    ENTER_INFORMATION("Sua Gia Tien: ", "%d", &Gia, Gia < 0);
                    
                    it->setTenMon(TenMon);
                    it->setGia(Gia);

                Havefood = true;   
                cout<<"SUA MON AN THANH CONG!"<<endl;  
                break;
                };           
                
            };

            if(Havefood != 1)
            {
                cout<<"KHoong tim thay mon an"<<endl;
            }
        );
    );
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
    
    CHECK_ERROR(
        Database,
        "DANH SACH MON AN TRONG!",
        "KHong THE XOA MON!",

        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : Database) 
        {
            PRINT_LIST(Stt, food);
            Stt++;
        }

        DOWHILE_METHODMENU
        (
            printf("Nhap Id Mon An:");
            scanf("%d", &id);

            for (auto it = Database.begin(); it != Database.end(); ++it) 
            {
                if(it->getId() == id){

                    Database.erase(it);
                    Havefood = true;
                    cout<<"DA XOA MON AN!"<<endl;  
                    break;  
                }
                
                
            }
            if(!Havefood)
            {
                cout<<"KHoong tim thay Id mon an"<<endl;
            }  
        );
    );

}
/*
 * Function: DanhSachMon
 * Description: hiễn thị danh sách món mà qyarn lý đã set up
 */
void QuanLy::DanhSachMon(){
    uint8_t key;
    CHECK_ERROR
    (

        Database,
        "DANH SACH MON AN TRONG!",
        "KHong the hien thi danh sach!",

        DOWHILE_METHODMENU
        (
            printf("\n--------------------------DANH SACH MON AN---------------------------\n");
                                    printf("STT\t| ID\t| Ten Mon\t|  Gia\n");
                        uint8_t Stt = 1;
                        for (Food food : Database) 
                        {
                            PRINT_LIST(Stt, food);
                            Stt++;
                        }
        );
    );
}

/*
 * Function: ChuongTrinhQuanLy
 * Description: Chương trình của quản lý
 */
void QuanLy::ChuongTrinhQuanLy(QuanLy *quanly){

    uint8_t key;
    int soban;
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
    
    ENTER_INFORMATION("Nhan Phim de tiep tuc: ", "%d", &key, key > 5 || key < 0);
     switch ((Menu)key)
        {
        case THEMMON:
            ThemMon();
            break;

        case SUAMON:
            SuaMon();
            break;

        case XOAMON:
            XoaMon();
            break;
        case DANHSACH:
            DanhSachMon();
            break;

        case SOBAN:
            setSoBan(soban);
            break;

        case OUT:
            return;
        
        default:
            break;
        }
    }while (key);
   
}   

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
/*
 * Function: Constructor BanAn
 * Description: Khởi tạo dữ liệu cho bàn ăn, Copy data danh sách món ăn của Quản lý đã tạo để gọi món
 * Input:
 *   quanly - QuanLy
 */
BanAn::BanAn(QuanLy quanly) {
    for(auto food : quanly.getListFood()){
        copyfood.push_back(food);
    }
}
/*
 * Function: GoiMon
 * Description: Gọi món ăn
 */
void BanAn::GoiMon(){
    uint8_t key;
    int id;
    int soluong = 0;
    bool Havefood = false;

    CHECK_ERROR
    (

       copyfood,
        "DANH SACH MON AN TRONG!",
        "KHONG THE GOI MON!",

        printf("\n-----------------DANH SACH MON AN------------\n");
                    printf("  STT\t| ID\t| Ten Mon\t|  Gia\n");
        uint8_t Stt = 1;           
        for (Food food : copyfood) 
        {
            PRINT_LIST(Stt, food);
            Stt++;
        }

        DOWHILE_METHODMENU
        (
            cout<<"--GOI MON AN!--"<<endl;
            cout <<"Nhap Id Mon an: ";
            cin>> id; 
            for (auto it = copyfood.begin(); it != copyfood.end(); ++it){

                if(it->getId() == id)
                {
                    ENTER_INFORMATION("Nhap so luong: ", "%d", &soluong, soluong < 0);
                   
                    GoiMonAn food(it->getId(), it->getTenMon(), it->getGia(), soluong);
                        goimon.push_back(food);
                        SoBanHienTai = 1;
                        Havefood = true;
                        break;
                };
            };
            if(Havefood != 1)
            {
                printf("KHONG TIM THAY MON AN CAN GOI\n");
            }
        );
    );
}
/*
 * Function: Method HienThiDSGoiMon
 * Description: Hiển thị món ăn đã gọi
 */
void BanAn::HienThiDSGoiMon(){
    uint8_t key;
    bool Havefood = false;
    CHECK_ERROR
    (
        copyfood,
        "DANH SACH GOI MON TRONG!",
        "KHONG THE HIEN THI!",

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
    );
}
/*
 * Function: Method getThanhToan
 * Description: Tính tổng tiền món ăn đã gọi
 */
void BanAn::getThanhToan(){


    uint8_t key;
    bool Havefood = false;
    CHECK_ERROR
    (
        copyfood,
        "DANH SACH GOI MON TRONG!",
        "KHONG THE THANH TOAN!",
        
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
            for(GoiMonAn orther : goimon)
            {
                BanAn::ThanhToan +=   orther.getGiaMonDuocGoi() * orther.getSoMonAn();
            }
                cout<<"Tong thanh toan la : "<< ThanhToan<<(" VND")<<endl;
                goimon.clear();
                SoBanHienTai = 0;
        );
    );
}
/*
 * Function: Method getSoBanHienCo
 * Description: Lấy trạng thái của mỗi bàn, xem bàn đó đã có người ăn chưa 
 * Output:
 *   SoBanHienTai - bool 
 */
bool BanAn::getSoBanHienCo(){
    return SoBanHienTai;
}
/*
 * Function: Method CapNhatLaiMonAn
 * Description: Cập nhật danh sách món ăn khi Quản Lý thay đổi 
 */
void BanAn::CapNhatLaiMonAn(QuanLy quanly){
    copyfood.clear();
    for(auto data : quanly.getListFood())
    {
        copyfood.push_back(data);
    }
}

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
     auto it = DanhSachBanAn.begin();
    for (int i = 0; i < SoBanAn; i++)
    {
        BanAn banan(*quanly);
        it->CapNhatLaiMonAn(*quanly);//cập nhập thông tin danh sách món ăn
        ++it;
    }
    for (int i = SoBanConLai; i < NhanVien::SoBanAn; i++)
    {
        BanAn banan(*quanly);
        DanhSachBanAn.push_back(banan);// cập nhật thêm bàn từ quản lí nếu có set up thêm
        ++it;
    }
}
/*
 * Function: Method HienThiDSBan
 * Description: Hiển thị trạng thái bàn 
 */
void NhanVien::HienThiDSBan(){
    int key;
    CHECK_ERROR
    (
        DanhSachBanAn,
        "Ban an chua duoc Quan Ly setup!\n",
        "KHONG THE HIEN THI DANH SACH BAN AN!\n",
    
        printf("-------Trang thai ban------\n");
            printf("Ban:     |");
            for (int i = 1; i <= NhanVien::SoBanAn; i++)
            {
                printf(" %d |",i);
            }
            printf("\nT.Thai:  |");

            auto it = DanhSachBanAn.begin();
            for (int i = 0; i < NhanVien::SoBanAn; i++)
            {
                if(it->getSoBanHienCo() == 1){
                    printf(" X |");
                    ++it;
                }else{
                    printf(" O |");
                }
            }
    );
}

/*
 * Function: Method ChonBanAn
 * Description: Lựa chọn bàn ăn và gọi món
 * Input:
 *   choice - int
 */
void NhanVien::ChonBanAn(int choice){
    int key;
   CHECK_ERROR
   (
        DanhSachBanAn,
        "Ban an chua duoc setup!\n",
        "KHONG THE CHON BAN AN!\n",
    
        auto it = DanhSachBanAn.begin();
        advance(it, choice);// di chuyển đến vị trí choice
        printf("------BAN %d------\n",choice + 1);
        printf("1. Goi mon\n");
        printf("2. Danh sach mon da goi\n");
        printf("3. Tinh tien\n");
        printf("0. Thoat\n");

        ENTER_INFORMATION("Nhan Phim: ", "%d", &key, key > 3 || key < 0);

        switch ((Other)key)
        {
        case GOIMON:
            it->GoiMon();
            break;
        case DANHSACHMON:
            it->HienThiDSGoiMon();
            break;
        case THANHTOAN:
            it->getThanhToan();
            break;
        case EXIT:
            return;
        default:
            break;
        }

        
   );
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
        ENTER_INFORMATION("Chon Ban: ", "%d",&key ,key > nhanvien->getSoBan()  || key < 0 );

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
        ENTER_INFORMATION("Nhan Phim: ", "%d", &key, key > 2 || key < 0 );
        
        switch ((Restaurant)key)
        {
        case QUAN_LY:
            quanly.ChuongTrinhQuanLy(&quanly);
            nhanvien.getDataTuQuanLy(&quanly);
            break;
        case NHAN_VIEN:
            nhanvien.CapNhatDataTuQuanLy(&quanly);
            ChuongTrinhNhanVien(&nhanvien);
            break;
        case THOAT:
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
