//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void tao_mang_ngau_nhien(int a[], int n) {
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++) {
//		a[i] = rand() % 101;
//	}
//}
//
//void tao_mang_so_chan(int a[], int n) {
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++) {
//		a[i] = 2 * (rand() % 51);
//	}
//}
//
//int tim_kiem_tuyen_tinh(int a[], int n, int x) {
//	for (int i = 0; i < n; i++) {
//		if (a[i] == x) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//void sap_xep_doi_cho(int a[], int n, int tang_giam) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if ((tang_giam && a[i] > a[j]) || (!tang_giam && a[i] < a[j])) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//
//int tim_kiem_nhi_phan(int a[], int n, int x) {
//	int left = 0, right = n - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (a[mid] == x) {
//			return mid;
//		}
//		else if (a[mid] < x) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
//
//void sap_xep_chon(int a[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		int min_idx = i;
//		for (int j = i + 1; j < n; j++) {
//			if (a[j] < a[min_idx]) {
//				min_idx = j;
//			}
//		}
//		int temp = a[i];
//		a[i] = a[min_idx];
//		a[min_idx] = temp;
//	}
//}
//
//void quick_sort(int a[], int left, int right) {
//	if (left < right) {
//		int pivot = a[(left + right) / 2];
//		int i = left, j = right;
//		while (i <= j) {
//			while (a[i] < pivot) {
//				i++;
//			}
//			while (a[j] > pivot) {
//				j--;
//			}
//			if (i <= j) {
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//				i++;
//				j--;
//			}
//		}
//		quick_sort(a, left, j);
//		quick_sort(a, i, right);
//	}
//}
//
//void in_mang(int a[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	int n, x;
//	int a[100];
//
//	do {
//		printf("Nhap so phan tu cua mang (>=10): ");
//		scanf_s("%d", &n);
//	} while (n < 10);
//
//	int choice;
//	int pos;
//	do {
//		printf("\nMENU:\n");
//		printf("1. Tao mang ngau nhien\n");
//		printf("2. Tao mang chua toan so chan\n");
//		printf("3. Tim kiem tuyen tinh\n");
//		printf("4. Sap xep doi cho tang dan\n");
//		printf("5. Sap xep doi cho giam dan\n");
//		printf("6. Tim kiem nhi phan\n");
//		printf("7. Sap xep chon tang dan\n");
//		printf("8. Sap xep nhanh tang dan\n");
//		printf("0. Thoat\n");
//		printf("Nhap lua chon cua ban: ");
//		scanf_s("%d", &choice);
//
//		switch (choice) {
//		case 1:
//			tao_mang_ngau_nhien(a, n);
//			printf("Mang ngau nhien: ");
//			in_mang(a, n);
//			break;
//		case 2:
//			tao_mang_so_chan(a, n);
//			printf("Mang chua toan so chan: ");
//			in_mang(a, n);
//			break;
//		case 3:
//			printf("Nhap gia tri can tim: ");
//			scanf_s("%d", &x);
//			pos = tim_kiem_tuyen_tinh(a, n, x);
//			if (pos != -1) {
//				printf("Tim thay %d tai vi tri %d trong mang.\n", x, pos);
//			}
//			else {
//				printf("Khong tim thay %d trong mang.\n", x);
//			}
//			break;
//		case 4:
//			sap_xep_doi_cho(a, n, 1);
//			printf("Mang sau khi sap xep tang dan: ");
//			in_mang(a, n);
//			break;
//		case 5:
//			sap_xep_doi_cho(a, n, 0);
//			printf("Mang sau khi sap xep giam dan: ");
//			in_mang(a, n);
//			break;
//		case 6:
//			sap_xep_doi_cho(a, n, 1);
//			printf("Nhap gia tri can tim: ");
//			scanf_s("%d", &x);
//			pos = tim_kiem_nhi_phan(a, n, x);
//			if (pos != -1) {
//				printf("Tim thay %d tai vi tri %d trong mang.\n", x, pos);
//			}
//			else {
//				printf("Khong tim thay %d trong mang.\n", x);
//			}
//			break;
//		case 7:
//			sap_xep_chon(a, n);
//			printf("Mang sau khi sap xep tang dan: ");
//			in_mang(a, n);
//			break;
//		case 8:
//			quick_sort(a, 0, n - 1);
//			printf("Mang sau khi sap xep tang dan: ");
//			in_mang(a, n);
//			break;
//		case 0:
//			printf("Ket thuc chuong trinh.\n");
//			break;
//		default:
//			printf("Lua chon khong hop le. Vui long chon lai.\n");
//		}
//	} while (choice != 0);
//
//	return 0;
//}