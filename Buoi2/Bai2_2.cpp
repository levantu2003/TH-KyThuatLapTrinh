#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KICH_THUOC_TOI_DA 100

typedef struct {
	int TuSo;
	int MauSo;
} PhanSo;

typedef struct {
	int PhanNguyen;
	PhanSo PhanPhanSo;
} HonSo;

HonSo MangHonSo[KICH_THUOC_TOI_DA];
int KichThuocMang = 0;

int layNgauNhien(int Min, int Max) {
	return Min + rand() % (Max - Min + 1);
}

PhanSo taoNgauNhienPhanSo() {
	PhanSo PS;
	PS.TuSo = layNgauNhien(0, 9);
	PS.MauSo = layNgauNhien(1, 9);
	return PS;
}

void taoNgauNhienMangHonSo() {
	KichThuocMang = layNgauNhien(3, 5);
	for (int i = 0; i < KichThuocMang; i++) {
		MangHonSo[i].PhanNguyen = layNgauNhien(0, 9);
		MangHonSo[i].PhanPhanSo = taoNgauNhienPhanSo();
	}
}

void inHonSo(HonSo HS) {
	printf("%d %d/%d", HS.PhanNguyen, HS.PhanPhanSo.TuSo, HS.PhanPhanSo.MauSo);
}

void inMangHonSo() {
	for (int i = 0; i < KichThuocMang; i++) {
		inHonSo(MangHonSo[i]);
		printf("\n");
	}
}

int soSanhHonSo(HonSo HS1, HonSo HS2) {
	double GiaTri1 = HS1.PhanNguyen + (double)HS1.PhanPhanSo.TuSo / HS1.PhanPhanSo.MauSo;
	double GiaTri2 = HS2.PhanNguyen + (double)HS2.PhanPhanSo.TuSo / HS2.PhanPhanSo.MauSo;

	if (GiaTri1 < GiaTri2) return -1;
	if (GiaTri1 > GiaTri2) return 1;
	return 0;
}

PhanSo chuyenHonSoThanhPhanSo(HonSo HS) {
	PhanSo KetQua;
	KetQua.TuSo = HS.PhanNguyen * HS.PhanPhanSo.MauSo + HS.PhanPhanSo.TuSo;
	KetQua.MauSo = HS.PhanPhanSo.MauSo;
	return KetQua;
}

HonSo chuyenPhanSoThanhHonSo(PhanSo PS) {
	HonSo KetQua;
	KetQua.PhanNguyen = PS.TuSo / PS.MauSo;
	KetQua.PhanPhanSo.TuSo = PS.TuSo % PS.MauSo;
	KetQua.PhanPhanSo.MauSo = PS.MauSo;
	return KetQua;
}

int timUCLN(int a, int b) {
	if (b == 0) return a;
	return timUCLN(b, a % b);
}

void rutGonPhanSo(PhanSo* PS) {
	int UocChung = timUCLN(abs(PS->TuSo), abs(PS->MauSo));
	PS->TuSo /= UocChung;
	PS->MauSo /= UocChung;
}

HonSo congHonSo(HonSo HS1, HonSo HS2) {
	PhanSo PS1 = chuyenHonSoThanhPhanSo(HS1);
	PhanSo PS2 = chuyenHonSoThanhPhanSo(HS2);

	PhanSo Tong;
	Tong.TuSo = PS1.TuSo * PS2.MauSo + PS2.TuSo * PS1.MauSo;
	Tong.MauSo = PS1.MauSo * PS2.MauSo;

	rutGonPhanSo(&Tong);
	return chuyenPhanSoThanhHonSo(Tong);
}

HonSo truHonSo(HonSo HS1, HonSo HS2) {
	PhanSo PS1 = chuyenHonSoThanhPhanSo(HS1);
	PhanSo PS2 = chuyenHonSoThanhPhanSo(HS2);

	PhanSo Hieu;
	Hieu.TuSo = PS1.TuSo * PS2.MauSo - PS2.TuSo * PS1.MauSo;
	Hieu.MauSo = PS1.MauSo * PS2.MauSo;

	rutGonPhanSo(&Hieu);
	return chuyenPhanSoThanhHonSo(Hieu);
}

HonSo nhanHonSo(HonSo HS1, HonSo HS2) {
	PhanSo PS1 = chuyenHonSoThanhPhanSo(HS1);
	PhanSo PS2 = chuyenHonSoThanhPhanSo(HS2);

	PhanSo Tich;
	Tich.TuSo = PS1.TuSo * PS2.TuSo;
	Tich.MauSo = PS1.MauSo * PS2.MauSo;

	rutGonPhanSo(&Tich);
	return chuyenPhanSoThanhHonSo(Tich);
}

HonSo chiaHonSo(HonSo HS1, HonSo HS2) {
	PhanSo PS1 = chuyenHonSoThanhPhanSo(HS1);
	PhanSo PS2 = chuyenHonSoThanhPhanSo(HS2);

	PhanSo Thuong;
	Thuong.TuSo = PS1.TuSo * PS2.MauSo;
	Thuong.MauSo = PS1.MauSo * PS2.TuSo;

	rutGonPhanSo(&Thuong);
	return chuyenPhanSoThanhHonSo(Thuong);
}

void hoanDoi(HonSo* a, HonSo* b) {
	HonSo Temp = *a;
	*a = *b;
	*b = Temp;
}

void sapXepDoiChoTrucTiep(int TangDan) {
	for (int i = 0; i < KichThuocMang - 1; i++) {
		for (int j = i + 1; j < KichThuocMang; j++) {
			int KetQuaSoSanh = soSanhHonSo(MangHonSo[i], MangHonSo[j]);
			if ((TangDan && KetQuaSoSanh > 0) || (!TangDan && KetQuaSoSanh < 0)) {
				hoanDoi(&MangHonSo[i], &MangHonSo[j]);
			}
		}
	}
}

void sapXepChon(int TangDan) {
	for (int i = 0; i < KichThuocMang - 1; i++) {
		int ViTriCucTri = i;
		for (int j = i + 1; j < KichThuocMang; j++) {
			int KetQuaSoSanh = soSanhHonSo(MangHonSo[j], MangHonSo[ViTriCucTri]);
			if ((TangDan && KetQuaSoSanh < 0) || (!TangDan && KetQuaSoSanh > 0)) {
				ViTriCucTri = j;
			}
		}
		if (ViTriCucTri != i) {
			hoanDoi(&MangHonSo[i], &MangHonSo[ViTriCucTri]);
		}
	}
}

int phanDoan(int Thap, int Cao, int TangDan) {
	HonSo Truc = MangHonSo[Cao];
	int i = Thap - 1;

	for (int j = Thap; j < Cao; j++) {
		int KetQuaSoSanh = soSanhHonSo(MangHonSo[j], Truc);
		if ((TangDan && KetQuaSoSanh <= 0) || (!TangDan && KetQuaSoSanh >= 0)) {
			i++;
			hoanDoi(&MangHonSo[i], &MangHonSo[j]);
		}
	}

	hoanDoi(&MangHonSo[i + 1], &MangHonSo[Cao]);
	return i + 1;
}

void sapXepNhanh(int Thap, int Cao, int TangDan) {
	if (Thap < Cao) {
		int ChiSoPhanDoan = phanDoan(Thap, Cao, TangDan);
		sapXepNhanh(Thap, ChiSoPhanDoan - 1, TangDan);
		sapXepNhanh(ChiSoPhanDoan + 1, Cao, TangDan);
	}
}

void Menu() {
	printf("\n--- MENU ---\n");
	printf("1. Tao Ngau Nhien Mang Hon So\n");
	printf("2. In Danh Sach Hon So\n");
	printf("3. So Sanh Hai Hon So\n");
	printf("4. Chuyen Hon So Thanh Phan So\n");
	printf("5. Chuyen Phan So Thanh Hon So\n");
	printf("6. Thuc Hien Phep Tinh voi Hai Hon So\n");
	printf("7. Sap Xep Mang Hon So\n");
	printf("0. Thoat\n");
	printf("Chon chuc nang: ");
}

int main() {
	srand((unsigned int)time(NULL));
	int LuaChon;

	do {
		Menu();
		scanf_s("%d", &LuaChon);

		switch (LuaChon) {
		case 1:
			taoNgauNhienMangHonSo();
			printf("Da tao Mang Hon So ngau nhien.\n");
			break;
		case 2:
			printf("Danh sach Hon So:\n");
			inMangHonSo();
			break;
		case 3:
			if (KichThuocMang < 2) {
				printf("Can it nhat 2 Hon So trong Mang.\n");
			}
			else {
				int KetQua = soSanhHonSo(MangHonSo[0], MangHonSo[1]);
				printf("So sanh Hon So 1 va Hon So 2: ");
				if (KetQua < 0) printf("Hon So 1 < Hon So 2\n");
				else if (KetQua > 0) printf("Hon So 1 > Hon So 2\n");
				else printf("Hon So 1 = Hon So 2\n");
			}
			break;
		case 4:
			if (KichThuocMang > 0) {
				PhanSo PS = chuyenHonSoThanhPhanSo(MangHonSo[0]);
				printf("Hon So dau tien chuyen thanh Phan So: %d/%d\n", PS.TuSo, PS.MauSo);
			}
			else {
				printf("Mang rong.\n");
			}
			break;
		case 5:
		{
			PhanSo PS;
			printf("Nhap Tu So va Mau So cua Phan So: ");
			scanf_s("%d %d", &PS.TuSo, &PS.MauSo);
			HonSo HS = chuyenPhanSoThanhHonSo(PS);
			printf("Phan So chuyen thanh Hon So: ");
			inHonSo(HS);
			printf("\n");
		}
		break;
		case 6:
			if (KichThuocMang >= 2) {
				printf("Tong: ");
				inHonSo(congHonSo(MangHonSo[0], MangHonSo[1]));
				printf("\nHieu: ");
				inHonSo(truHonSo(MangHonSo[0], MangHonSo[1]));
				printf("\nTich: ");
				inHonSo(nhanHonSo(MangHonSo[0], MangHonSo[1]));
				printf("\nThuong: ");
				inHonSo(chiaHonSo(MangHonSo[0], MangHonSo[1]));
				printf("\n");
			}
			else {
				printf("Can it nhat 2 Hon So trong Mang.\n");
			}
			break;
		case 7:
		{
			int PhuongPhapSapXep, TangDan;
			printf("Chon phuong phap sap xep (1: Doi cho truc tiep, 2: Chon, 3: Nhanh): ");
			scanf_s("%d", &PhuongPhapSapXep);
			printf("Sap xep tang dan (1) hay giam dan (0)? ");
			scanf_s("%d", &TangDan);
			switch (PhuongPhapSapXep) {
			case 1:
				sapXepDoiChoTrucTiep(TangDan);
				break;
			case 2:
				sapXepChon(TangDan);
				break;
			case 3:
				sapXepNhanh(0, KichThuocMang - 1, TangDan);
				break;
			default:
				printf("Lua chon khong hop le.\n");
				break;
			}

			printf("Da sap xep Mang Hon So.\n");
		}
		break;
		case 0:
			printf("Tam biet!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (LuaChon != 0);

	return 0;
}