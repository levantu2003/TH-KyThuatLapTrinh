#include <stdio.h>

void nhapSoNguyen(int a, int b, int c)
{
    printf("Nhap so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf("%d", &b);
    printf("Nhap so nguyen c: ");
    scanf("%d", &c);
}
int kiemtraMau(int a, int b, int c)
{
    if (a == b)
    {
        printf("Mau khong duoc bang 0");
        return 0;
    }
    return 1;
}
int main()
{
    int a, b, c;
    nhapSoNguyen(a, b, c);
    if (kiemtraMau(a, b, c))
    {
        printf("\nPhuong trinh co nghiem la: %f", (float)(c) / (a - b));
    }
    return 0;
}
