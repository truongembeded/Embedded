**1. Compiler**
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)

- Giai đoạn dịch NNBC sang Asembly (Compiler)

- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)

- Giai đoạn liên kết (Linker)

1. Giai đoạn tiền xử lý – Preprocessor  
Giai đoạn này sẽ thực hiện:

- Nhận mã nguồn

- Xóa bỏ tất cả chú thích, comments của chương trình

- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý

_Ví dụ_: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.

2. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly

- Phân tích cú pháp (syntax) của mã nguồn NNBC

- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

3. Công đoạn dịch Assembly

- Dich chương trình => Sang mã máy 0 và 1

- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

4. Giai đoạn Linker

- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.

- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.

**2. Phân Vùng Nhớ**


   - **Phân vùng test:** chỉ read, chỉ khai báo hằng số (const) và con trỏ xâu (char *arr = "hello")
    -   **Phân vùng data:** Quyền truy cập là read-write
											Biến global and static with value khác 0.
											khi nạp code sẽ tồn tại cho đến khi tắt nguồn vđk
	 -   **Phân vùng bss:**  Quyền truy cập là read-write.
			Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
			Được giải phóng khi kết thúc chương trình

   -   **Stack:** Quyền truy cập là read-write.
			   Được sử dụng cấp phát cho biến local, input parameter của hàm,…
			   Sẽ được giải phóng khi ra khỏi block code/hàm

    ví dụ:
    include<stdio.h>
    int tong (int a, int b){
    	int c;
    	c = a + b;
    	return c;
    }
    int main{
    	tong(7, 8); //khi thoát khỏi hàm sẽ được giải phóng hết

    	return 0;
    }

   -	**Heap**: Quyền truy cập là read-write.
			  Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
			  Sẽ được giải phóng khi gọi hàm free,…


**3. Stack và Heap**

-   Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
-   Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
-   Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm _malloc - calloc - realloc_ (trong C)

-   _Kích thước vùng nhớ_  
    Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).  
    Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
-   _Đặc điểm vùng nhớ_  
    Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.  
    Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.

Lưu ý: việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.

-   _Vấn đề lỗi xảy ra đối với vùng nhớ_  
    Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...  
    Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:

			int foo(int x){

			printf("De quy khong gioi han\n");

			return foo(x);

			}

- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).  
Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.  
Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:

		int *A = (int *)malloc(18446744073709551615);



**4. Sự khác nhau giữa Macro, Inline và Function**

1. Macro:

- Được xử lý bởi preprocessor

- Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó

		#define SUM(a,b) (a+b)

- Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

2. Inline

- Được xử lý bởi compiler

- Được khai báo với từ khóa inline

- Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile

3. Hàm bình thường

- Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.

- Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)

4. So sánh

- Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch

- Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi

- Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình

- Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.

- Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình

- Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.
 **5. static**
**Biến static cục bộ**
- Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.

**Biến static toàn cục**

- Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.

**6. Thao tác bit:**

  -    AND(&) : 1 & 1 = 1 còn lại là 0
  -    NOT(~) : 0 -> 1 and 1 -> 0
  -  OR(|)  : 0 | 0 = 0 còn lại là 1
  -    XOR(^) : giống nhau thì thành 0(0 ^ 0 = 0) khác thì thành 1(0 ^ 1 = 1)
  -    (<<)     : dịch trái bao nhiêu bit thì lấy bấy nhiêu bit đưa thành 0 rồi đem qua phải
            ví dụ : 0b11010101 << 2 = 0b01010100 ví dụ này ta lấy 2 bit 11 đổi thành 0 rồi đưa sang phải
  -    (>>): dịch phải bao nhiêu bit thì lấy bấy nhiêu bit đổi thành 0 rồi đưa sang trái
            ví dụ : 0b11010101 >> 3 = 0b00011010 ví dụ này ta lấy 3 bit 101 đổi thành 0 rồi đưa sang phải

**7. Hoạt động của vđk:**

   -   Vđk 8 bit 1 port có thể đk được 8 chân tương đương với 8 bit (0b00000000) và 1 bit tương đương với 1 chân.
    -   Để mà vđk đk được các chân thì bên trong vđk chứ các transitor giống như các khoá k để điều khiển được. 
    -   Nó chỉ có 2 mức điện áp 5v - 0 ngta sẽ sử dụng mã binary (bit 0 1) để điều khiển chân có điện áp sẽ là bit 1 và chân không có điện là bit 0.

**8. Struct:**

   -   là kiểu dữ liệu do mình tự định nghĩa..
   -   Kích thước của một biến struct được xác định bởi tổng kích thước của các thành phần và bộ nhớ đệm của nó .

** Union:**

   -   Union là cấu trúc dữ liệu tương tự như struct, cho phép lưu trữ nhiều biến có cùng địa chỉ dùng chung
   -   khi truyền data các giá trị sẽ bị ghi đè lên nhau và nó sẽ lấy giá trị cuối cùng
   -   Kích thước của Union chính là kích thước của member lớn nhất 
   -   Vì là địa chỉ dùng chung nên khi thay đổi giá trị của một member thì sẽ ảnh hưởng đến những member khác
   -   Ứng dụng của Union chính là những trường hợp chỉ được chọn một để dùng thì sẽ sử dụng Union vì nó là bộ nhớ dùng chung nên sẽ đỡ tốn bộ nhớ
   
 **So sánh struct và union**

Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

- struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

- Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

**9. Khái niệm con trỏ**

- Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.

- Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.

- Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu.

- Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.

**Con trỏ là gì?**

- Trong ngôn ngữ C/C++, **con trỏ (pointer)** là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.

**Con trỏ NULL**

- Con trỏ **NULL**  là con trỏ lưu địa chỉ **0x00000000**. Tức địa chỉ bộ nhớ **0**, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.

	  int  *`p2`;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó

      int  *`p3` =  NULL;//con trỏ null không trỏ đến vùng nhớ nào

 **Kích thước của con trỏ**

Ví dụ các khai báo con trỏ sau:

	char  *`p1`;

	int  *`p2`;

	float  *`p3`;

	double  *`p4`;

Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau.
  
