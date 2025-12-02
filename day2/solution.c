#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct range range;

int numberOfRanges = 0; //global variable for tracking number of ranger in input

struct range {
    unsigned long long low;
    unsigned long long high;
};

void parseData(range* list) {
    char ch;
    unsigned long long number = 0;
    while((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9') {
            number = number*10 + ch - '0';
        } else if(ch == '-') {
            list[numberOfRanges].low = number;
            number = 0;
        } else if(ch == ',' || ch == '\n') {
            if (numberOfRanges > 0 && number == 0 && list[numberOfRanges].low == 0) continue;
            list[numberOfRanges].high = number;
            number = 0;
            numberOfRanges++;
        }
    }
}

int numberOfDigits(unsigned long long n) {
    if (n < 10) return 1;
    else return 1 + numberOfDigits(n/10);
}

unsigned long long solution(range* data) {
    unsigned long long r = 0;
    int k = 0;
    for (int i = 0; i < numberOfRanges; i++) {
        for (unsigned long long j = data[i].low; j <= data[i].high; j++) {
            int n = numberOfDigits(j);
            if (n % 2 == 1) continue;
            
            char str[n+2];
            sprintf(str, "%llu", j); 
            
            k = 0;
            while((int) (str[k] ^ str[(n/2)+k]) == 0) {
                k++;
                if(k == n/2) {
                    r += j;
                    break;
                }
            }
        }
    }
    return r;
}

int main() {
    range* data = calloc(1000000, sizeof(range));
    if (data == NULL) return 1;

    parseData(data);
    unsigned long long result = solution(data);
    printf("day1 = %llu\n", result);
    free(data);
    return 0;
}