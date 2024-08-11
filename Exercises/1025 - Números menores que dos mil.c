// https://omegaup.com/arena/problem/nmd/#problems

#include <stdio.h>
#include <string.h>

int countPartsFromStart(char *s) {
    int count = 0;
    int length = strlen(s);
    for (int i = 0; i < length;) {
        int num = 0;
        while (i < length && num * 10 + (s[i] - '0') < 2000) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        count++;
    }
    return count;
}

int countPartsFromEnd(char *s) {
    int count = 0;
    int length = strlen(s);
    for (int i = length - 1; i >= 0;) {
        int num = 0;
        int multiplier = 1;
        while (i >= 0 && num + (s[i] - '0') * multiplier < 2000) {
            num += (s[i] - '0') * multiplier;
            multiplier *= 10;
            i--;
        }
        count++;
    }
    return count;
}

int main() {
    char s[1001];
    scanf("%s", s);
    
    int p = countPartsFromStart(s);
    int f = countPartsFromEnd(s);
    
    printf("%d %d\n", p, f);
    
    return 0;
}
