#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void chiaMang(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Khong the chia cho 0 tai vi tri %d\n", i);
        } else {
            float ketqua = (float)a[i] / b[i];
            printf("a[%d] / b[%d] = %.2f\n", i, i, ketqua);
        }
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    printf("Nhap mang a:\n");
    nhapMang(a, n);

    printf("Nhap mang b:\n");
    nhapMang(b, n);

    printf("Ket qua phep chia:\n");
    chiaMang(a, b, n);

    free(a);
    free(b);

    return 0;
}
