#include <stdio.h>

void nhapSoNguyen(int* a, int* b, int* c)
{
	printf("Nhap so nguyen a: ");
	scanf_s("%d", a);
	printf("Nhap so nguyen b: ");
	scanf_s("%d", b);
	printf("Nhap so nguyen c: ");
	scanf_s("%d", c);
}

int kiemtraMau(int a, int b)
{
	if (a == b)
	{
		printf("Mau khong duoc bang 0\n");
		return 0;
	}
	return 1;
}

int main()
{
	int a, b, c;
	nhapSoNguyen(&a, &b, &c);
	if (kiemtraMau(a, b))
	{
		printf("\nPhuong trinh co nghiem la: %f", (float)(c) / (a - b));
	}
	return 0;
}