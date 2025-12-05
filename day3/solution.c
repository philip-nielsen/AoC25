#include <stdlib.h>
#include <stdio.h>

int numberOfNumbers = 0;
int sizeOfNumber = 0;

void parseData(int** data) {
    char ch;
    int j = 0;
    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9') {
            data[numberOfNumbers][j] =  ch - '0';
            j++;
        } else if(ch == '\n') {
            sizeOfNumber = j;
            j=0;
            numberOfNumbers++;
        }
    }
}

int day1(int **data) {
    int r = 0;
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < numberOfNumbers; i++) {
        int n1 = data[i][0];
        int n2 = data[i][1];
        for(int j = 1; j < sizeOfNumber; j++) {
            int tmp = data[i][j];
            if (tmp > n1 && j == sizeOfNumber-1) {
                n2 = tmp;
            } else if(tmp > n1) {
                n2 = 0;
                n1 = tmp;
            } else if(tmp > n2) {
                n2 = tmp;
            }
        }
        // printf("n1 = %d, n2 = %d\n",n1,n2); 
        r += n1*10 + n2;
    }
    return r;
}

int findLowestIndex(int* array) {
    int index = 0;
    return index;
}

unsigned long long day2(int **data) {
    unsigned long long r = 0;
    int cnt = 0;
    int lowestValue = 0;
    int lowestValueIndex = 0;
    for (int i = 0; i < numberOfNumbers; i++) {
        int n1 = data[i][0];
        int n2 = data[i][1];
        int* numArray = calloc(sizeOfNumber, sizeof(int));
        numArray[0] = n1;
        numArray[1] = n2;
        for(int j = 2; j < sizeOfNumber; j++) {
            int tmp = data[i][j];
        }
        // printf("n1 = %d, n2 = %d\n",n1,n2); 
        r += n1*10 + n2;
    }
    return r;
}

int main() {
    int** data = calloc(200,sizeof(int*));
    for (int i = 0; i < 200; i++) {
        data[i] = calloc(200,sizeof(int));
    }

    parseData(data);
    printf("day1 = %d\n",day1(data));
    printf("numberOfnumbers = %d\n", numberOfNumbers);
    printf("numberOfdigits = %d\n", sizeOfNumber);
}