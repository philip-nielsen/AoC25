#include <stdlib.h>
#include <stdio.h>

int numberOfNumbers = 0;

void parseData(int* data) {
    char ch;
    int number = 0;
    int j = 0;
    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9') {
            number = number * 10 + ch - '0';
            j++;
        } else if(ch == '\n') {
            data[numberOfNumbers] = number;
            j=0;
            number = 0;
            numberOfNumbers++;
        }
    }
}

int numberOfDigits(int n) {
    if (n < 10) return 1;
    else return 1 + numberOfDigits(n/10);
}

int day1(int*data) {
    int r = 0;
    int n1 = 0;
    int n2 = 0;
    int digits = 0;
    for (int i = 0; i < numberOfNumbers; i++) {
        digits = numberOfDigits(data[i]);
        char str[digits + 2];
        sprintf(str, "%llu", data[i]);
        int n1 = str[0] - '0';
        int n2 = str[1] - '0';
        for(int j = 0; j < digits-1; j++) {
            int tmp = str[j] - '0';
            if(tmp > n1) {
                n2 = n1;
                n1 = tmp;
            } else if(tmp > n2) {
                n2 = tmp;
            }
        }
    }

    return r;
}

int main() {
    int* data = calloc(1000,sizeof(int*));
    parseData(data);
}