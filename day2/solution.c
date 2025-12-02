#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct range range;

int numberOfRanges = 0; //global variable to track how many ranges we have;

struct range {
    int low;
    int high;
};

void parseData(range* list) {
    char ch;
    int number = 0;
    while((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9') {
            number = number*10 + ch - '0';
        } else if(ch == '-') {
            list[numberOfRanges].low = number;
            number = 0;
        } else if(ch == ',' || ch == '\n') {
            list[numberOfRanges].high = number;
            number = 0;
            numberOfRanges++;
        }
    }
}

int numberOfDigits(int n) {
    if(n < 0) numberOfDigits(-n);
    else if (n < 10) return 1;
    else return 1 + numberOfDigits(n/10);
}

// char* addition(char* r, int n) {
//     int digits = numberOfDigits(n);
//     char* tmp[digits+1];
//     sprintf(tmp, "%d", n);
//     int carry = 0;
//     for (int i = digits-1; i >= 0; i--) {
//         int number = r[i]-'0' + tmp[i]-'0';
//     } 
//     return r;
// }

unsigned long long solution(range* data) {
    unsigned long long r = 0;
    int k = 0;
    int overflows = 0;
    for (int i = 0; i < numberOfRanges; i++) {
        for (int j = data[i].low; j <= data[i].high; j++) {
            int n = numberOfDigits(j);
            if (n % 2 == 1) continue;
            char str[n+2];
            sprintf(str, "%d", j);
            while((int) (str[k] ^ str[(n/2)+k]) == 0) {
                k++;
                // printf("str[k] = %c and str[(n/2)+k] = %c\n", str[k], str[(n/2)+k]);
                if(k == n/2) {
                    printf("j is %s\n", str);
                    r+=j;
                    if (r <= j) overflows++;
                    break;
                }
            }
            k = 0;
            //do and (&) operation for first and half+1 element in j 
            //check if 1 until half. If zero then go to next
            //if 1 all the way, r++;
        }
    }
    return r;
}

int main() {
    range* data = calloc(100000, sizeof(range));
    parseData(data);
    unsigned long long day1 = solution(data);
    printf("day1 = %llu\n", day1);
    free(data);
    return 0;
}