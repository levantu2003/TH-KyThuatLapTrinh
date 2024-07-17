#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

void chuyenChuThuong(char* Str)
{
	for (int i = 0; Str[i]; i++)
	{
		Str[i] = tolower((unsigned char)Str[i]);
	}
}

int tinhTuoi(int Ngay, int Thang, int Nam)
{
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);
	int Tuoi = tm.tm_year + 1900 - Nam;
	if (tm.tm_mon + 1 < Thang || (tm.tm_mon + 1 == Thang && tm.tm_mday < Ngay))
	{
		Tuoi--;
	}
	return Tuoi;
}

void nhapThongTin(char* HoTen, int* Ngay, int* Thang, int* Nam, char* GioiTinh)
{
	printf("Nhap ho ten: ");
	fgets(HoTen, 100, stdin);
	HoTen[strcspn(HoTen, "\n")] = 0;

	printf("Nhap ngay sinh (dd/mm/yyyy): ");
	scanf_s("%d/%d/%d", Ngay, Thang, Nam);
	(void)getchar(); // Doc ky tu newline con lai

	printf("Nhap gioi tinh (nam/nu): ");
	fgets(GioiTinh, 4, stdin);
	GioiTinh[strcspn(GioiTinh, "\n")] = 0;
	chuyenChuThuong(GioiTinh);
}

int kiemTraHopLe(char* GioiTinh, int TuoiHienTai, int TuoiHuu)
{
	if (strcmp(GioiTinh, "nam") != 0 && strcmp(GioiTinh, "nu") != 0)
	{
		printf("Loi: Gioi tinh khong hop le.\n");
		return 0;
	}
	if (TuoiHienTai < 18 || TuoiHienTai >= TuoiHuu)
	{
		printf("Loi: Tuoi khong nam trong do tuoi lao dong.\n");
		return 0;
	}
	return 1;
}

void tinhVaHienThiKetQua(char* HoTen, int Ngay, int Thang, int Nam, char* GioiTinh)
{
	int TuoiHienTai = tinhTuoi(Ngay, Thang, Nam);
	int TuoiHuu = (strcmp(GioiTinh, "nam") == 0) ? 62 : 60;

	if (!kiemTraHopLe(GioiTinh, TuoiHienTai, TuoiHuu))
	{
		return;
	}

	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);
	int NamHienTai = tm.tm_year + 1900;

	int NamNghiHuu = Nam + TuoiHuu;
	int ThangNghiHuu = Thang;

	if (Thang == 12)
	{
		ThangNghiHuu = 1;
		NamNghiHuu++;
	}

	char* Ten = strrchr(HoTen, ' ');
	Ten = (Ten != NULL) ? Ten + 1 : HoTen;

	printf("\n%s, gioi tinh %s, sinh ngay %02d/%02d/%d.", HoTen, GioiTinh, Ngay, Thang, Nam);
	printf("\nHien tai (nam %d) %s da %d tuoi. ", NamHienTai, Ten, TuoiHienTai);
	printf("\nThoi gian %s duoc nghi huu la thang %02d/%d.\n", Ten, ThangNghiHuu, NamNghiHuu);
}

int main()
{
	char HoTen[100], GioiTinh[4];
	int Ngay, Thang, Nam;

	nhapThongTin(HoTen, &Ngay, &Thang, &Nam, GioiTinh);
	tinhVaHienThiKetQua(HoTen, Ngay, Thang, Nam, GioiTinh);

	return 0;
}