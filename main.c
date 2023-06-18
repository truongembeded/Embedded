#include<stdio.h>

void reverseString(char *arr, int start, int end){
    while (start < end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
}

void reverseWords(char *arr){
    int length = 0;
    while (arr[length] != '\0' )
    {
        length++;
    }
    reverseString(arr, 0, length - 1);

    int left = 0;
    int right = 0;
    while (arr[right] != '\0' )
    {
        if (arr[right] == ' ')
        {
            reverseString(arr, left, right - 1);
            left = right + 1;

        }
        right++;
    }
    reverseString(arr, left, right - 1);
    
}

int main(int argc, char const *argv[])
{
    char arr[] = " tinh anh nhu nuoc con song dai";
    reverseWords(arr);
    printf("%s", arr);
    return 0;
}
