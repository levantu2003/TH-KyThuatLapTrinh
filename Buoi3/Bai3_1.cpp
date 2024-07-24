#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void taoMang2C(int a[][MAX], int m, int n);
void xuatMang2C(int a[][MAX], int m, int n);
void tinhTongTungDong(int a[][MAX], int m, int n);
void timMaxTungCot(int a[][MAX], int m, int n);
void xuatPhanTuBien(int a[][MAX], int m, int n);
void xuatPhanTuCucDai(int a[][MAX], int m, int n);
void xuatPhanTuHoangHau(int a[][MAX], int m, int n);
void xuatDiemYenNgua(int a[][MAX], int m, int n);
void xuatDongChuaSoChan(int a[][MAX], int m, int n);
void sapXepTangTheoDong(int a[][MAX], int m, int n);
void menu();

int main()
{
    int choice;
    int a[MAX][MAX];
    int m = 0, n = 0;
    int daKhoiTao = 0;

    srand(time(NULL));

    do
    {
        menu();
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nNhap so hang m (toi da %d): ", MAX);
            scanf("%d", &m);
            printf("\nNhap so cot n (toi da %d): ", MAX);
            scanf("%d", &n);
            if (m > MAX || n > MAX || m <= 0 || n <= 0)
            {
                printf("\nKich thuoc khong hop le!");
                break;
            }
            taoMang2C(a, m, n);
            daKhoiTao = 1;
            break;
        case 2:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatMang2C(a, m, n);
            }
            break;
        case 3:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                tinhTongTungDong(a, m, n);
            }
            break;
        case 4:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                timMaxTungCot(a, m, n);
            }
            break;
        case 5:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatPhanTuBien(a, m, n);
            }
            break;
        case 6:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatPhanTuCucDai(a, m, n);
            }
            break;
        case 7:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatPhanTuHoangHau(a, m, n);
            }
            break;
        case 8:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatDiemYenNgua(a, m, n);
            }
            break;
        case 9:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatDongChuaSoChan(a, m, n);
            }
            break;
        case 10:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                sapXepTangTheoDong(a, m, n);
                printf("\nMang sau khi sap xep:\n");
                xuatMang2C(a, m, n);
            }
            break;
        case 0:
            printf("\nThoat chuong trinh.");
            break;
        default:
            printf("\nLua chon khong hop le. Vui long chon lai");
        }
    } while (choice != 0);

    return 0;
}

void menu()
{
    printf("\n---- MENU ----");
    printf("\n1. Tao mang 2 chieu");
    printf("\n2. Xuat mang 2 chieu");
    printf("\n3. Tinh tong gia tri tung dong");
    printf("\n4. Tim phan tu lon nhat tren tung cot");
    printf("\n5. Xuat cac phan tu thuoc duong bien");
    printf("\n6. Xuat cac phan tu cuc dai");
    printf("\n7. Xuat cac phan tu hoang hau");
    printf("\n8. Xuat cac phan tu la diem yen ngua");
    printf("\n9. Xuat dong chi chua so chan");
    printf("\n10. Sap xep mang tang theo tung dong");
    printf("\n0. Thoat\n");
}

void taoMang2C(int a[][MAX], int m, int n)
{
    int chon, k, A, B;
    printf("\nChon cach tao ma tran: ");
    printf("\n1. Lay so ngau nhien tu 0 toi k");
    printf("\n2. Lay so ngau nhien tu a toi b");
    printf("\nNhap so (1 hoac 2): ");
    scanf("%d", &chon);
    switch (chon)
    {
    case 1:
        printf("\nNhap so k: ");
        scanf("%d", &k);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = rand() % (k + 1);
            }
        }
        break;
    case 2:
        printf("\nNhap a: ");
        scanf("%d", &A);
        printf("\nNhap b: ");
        scanf("%d", &B);
        if (A > B)
        {
            int temp = A;
            A = B;
            B = temp;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = A + rand() % (B - A + 1);
            }
        }
        break;
    default:
        printf("Chi chon 1 hoac 2!");
        break;
    }
}

void xuatMang2C(int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTongTungDong(int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("Tong dong %d: %d\n", i + 1, sum);
    }
}

void timMaxTungCot(int a[][MAX], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int max = a[0][j];
        for (int i = 1; i < m; i++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        printf("Max cot %d: %d\n", j + 1, max);
    }
}

void xuatPhanTuBien(int a[][MAX], int m, int n)
{
    printf("Cac phan tu bien:\n");
    for (int j = 0; j < n; j++)
        printf("%d ", a[0][j]); // Biên trên
    for (int i = 1; i < m - 1; i++)
        printf("%d ", a[i][n - 1]); // Biên phải
    if (m > 1)
    {
        for (int j = n - 1; j >= 0; j--)
            printf("%d ", a[m - 1][j]); // Biên dưới
    }
    for (int i = m - 2; i > 0; i--)
        printf("%d ", a[i][0]); // Biên trái
    printf("\n");
}

void xuatPhanTuCucDai(int a[][MAX], int m, int n)
{
    printf("Cac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int isCucDai = 1;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j])
                    {
                        isCucDai = 0;
                        break;
                    }
                }
                if (!isCucDai) break;
            }
            if (isCucDai) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatPhanTuHoangHau(int a[][MAX], int m, int n)
{
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int isHoangHau = 1;
            for (int k = 0; k < n; k++)
                if (a[i][k] > a[i][j])
                {
                    isHoangHau = 0;
                    break;
                }
            for (int k = 0; k < m; k++)
                if (a[k][j] > a[i][j])
                {
                    isHoangHau = 0;
                    break;
                }
            if (isHoangHau) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatDiemYenNgua(int a[][MAX], int m, int n)
{
    printf("Cac diem yen ngua:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int minRow = a[i][0], maxCol = a[0][j];
            for (int k = 1; k < n; k++)
                if (a[i][k] < minRow) minRow = a[i][k];
            for (int k = 1; k < m; k++)
                if (a[k][j] > maxCol) maxCol = a[k][j];
            if (a[i][j] == minRow && a[i][j] == maxCol)
                printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatDongChuaSoChan(int a[][MAX], int m, int n)
{
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++)
    {
        int allEven = 1;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                allEven = 0;
                break;
            }
        }
        if (allEven)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}

void sapXepTangTheoDong(int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i][j] > a[i][k])
                {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}
