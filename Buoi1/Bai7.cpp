#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapM1C_SoNguyen(int*& a, int& n)
{
	n = 10;
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		if (a != NULL) {
			*(a + i) = rand() % 100;
		}
	}
}
void xuatM1C_SoNguyen(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (void*)(a + i));
	}
}

void timPhanTuLonNhat(int* a, int n)
{
	int* max = a;
	for (int i = 1; i < n; i++)
	{
		if (*(a + i) > *max)
		{
			max = a + i;
		}
	}
	printf("\nPhan tu lon nhat la %d tai dia chi %x", *max, max);
}

void timPhanTuChanLonNhatLeNhoNhat(int* a, int n)
{
	int* maxChan = NULL, * minLe = NULL;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 2 == 0)
		{
			if (maxChan == NULL || *(a + i) > *maxChan)
			{
				maxChan = a + i;
			}
		}
		else
		{
			if (minLe == NULL || *(a + i) < *minLe)
			{
				minLe = a + i;
			}
		}
	}
	if (maxChan != NULL)
	{
		printf("\nDia chi phan tu chan lon nhat: %x", maxChan);
	}
	else
	{
		printf("\nKhong co phan tu chan trong mang.");
	}
	if (minLe != NULL)
	{
		printf("\nDia chi phan tu le nho nhat: %x", minLe);
	}
	else
	{
		printf("\nKhong co phan tu le trong mang.");
	}
}

void xoaPhanTuGiaTri0(int*& a, int& n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) != 0)
		{
			*(a + count) = *(a + i);
			count++;
		}
	}
	n = count;
	a = (int*)realloc(a, n * sizeof(int));

	printf("\nMang sau khi xoa phan tu gia tri 0:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", *(a + i));
	}
}

void themPhanTuDau(int*& a, int& n, int x)
{
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for (int i = n - 1; i > 0; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	*a = x;

	printf("\nMang sau khi them phan tu 99 vao dau:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", *(a + i));
	}
}

int tongSoChinhPhuong(int* a, int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		int canBacHai = (int)sqrt(*(a + i));
		if (canBacHai * canBacHai == *(a + i))
		{
			tong += *(a + i);
		}
	}
	return tong;
}

void timSoCucDai(int* a, int n)
{
	printf("\nCac so cuc dai trong mang:");
	for (int i = 1; i < n - 1; i++)
	{
		if (*(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1))
		{
			printf(" %d", *(a + i));
		}
	}
}

int main()
{
	int* a, n = 10;
	nhapM1C_SoNguyen(a, n);
	timPhanTuLonNhat(a, n);
	timPhanTuChanLonNhatLeNhoNhat(a, n);
	xoaPhanTuGiaTri0(a, n);
	themPhanTuDau(a, n, 99);
	printf("\nTong cac so chinh phuong: %d", tongSoChinhPhuong(a, n));
	timSoCucDai(a, n);
	free(a);
	return 0;
}
