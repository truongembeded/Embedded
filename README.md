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

-  **Phân vùng test:** chỉ read, chỉ khai báo hằng số (const) và con trỏ xâu (char *arr = "hello")

-  **Phân vùng data:** Quyền truy cập là read-write

Biến global and static with value khác 0.

khi nạp code sẽ tồn tại cho đến khi tắt nguồn vđk

-  **Phân vùng bss:** Quyền truy cập là read-write.

Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

Được giải phóng khi kết thúc chương trình

-  **Stack:** Quyền truy cập là read-write.

Được sử dụng cấp phát cho biến local, input parameter của hàm,…

Sẽ được giải phóng khi ra khỏi block code/hàm

ví dụ:
```php
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
```
  
-  **Heap**: Quyền truy cập là read-write.

Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

Sẽ được giải phóng khi gọi hàm free,…

**3. Stack và Heap**

- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.

- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.

- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm _malloc - calloc - realloc_ (trong C)

-  _Kích thước vùng nhớ_

Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).

Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.

-  _Đặc điểm vùng nhớ_

Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.

Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.

Lưu ý: việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.

-  _Vấn đề lỗi xảy ra đối với vùng nhớ_

Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...

Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:

```php
int foo(int x){
printf("De quy khong gioi han\n");
return foo(x);

}
```
  - Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).

Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:

```php
int *A = (int *)malloc(18446744073709551615);
```
  
**4. Sự khác nhau giữa Macro, Inline và Function**

1. Macro:

- Được xử lý bởi preprocessor

- Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó

```php
#define SUM(a,b) (a+b)
```
  
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

- AND(&) : 1 & 1 = 1 còn lại là 0

- NOT(~) : 0 -> 1 and 1 -> 0

- OR(|) : 0 | 0 = 0 còn lại là 1

- XOR(^) : giống nhau thì thành 0(0 ^ 0 = 0) khác thì thành 1(0 ^ 1 = 1)

- (<<) : dịch trái bao nhiêu bit thì lấy bấy nhiêu bit đưa thành 0 rồi đem qua phải

ví dụ : 0b11010101 << 2 = 0b01010100 ví dụ này ta lấy 2 bit 11 đổi thành 0 rồi đưa sang phải

- (>>): dịch phải bao nhiêu bit thì lấy bấy nhiêu bit đổi thành 0 rồi đưa sang trái

ví dụ : 0b11010101 >> 3 = 0b00011010 ví dụ này ta lấy 3 bit 101 đổi thành 0 rồi đưa sang phải

**7. Hoạt động của vđk:**

- Vđk 8 bit 1 port có thể đk được 8 chân tương đương với 8 bit (0b00000000) và 1 bit tương đương với 1 chân.

- Để mà vđk đk được các chân thì bên trong vđk chứ các transitor giống như các khoá k để điều khiển được.

- Nó chỉ có 2 mức điện áp 5v - 0 ngta sẽ sử dụng mã binary (bit 0 1) để điều khiển chân có điện áp sẽ là bit 1 và chân không có điện là bit 0.

**8. Struct:**

- là kiểu dữ liệu do mình tự định nghĩa..

- Kích thước của một biến struct được xác định bởi tổng kích thước của các thành phần và bộ nhớ đệm của nó .

** Union:**

- Union là cấu trúc dữ liệu tương tự như struct, cho phép lưu trữ nhiều biến có cùng địa chỉ dùng chung

- khi truyền data các giá trị sẽ bị ghi đè lên nhau và nó sẽ lấy giá trị cuối cùng

- Kích thước của Union chính là kích thước của member lớn nhất

- Vì là địa chỉ dùng chung nên khi thay đổi giá trị của một member thì sẽ ảnh hưởng đến những member khác

- Ứng dụng của Union chính là những trường hợp chỉ được chọn một để dùng thì sẽ sử dụng Union vì nó là bộ nhớ dùng chung nên sẽ đỡ tốn bộ nhớ

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

- Con trỏ **NULL** là con trỏ lưu địa chỉ **0x00000000**. Tức địa chỉ bộ nhớ **0**, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.

int *`p2`;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó

int *`p3` = NULL;//con trỏ null không trỏ đến vùng nhớ nào

**Kích thước của con trỏ**

  

Ví dụ các khai báo con trỏ sau:

  
```php
char *`p1`;
int *`p2`;
float *`p3`;
double *`p4`;
```
Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau.

 #  C++

**Class** hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) cócùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) chonhững mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm :

  

- Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).

- Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.

- Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.

Khai báo class và sử dụng class 

Ví dụ một class cơ bản:
```php
 class Person { 
 public: 
		string firstName; // property 
		string lastName; // property 
		int age; // property 
		void fullname() { // method 
			cout << firstName << ' ' << lastName; } 
			}; 
```
			
- Cú pháp tạo object của một class và sử dụng các thuộc tính và phương thức: 

```php
	Person person; 
	person.firstName = "Khiem"; 
	person.lastName = "Le"; 
	person.fullname(); // sẽ in ra màn hình là "Khiem Le"	
```
### Access modifiers & properties declaration
Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.
- Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.

- Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị. 
-  Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

Ví dụ của access modifier:
```php
class MyClass { 
public: 
	int public_property; 
private: 
	int _private_property; 
	};
```
#### Method declaration
Phương thức cũng giống như một hàm bình thường

Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class. 
- Định nghĩa thi hành bên trong class:
```php
class Animal { 
public: 
	string sound; 
	void makeNoise() { 
		cout << sound;
		} 
};
```
- Định nghĩa thi hành bên ngoài class:
```php
class Animal { 
	public: 
		string sound; 
		void makeNoise(); 
}; 

void Animal::makeNoise() { 
	cout << sound; 
}
```
### Constructor
Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object.
```php
class Person { 
public: 
string firstName; 
string lastName; 
int age; 
Person(string _firstName, string _lastName, int _age) { 
firstName = _firstName; 
lastName = _lastName; 
age = _age; 
} 
void fullname() {
cout << firstName << ' ' << lastName; 
	} 
};
```
### Static member
Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. 

Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. 

Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. 

Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.

## Đặc tính của lập trình hướng đối tượng
- **Inheritance** (Tính kế thừa)trong lập trình hướng đối tượng có ý nghĩa, một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó. 
- Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong C++. 
```php
class  DoiTuong{
	public:
		void  setThongTin(string  name, int  age);
		void  hienThi();
	protected:
		int  AGE;
		string  NAME;
};
class  SinhVien : public  DoiTuong{
	public:
		void  setThongTin(string  name, int  age, int  mssv);
		void  hienThi();
	private:
		int  MSSV;
};
```
- **Abstraction** (Tính trừu tượng) trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. 
- Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class. 
- Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm. 
```php
class  PhuongTrinh{
	public:
		void  GetXY();
		void  NhapABC();
	private:
		int  X1;
		int  Y2;
		void  GetDelta();
};
```
- **Polymorphism** (Tính đa hình) trong lập trình hướng đối tượng là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý. 
- Ví dụ đơn giản, cùng là một class quản lý dữ liệu là các con vật, thì hành động sủa hay kêu của chúng được định nghĩa trong class sẽ cho ra kết quả khác nhau, ví dụ nếu là con mèo thì kêu meo meo, còn con chó thì sủa gâu gâu chẳng hạn. 
```php
class  ToanHoc{
	public:
		void  Tong(int  a, int  b);
		void  Tong(int  a, int  b, int  c);
		int  Tong(int  a, double  b);
};
```
- **Encapsulation** (Tính đóng gói) trong lập trình hướng đối tượng có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. 
- Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu. 
- Ví dụ đơn giản, khi bạn dùng một cái iphone, bạn không thể thay đổi các cấu trúc bên trong của hệ điều hành iOS, mà chỉ có Apple mới có thể làm được điều này thôi.
```php
class  PhuongTrinh{
	public:
		void  GetXY();
		void  NhapABC();
	private:
		int  A;
		int  B;
		int  C;
		int  X1;
		int  Y2;
		void  GetDelta();
};
```
## Namespace là gì? 
**Tình huống**: Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì vậy trình biên dịch chương trình sẽ báo lỗi. 
#### Định nghĩa: 
Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau. 
```php
namespace  ConOngA{
int  A = 10;
}

namespace  ConOngB{
int  A = 20;
}
```
#### Template trong C++ là gì? 
-  Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool... 

- Template trong C++ có 2 loại đó là function template & class template. 

- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau. 
```php
template<typename  var, typename  var>

var  Tong(var  a, var  b){
return (var)(a+b);
}
```
#### Hàm ảo (virtual function) là gì? 
- **Virtual function** là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần phải định nghĩa lại. 
- Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất. 
- Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ trợ bởi nguồn ngữ C++. 
- Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được. Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ. 
```php
class  Animal { 
	public: 
		virtual void makeSound() { 
			std::cout << "Animal makes a sound" << std::endl; 
	} 
}; 

class  Dog : public Animal { 
	public: 
		void makeSound() override { 
			std::cout << "Dog barks" << std::endl; 
	}
};
int main() { 
Animal* animalPtr; 
Dog dog; Cat cat; 
animalPtr = &dog; 
animalPtr->makeSound(); // Gọi hàm makeSound() của lớp Dog
```
#### Vector là gì? 
- Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector. 

- Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình 
```php
		vector<int> v;
```
**Modifiers**
1. **push_back():** Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu của vector thì sẽ bị ném ra. 
	```php
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		```

2.  pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
```php
		v.pop_back();
```
3. **assign():** Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
```php
	// Gán các giá trị từ mảng vào vector
	int values[] = {1, 2, 3, 4, 5}; 
	v.assign(values, values + 5);
	v.assign(3, 10); // Gán giá trị 10 cho 3 phần tử trong vector
```
4. **insert():** Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
```php
v.insert(v.begin() + 2, 10); // Chèn giá trị 10 vào vị trí thứ 2
v.insert(v.begin() + 4, values.begin(), values.end());
// Chèn dãy values vào vị trí thứ 4
```
5. **erase():** Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
```php
		v.erase(v.begin() + 2); // Xóa phần tử thứ 3
		v.erase(v.begin() + 1, v.begin() + 4); 
		// Xóa phần tử thứ 2 đến phần tử thứ 4
```
6. **emplace():** Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
```php
		v.emplace(v.begin(), 30);
```
7. **emplace_back():** Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
```php
		v.emplace_back(25);
```
8. **swap():** Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
```php
		vector<int> v = {1, 2, 3}; 
		vector<int> v1 = {4, 5, 6};
		v.swap(v1);
```
9. **clear():** Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector.
```php
		v.clear();
``` 
### for each
- C++ cung cấp một cấu trúc vòng lặp gọi là `range-based for loop` để duyệt qua các phần tử của một chuỗi (array, vector, set, list, string, v.v.)
```php
		for(int  x : v){//đọc data của v thông qua x
		cout  <<  x  <<  endl;
}
``` 
### auto
- Trong ngôn ngữ lập trình C++, từ khóa `auto` được sử dụng để khai báo một biến với kiểu dữ liệu được suy luận tự động từ giá trị khởi tạo.
```php
	auto number = 10;
	auto name = "John";
	
	for(auto  it = v.begin(); it  !=  v.end(); ++it){
		cout  <<  *it  <<  endl;
}
``` 
### list
- Trong ngôn ngữ lập trình C++, `std::list` là một lớp template trong thư viện chuẩn (STL) của C++ được sử dụng để biểu diễn danh sách liên kết kép (doubly linked list). Một danh sách liên kết kép cho phép chèn, xóa và truy cập phần tử ở cả hai đầu của danh sách một cách hiệu quả.
```php
	list<int> l = {, 2, 3, 4, 5, 6};
	l.push_back(7);
	l.push_front(1);
	l.insert(l.begin(), 8);
	l.pop_back();
	l.pop_front();
	l.erase(l.begin(), l.end());
	l.clear()
``` 
### map
- Một map là một tập hợp các cặp khóa-giá trị không trùng lặp, trong đó mỗi khóa chỉ được xuất hiện duy nhất và tương ứng với một giá trị.
```php
	std::map<string, int> m;
	m["Alice"] = 25;
	m["Bob"] = 30;
	m["Charlie"] = 35;
	m.insert(std::make_pair("David", 40));
	m.erase("Bob");
``` 
### linked list
- linked list (danh sách liên kết) là một cấu trúc dữ liệu được sử dụng để lưu trữ và quản lý một tập hợp các phần tử tuần tự trong bộ nhớ. Mỗi phần tử trong danh sách liên kết được gọi là nút (node) và chứa dữ liệu cùng với một con trỏ để liên kết với phần tử tiếp theo trong danh sách.
```php
	struct  Node
	{
		int  data;
		struct  Node *next;
	};
	
	Node  createNode(int  value){
		Node  temp;  
		temp = (Node)malloc(sizeof(struct  Node));
		temp  ->next = NULL;
		temp->data = value;
	return  temp;
}
``` 