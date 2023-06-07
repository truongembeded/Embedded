#include <stdio.h>

#define MAX 100

char words[MAX][50];
int count[MAX] = {0}; 
int wordCount = 0; 
int lenght = 0; 


int isEqual(const char word1[], const char word2[]) {
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0') {
        if (word1[i] != word2[i]) {
            return 0;
        }
        i++;
    }
    return word1[i] == '\0' && word2[i] == '\0';
}

void splitwords(const char str[]) {
    
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?' && str[i] != '!') {
            words[wordCount][lenght] = str[i];
            lenght++;
        } else {
            if (lenght > 0) {
                words[wordCount][lenght] = '\0';
                wordCount++;
                lenght = 0;
            }
        }
        i++;
    }
        if (lenght > 0) {
        words[wordCount][lenght] = '\0';
        wordCount++;
    }

}

void countword(){

    for (int i = 0; i < wordCount; i++) {
        if (count[i] == -1) {
            continue; 
        }

        count[i] = 1;

        for (int j = i + 1; j < wordCount; j++) {
            if (count[j] != -1 && isEqual(words[i], words[j])) {
                
                count[i]++; // Tăng số lần xuất hiện của từ
                count[j] = -1; // Đánh dấu từ này đã được đếm
            }
        }
    }
}
void printword(){
    for (int i = 0; i < wordCount; i++) {
        if (count[i] != -1) {
            printf("Tu '%s' xuat hien %d lan\n", words[i], count[i]);
        }
    }
}

int main() {
    char str[] = "mot hai?mot,bon nam,mot hai!sau,sau.sau hoc?hoc hoc!hanh.hanh";
    splitwords(str);
    countword();
    printword();
    return 0;
}



