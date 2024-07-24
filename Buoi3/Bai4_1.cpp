#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MAX 10

void taoMang2C(int a[][MAX], int m, int n);
void xuatMang2C(int a[][MAX], int m, int n);
void xuatCotChuaSoLe(int a[][MAX], int m, int n);
int timMaxBien(int a[][MAX], int m, int n);
int demPhanTuCoChuSo2(int a[][MAX], int m, int n);
void xuatPhanTuCucTieu(int a[][MAX], int m, int n);
void sapXepDongChanLeDongsLe(int a[][MAX], int m, int n);
void sapXepCotChanLeCot(int a[][MAX], int m, int n);
int kiemTraGiamDanZicZac(int a[][MAX], int m, int n);
void lietKeDongChuaToanChan(int a[][MAX], int m, int n);
void lietKeDongGiamDan(int a[][MAX], int m, int n);
int timGiaTriXuatHienNhieuNhat(int a[][MAX], int m, int n);
void timChuSoXuatHienNhieuNhat(int a[][MAX], int m, int n);
void lietKeCotTongNhoNhat(int a[][MAX], int m, int n);
void hoanViHaiCot(int a[][MAX], int m, int n, int i, int j);
void hoanViHaiDong(int a[][MAX], int m, int n, int k, int l);

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
                xuatCotChuaSoLe(a, m, n);
            }
            break;
        case 4:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                printf("\nPhan tu lon nhat tren bien: %d", timMaxBien(a, m, n));
            }
            break;
        case 5:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                printf("\nSo phan tu co chu so 2: %d", demPhanTuCoChuSo2(a, m, n));
            }
            break;
        case 6:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                xuatPhanTuCucTieu(a, m, n);
            }
            break;
        case 7:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                sapXepDongChanLeDongsLe(a, m, n);
                printf("\nMa tran sau khi sap xep:\n");
                xuatMang2C(a, m, n);
            }
            break;
        case 8:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                sapXepCotChanLeCot(a, m, n);
                printf("\nMa tran sau khi sap xep:\n");
                xuatMang2C(a, m, n);
            }
            break;
        case 9:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                if (kiemTraGiamDanZicZac(a, m, n))
                {
                    printf("\nMa tran giam dan theo cot va dong (ziczac)");
                }
                else
                {
                    printf("\nMa tran khong giam dan theo cot va dong (ziczac)");
                }
            }
            break;
        case 10:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                lietKeDongChuaToanChan(a, m, n);
            }
            break;
        case 11:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                lietKeDongGiamDan(a, m, n);
            }
            break;
        case 12:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                printf("\nGia tri xuat hien nhieu nhat: %d", timGiaTriXuatHienNhieuNhat(a, m, n));
            }
            break;
        case 13:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                timChuSoXuatHienNhieuNhat(a, m, n);
            }
            break;
        case 14:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                lietKeCotTongNhoNhat(a, m, n);
            }
            break;
        case 15:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                int i, j;
                printf("\nNhap cot i: ");
                scanf("%d", &i);
                printf("\nNhap cot j: ");
                scanf("%d", &j);
                hoanViHaiCot(a, m, n, i, j);
                printf("\nMa tran sau khi hoan vi:\n");
                xuatMang2C(a, m, n);
            }
            break;
        case 16:
            if (!daKhoiTao)
            {
                printf("\nMang chua duoc khoi tao!");
            }
            else
            {
                int k, l;
                printf("\nNhap dong k: ");
                scanf("%d", &k);
                printf("\nNhap dong l: ");
                scanf("%d", &l);
                hoanViHaiDong(a, m, n, k, l);
                printf("\nMa tran sau khi hoan vi:\n");
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
    printf("\n3. Xuat cac cot chi chua so le");
    printf("\n4. Tim phan tu lon nhat tren bien");
    printf("\n5. Dem phan tu co chu so 2");
    printf("\n6. Xuat phan tu cuc tieu");
    printf("\n7. Sap xep dong chan le");
    printf("\n8. Sap xep cot chan le");
    printf("\n9. Kiem tra giam dan ziczac");
    printf("\n10. Liet ke dong chua toan chan");
    printf("\n11. Liet ke dong giam dan");
    printf("\n12. Tim gia tri xuat hien nhieu nhat");
    printf("\n13. Tim chu so xuat hien nhieu nhat");
    printf("\n14. Liet ke cot tong nho nhat");
    printf("\n15. Hoan vi hai cot");
    printf("\n16. Hoan vi hai dong");
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

void xuatCotChuaSoLe(int a[][MAX], int m, int n)
{
    printf("\nCac cot chi chua so le:\n");
    int coKetQua = 0;
    for (int j = 0; j < n; j++)
    {
        int chuaLe = 1;
        for (int i = 0; i < m; i++)
        {
            if (a[i][j] % 2 == 0)
            {
                chuaLe = 0;
                break;
            }
        }
        if (chuaLe)
        {
            coKetQua = 1;
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    if (!coKetQua)
    {
        printf("Khong co cot nao chi chua so le.\n");
    }
}

int timMaxBien(int a[][MAX], int m, int n)
{
    int max = a[0][0];
    for (int j = 0; j < n; j++)
    {
        if (a[0][j] > max)
            max = a[0][j];
        if (a[m - 1][j] > max)
            max = a[m - 1][j];
    }
    for (int i = 1; i < m - 1; i++)
    {
        if (a[i][0] > max)
            max = a[i][0];
        if (a[i][n - 1] > max)
            max = a[i][n - 1];
    }
    return max;
}

int demPhanTuCoChuSo2(int a[][MAX], int m, int n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = abs(a[i][j]);
            while (num > 0)
            {
                if (num % 10 == 2)
                {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return count;
}

void xuatPhanTuCucTieu(int a[][MAX], int m, int n)
{
    printf("\nCac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int isCucTieu = 1;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                        continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] <= a[i][j])
                    {
                        isCucTieu = 0;
                        break;
                    }
                }
                if (!isCucTieu)
                    break;
            }
            if (isCucTieu)
            {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

void sapXepDongChanLeDongsLe(int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            // Sắp xếp dòng chẵn giảm dần
            for (int j = 0; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i][j] < a[i][k])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[i][k];
                        a[i][k] = temp;
                    }
                }
            }
        }
        else
        {
            // Sắp xếp dòng lẻ tăng dần
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
}

void sapXepCotChanLeCot(int a[][MAX], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            // Sắp xếp cột chẵn tăng dần
            for (int i = 0; i < m - 1; i++)
            {
                for (int k = i + 1; k < m; k++)
                {
                    if (a[i][j] > a[k][j])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
        else
        {
            // Sắp xếp cột lẻ giảm dần
            for (int i = 0; i < m - 1; i++)
            {
                for (int k = i + 1; k < m; k++)
                {
                    if (a[i][j] < a[k][j])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
    }
}

int kiemTraGiamDanZicZac(int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0 && a[i][j] >= a[i - 1][j - 1])
            {
                return 0;
            }
        }
    }
    return 1;
}

void lietKeDongChuaToanChan(int a[][MAX], int m, int n)
{
    printf("\nCac dong chua toan gia tri chan:\n");
    int coKetQua = 0;
    for (int i = 0; i < m; i++)
    {
        int toanChan = 1;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                toanChan = 0;
                break;
            }
        }
        if (toanChan)
        {
            printf("Dong %d\n", i);
            coKetQua = 1;
        }
    }
    if (coKetQua == 0)
    {
        printf("Khong co dong nao chua toan gia tri chan");
    }
}

void lietKeDongGiamDan(int a[][MAX], int m, int n)
{
    printf("\nCac dong chua gia tri giam dan:\n");
    int coKetQua = 0;
    for (int i = 0; i < m; i++)
    {
        int giamDan = 1;
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] >= a[i][j - 1])
            {
                giamDan = 0;
                break;
            }
        }
        if (giamDan)
        {
            printf("Dong %d\n", i);
            coKetQua == 1;
        }
    }
    if (coKetQua == 0)
    {
        printf("Khong co dong nao chua gia tri giam dan");
    }
}

int timGiaTriXuatHienNhieuNhat(int a[][MAX], int m, int n)
{
    int count[1001] = {0}; // Giả sử giá trị trong ma trận từ 0 đến 1000
    int maxCount = 0, maxValue = a[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count[a[i][j]]++;
            if (count[a[i][j]] > maxCount || (count[a[i][j]] == maxCount && a[i][j] > maxValue))
            {
                maxCount = count[a[i][j]];
                maxValue = a[i][j];
            }
        }
    }

    return maxValue;
}

void timChuSoXuatHienNhieuNhat(int a[][MAX], int m, int n)
{
    int count[10] = {0};
    int maxCount = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = abs(a[i][j]);
            if (num == 0)
            {
                count[0]++;
            }
            else
            {
                while (num > 0)
                {
                    count[num % 10]++;
                    num /= 10;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] > maxCount)
        {
            maxCount = count[i];
        }
    }

    printf("\nCac chu so xuat hien nhieu nhat (xuat hien %d lan):\n", maxCount);
    for (int i = 0; i < 10; i++)
    {
        if (count[i] == maxCount)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void lietKeCotTongNhoNhat(int a[][MAX], int m, int n)
{
    int minSum = INT_MAX;
    int sums[MAX] = {0};

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            sums[j] += a[i][j];
        }
        if (sums[j] < minSum)
        {
            minSum = sums[j];
        }
    }

    printf("\nCac cot co tong nho nhat (tong = %d):\n", minSum);
    for (int j = 0; j < n; j++)
    {
        if (sums[j] == minSum)
        {
            printf("Cot %d\n", j);
        }
    }
}

void hoanViHaiCot(int a[][MAX], int m, int n, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        printf("\nChi so cot khong hop le!");
        return;
    }

    for (int k = 0; k < m; k++)
    {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}

void hoanViHaiDong(int a[][MAX], int m, int n, int k, int l)
{
    if (k < 0 || k >= m || l < 0 || l >= m)
    {
        printf("\nChi so dong khong hop le!");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        int temp = a[k][j];
        a[k][j] = a[l][j];
        a[l][j] = temp;
    }
}
