#include <stdio.h>

int main()
{
    float a, b;
    printf("Nhap a va b: ");
    scanf("%f%f", &a, &b);
    float *pa = &a;
    float *pb = &b;
    printf("\nDia chi cua a: %x", pa);
    printf("\nDia chi cua b: %x", pb);
    return 0;
}
