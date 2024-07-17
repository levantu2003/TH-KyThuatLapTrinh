#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct
{
	int Tu;
	int Mau;
} Phanso;

int timUCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void nhapPhanso(Phanso* ps)
{
	do
	{
		printf("Nhap tu so: ");
		scanf_s("%d", &ps->Tu);
		printf("Nhap mau so (khac 0): ");
		scanf_s("%d", &ps->Mau);
		if (ps->Mau == 0)
		{
			printf("Loi: Mau so khong the bang 0. Vui long nhap lai.\n");
		}
	} while (ps->Mau == 0);
}

void xuatPhanso(Phanso ps)
{
	printf("%d/%d", ps.Tu, ps.Mau);
}

void nhapMangPhanso(Phanso** a, int n)
{
	*a = (Phanso*)malloc(n * sizeof(Phanso));
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan so thu %d:\n", i + 1);
		nhapPhanso(&(*a)[i]);
	}
}

void xuatMangPhanso(Phanso* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Phan so thu %d: ", i + 1);
		xuatPhanso(a[i]);
		printf("\n");
	}
}

void xuatPhansoMauLonHonTu(Phanso* a, int n)
{
	printf("Cac phan so co mau > tu:\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].Mau > a[i].Tu)
		{
			xuatPhanso(a[i]);
			printf("\n");
		}
	}
}

int demPhansoTuMauChan(Phanso* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].Tu % 2 == 0 && a[i].Mau % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

void rutGonPhanso(Phanso* ps)
{
	int ucln = timUCLN(ps->Tu, ps->Mau);
	ps->Tu /= ucln;
	ps->Mau /= ucln;
	if (ps->Mau < 0)
	{
		ps->Tu = -ps->Tu;
		ps->Mau = -ps->Mau;
	}
}

Phanso tinhTichMangPhanso(Phanso* a, int n)
{
	Phanso tich = { 1, 1 };
	for (int i = 0; i < n; i++)
	{
		tich.Tu *= a[i].Tu;
		tich.Mau *= a[i].Mau;
		rutGonPhanso(&tich);
	}
	return tich;
}

Phanso timPhansoLonNhat(Phanso* a, int n)
{
	Phanso max = a[0];
	for (int i = 1; i < n; i++)
	{
		if ((double)a[i].Tu / a[i].Mau > (double)max.Tu / max.Mau)
		{
			max = a[i];
		}
	}
	return max;
}

int main()
{
	Phanso* a;
	int n;

	printf("Nhap so luong phan so: ");
	scanf_s("%d", &n);

	nhapMangPhanso(&a, n);

	printf("\nMang phan so vua nhap:");
	xuatMangPhanso(a, n);

	xuatPhansoMauLonHonTu(a, n);

	printf("\nSo phan so co tu va mau deu chan: %d", demPhansoTuMauChan(a, n));

	printf("\nMang phan so sau khi rut gon:");
	for (int i = 0; i < n; i++)
	{
		rutGonPhanso(&a[i]);
	}
	xuatMangPhanso(a, n);

	Phanso tich = tinhTichMangPhanso(a, n);
	printf("\nTich cac phan so trong mang: ");
	xuatPhanso(tich);

	Phanso max = timPhansoLonNhat(a, n);
	printf("\nPhan so lon nhat trong mang: ");
	xuatPhanso(max);

	free(a);
	return 0;
}