#include<iostream>

class PhuongTrinh{
    public:
        void GetXY();
        void NhapABC();
    private:
        int A;
        int B;
        int C;
        int X1;
        int Y2;
        void GetDelta();
};// ví dụ về tính trừu tượng và tính đóng gói

namespace ConOngA{
    int A = 10;
    class ILoveYou{
        public:
            void Love();
        private:
            int i;
};
}

namespace ConOngB{
    int A = 20;
}

using namespace ConOngA;

int main(int argc, char const *argv[])
{
    printf("A %d\n", A);
    printf("A %d\n", ConOngB:: A);
    ConOngA::ILoveYou Q;
    return 0;
}
