#include <stdio.h>
#include <stdlib.h>

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

void nhapPhanso(Phanso *ps)
{
    do
    {
        printf("Nhap tu so: ");
        scanf("%d", &ps->Tu);
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->Mau);
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

void nhapMangPhanso(Phanso **a, int n)
{
    *a = (Phanso *)malloc(n * sizeof(Phanso));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanso(&(*a)[i]);
    }
}

void xuatMangPhanso(Phanso *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Phan so thu %d: ", i + 1);
        xuatPhanso(a[i]);
        printf("\n");
    }
}

void xuatPhansoMauLonHonTu(Phanso *a, int n)
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

int demPhansoTuMauChan(Phanso *a, int n)
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

void rutGonPhanso(Phanso *ps)
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

Phanso tinhTichMangPhanso(Phanso *a, int n)
{
    Phanso tich = {1, 1};
    for (int i = 0; i < n; i++)
    {
        tich.Tu *= a[i].Tu;
        tich.Mau *= a[i].Mau;
        rutGonPhanso(&tich);
    }
    return tich;
}

Phanso timPhansoLonNhat(Phanso *a, int n)
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

Phanso timPhansoNhoNhat(Phanso *a, int n)
{
    Phanso min = a[0];
    for (int i = 1; i < n; i++)
    {
        if ((double)a[i].Tu / a[i].Mau < (double)min.Tu / min.Mau)
        {
            min = a[i];
        }
    }
    return min;
}

void xoaPhanTuTaiViTriK(Phanso **a, int *n, int k)
{
    if (k < 0 || k >= *n)
    {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    for (int i = k; i < *n - 1; i++)
    {
        (*a)[i] = (*a)[i + 1];
    }
    *n = *n - 1;
    *a = (Phanso *)realloc(*a, *n * sizeof(Phanso));
}

void themPhanTuTaiViTriK(Phanso **a, int *n, Phanso x, int k)
{
    if (k < 0 || k > *n)
    {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    *n = *n + 1;
    *a = (Phanso *)realloc(*a, *n * sizeof(Phanso));
    for (int i = *n - 1; i > k; i--)
    {
        (*a)[i] = (*a)[i - 1];
    }
    (*a)[k] = x;
}

int main()
{
    Phanso *a;
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    nhapMangPhanso(&a, n);
    printf("\nMang phan so vua nhap:\n");
    xuatMangPhanso(a, n);
    
    Phanso max = timPhansoLonNhat(a, n);
    printf("\nPhan so lon nhat trong mang: ");
    xuatPhanso(max);
    
    Phanso min = timPhansoNhoNhat(a, n);
    printf("\nPhan so nho nhat trong mang: ");
    xuatPhanso(min);
    
    int k;
    printf("\nNhap vi tri k can xoa: ");
    scanf("%d", &k);
    xoaPhanTuTaiViTriK(&a, &n, k);
    printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
    xuatMangPhanso(a, n);
    
    Phanso x;
    printf("\nNhap phan so can them:\n");
    nhapPhanso(&x);
    printf("Nhap vi tri k can them: ");
    scanf("%d", &k);
    themPhanTuTaiViTriK(&a, &n, x, k);
    printf("Mang sau khi them phan so tai vi tri %d:\n", k);
    xuatMangPhanso(a, n);
    
    free(a);
    return 0;
}
