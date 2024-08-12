// https://omegaup.com/arena/problem/Lectura-y-escritura-de-datos/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int ia = *(int *)a, ib = *(int *)b;
    if (ia % 2 == 0 && ib % 2 == 0) return ia - ib;
    if (ia % 2 == 1 && ib % 2 == 1) return ib - ia;
    if (ia % 2 == 0) return -1;
    return 1;
}

int main() {
    char e, s;
    scanf("%c%c", &e, &s);
    getchar();

    int *nums = NULL;
    int len = 0, capacity = 0;

    if (e == 'T') {
        int x;
        while (scanf("%d", &x) == 1) {
            if (len == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                nums = realloc(nums, capacity * sizeof(int));
            }
            nums[len++] = x;
        }
    } else {
        int x;
        while (fread(&x, sizeof(int), 1, stdin) == 1) {
            if (len == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                nums = realloc(nums, capacity * sizeof(int));
            }
            nums[len++] = x;
        }
    }

    qsort(nums, len, sizeof(int), cmp);

    if (s == 'T') {
        for (int i = 0; i < len; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < len; i++) {
            fwrite(&nums[i], sizeof(int), 1, stdout);
        }
    }

    free(nums);
    return 0;
}
