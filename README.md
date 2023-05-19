Compiler

    •   Quy trình compiler là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ đích máy để máy tính có thể hiểu và thực thi. Chương trình được viết bằng C muốn chạy được trên máy tính phải qua quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang dạng mã thực thi.
    •	Giai đoàn tiền xử lý (Pre-processor)
    •	Giai đoạn dịch NNBC sang Asembly (Compiler)
    •	Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
    •	Giai đoạn liên kết (Linker)

    1. Giai đoạn tiền xử lý – Preprocessor
    •	Nhận mã nguồn
    •	Xóa bỏ tất cả chú thích, comments của chương trình
    •	Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
    2. Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly
    •	Phân tích syntax của mã nguồn NNBC
    •	Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp gần với tập lệnh của bộ vi xử lý.
    3. Công đoạn dịch Assembly
    •	Dich chương trình => Sang mã máy 0 và 1
    •	Một tệp mã máy (.obj) sinh ra .
    4. Giai đoạn Linker
    •	Mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau 
    •	Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
    •	Tất cả các lỗi trong chương trình đều sẽ bị phát hiện
    •   Tất cả liên kết lại với nhau thành một chương trình (executable hay .exe) thống nhất.

Phân Vùng Nhớ

    •   Phân vùng test: chỉ read, chỉ khai báo hằng số (const) và con trỏ xâu (char *arr = "hello")
    •   Phân vùng data: biến global and static with value khác 0. khi nạp code sẽ tồn tại cho đến khi tắt nguồn vđk
    •   Phân vùng bss: ngược lại với data, khi được gán lại giá trị thì nó vẫn ở phân vùng bss
    •   Stack: biến local and input parameter, được giải phóng khi ra khỏi block code
    ví dụ

        int tong (int a, int b){
            int c;
            c = a + b;
            return c;
        }
        int main{
            tong(7, 8); //khi thoát khỏi hàm sẽ được giải phóng hết

            return 0;
        }

Marco 

    •   Không phải hàm củng không phải biến mà là 1 định nghĩa diễn ra trong quá trình tiền xử lí. Bản chất của marco là thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó nên chương trình sẽ dài ra mà time chạy ctring lại tối ưu hơn.

Inline 

    •   Được xử lý bởi compiler, khi gặp từ khoá inline sẽ được biên dịch ra ngôn ngữ máy tính có thể hiểu rồi mới thay thế đoạn code đó vào hàm ngược lại với marco

Function 

    •   Phải tạo một function call nên tốn thời gian nhưng code ngắn gọn hơn.

Program counter 

    •   là một bộ đếm của chương trình giống như vđk 8 bit bước nhảy của nó sẽ là 1 byte đầu tiên nó sẽ đếm 0x00 tiếp tục cho đến 0x08 tức là nó sẽ chạy qua từng ô nhớ rồi đọc giá trị ra

Stack pointer 

    •   nó sẽ lưu địa chỉ của con trỏ xảy ra khi PC đang đếm mà nhảy sang địa chỉ khác thì stack pointer nó sẽ lưu địa chỉ tiếp theo của PC đang đếm và nhảy sang đếm địa chỉ tiếp theo đó đếm xong lấy quả rồi tiếp tục thực hiện chương trình.

Thao tác bit:

    •   AND(&) : 1 & 1 = 1 còn lại là 0
    •   NOT(~) : 0 -> 1 and 1 -> 0
    •   OR(|)  : 0 | 0 = 0 còn lại là 1
    •   XOR(^) : giống nhau thì thành 0(0 ^ 0 = 0) khác thì thành 1(0 ^ 1 = 1)
    •   <<     : dịch trái bao nhiêu bit thì lấy bấy nhiêu bit đưa thành 0 rồi đem qua phải
            ví dụ : 0b11010101 << 2 = 0b01010100 ví dụ này ta lấy 2 bit 11 đổi thành 0 rồi đưa sang phải
    •   >>     : dịch phải bao nhiêu bit thì lấy bấy nhiêu bit đổi thành 0 rồi đưa sang trái
            ví dụ : 0b11010101 >> 3 = 0b00011010 ví dụ này ta lấy 3 bit 101 đổi thành 0 rồi đưa sang phải

Hoạt động của vđk:

    •   Vđk 8 bit 1 port có thể đk được 8 chân tương đương với 8 bit (0b00000000) và 1 bit tương đương với 1 chân.
    •   Để mà vđk đk được các chân thì bên trong vđk chứ các transitor giống như các khoá k để điều khiển được. 
    •   Nó chỉ có 2 mức điện áp 5v - 0 ngta sẽ sử dụng mã binary (bit 0 1) để điều khiển chân có điện áp sẽ là bit 1 và chân không có điện là bit 0.

    


  
