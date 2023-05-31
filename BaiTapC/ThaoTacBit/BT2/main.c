#include <stdio.h>

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;//lưu độ dài chuỗi
    }

    reverseString(str, 0, length - 1);

    int left = 0;
    int right = 0;
    while (str[right] != '\0') {
        if (str[right] == ' ') {
            reverseString(str, left, right - 1);
            left = right + 1;
        }
        right++;
    }
    reverseString(str, left, right - 1);
}

int main() {
    char str[] = "dai song con nuoc nhu anh tinh";

    reverseWords(str);

    printf(" %s\n", str);

    return 0;
}

