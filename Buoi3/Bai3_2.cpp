#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void taoMaTranVuong(int a[][MAX], int n);
void xuatMaTran(int a[][MAX], int n);
void xuatDuongCheoChinh(int a[][MAX], int n);
void xuatDuongCheoSongSong(int a[][MAX], int n);
int timMaxTamGiacTren(int a[][MAX], int n);
void sapXepZicZac(int a[][MAX], int n);
void sapXepDuongCheoChinh(int a[][MAX], int n);
void menu();

int main()
{
    int choice;
    int a[MAX][MAX];
    int n = 0;
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
            do
            {
                printf("\nNhap cap cua ma tran vuong (n >= 2 va n <= %d): ", MAX);
                scanf("%d", &n);
            } while (n < 2 || n > MAX);
            taoMaTranVuong(a, n);
            xuatMaTran(a, n);
            daKhoiTao = 1;
            break;
        case 2:
            if (!daKhoiTao)
            {
                printf("\nMa tran chua duoc khoi tao!");
            }
            else
            {
                xuatDuongCheoChinh(a, n);
            }
            break;
        case 3:
            if (!daKhoiTao)
            {
                printf("\nMa tran chua duoc khoi tao!");
            }
            else
            {
                xuatDuongCheoSongSong(a, n);
            }
            break;
        case 4:
            if (!daKhoiTao)
            {
                printf("\nMa tran chua duoc khoi tao!");
            }
            else
            {
                int max = timMaxTamGiacTren(a, n);
                printf("\nPhan tu max thuoc tam giac tren cua duong cheo chinh: %d", max);
            }
            break;
        case 5:
            if (!daKhoiTao)
            {
                printf("\nMa tran chua duoc khoi tao!");
            }
            else
            {
                sapXepZicZac(a, n);
                printf("\nMa tran sau khi sap xep zic-zac:\n");
                xuatMaTran(a, n);
            }
            break;
        case 6:
            if (!daKhoiTao)
            {
                printf("\nMa tran chua duoc khoi tao!");
            }
            else
            {
                sapXepDuongCheoChinh(a, n);
                printf("\nMa tran sau khi sap xep duong cheo chinh:\n");
                xuatMaTran(a, n);
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
    printf("\n1. Tao va xuat ma tran vuong");
    printf("\n2. Xuat cac phan tu tren duong cheo chinh");
    printf("\n3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh");
    printf("\n4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh");
    printf("\n5. Sap xep ma tran tang dan theo kieu zic-zac");
    printf("\n6. Sap xep duong cheo chinh tang dan tu tren xuong duoi");
    printf("\n0. Thoat\n");
}

void taoMaTranVuong(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100; // Số ngẫu nhiên từ 0 đến 99
        }
    }
}

void xuatMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(int a[][MAX], int n)
{
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

void xuatDuongCheoSongSong(int a[][MAX], int n)
{
    printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
    for (int k = 1; k < n; k++)
    {
        printf("Duong cheo thu %d ben tren: ", k);
        for (int i = 0; i < n - k; i++)
        {
            printf("%d ", a[i][i + k]);
        }
        printf("\n");

        printf("Duong cheo thu %d ben duoi: ", k);
        for (int i = k; i < n; i++)
        {
            printf("%d ", a[i][i - k]);
        }
        printf("\n");
    }
}

int timMaxTamGiacTren(int a[][MAX], int n)
{
    int max = a[0][1];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
    return max;
}

void sapXepZicZac(int a[][MAX], int n)
{
    int temp[MAX * MAX];
    int index = 0;

    // Chuyển ma trận 2D thành mảng 1D
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng 1D
    for (int i = 0; i < n * n - 1; i++)
    {
        for (int j = i + 1; j < n * n; j++)
        {
            if (temp[i] > temp[j])
            {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Chuyển lại thành ma trận 2D theo kiểu zic-zac
    index = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = temp[index++];
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                a[i][j] = temp[index++];
            }
        }
    }
}

void sapXepDuongCheoChinh(int a[][MAX], int n)
{
    int temp[MAX];

    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i][i] = temp[i];
    }
}
