#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a = 0, b = 0;
	printf("Nhap a va b: ");
	scanf_s("%d%d", &a, &b);

	try {
		if (b == 0)
		{
			throw "Loi chia cho 0";
		}
		else
		{
			int phanso = a / b;
			printf("Ket qua phan so: %d", phanso);
		}
	}
	catch (const char* msg)
	{
		printf("Loi: %s", msg);
	}
	return 0;
}
