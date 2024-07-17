//#include <stdio.h>
//
//float tinhTong(float* a, float* b);
//float tinhHieu(float* a, float* b);
//float tinhTich(float* a, float* b);
//float tinhThuong(float* a, float* b);
//
//int main()
//{
//	float a, b;
//	float tong, hieu, tich, thuong;
//
//	printf("Nhap a va b: ");
//	scanf_s("%f%f", &a, &b);
//
//	float* pa = &a;
//	float* pb = &b;
//
//	tong = tinhTong(pa, pb);
//	hieu = tinhHieu(pa, pb);
//	tich = tinhTich(pa, pb);
//	thuong = tinhThuong(pa, pb);
//
//	printf("\nDia chi cua a: %p", (void*)pa);
//	printf("\nDia chi cua b: %p", (void*)pb);
//
//	printf("\n\nTong: %.2f", tong);
//	printf("\nDia chi cua tong: %p", (void*)&tong);
//
//	printf("\n\nHieu: %.2f", hieu);
//	printf("\nDia chi cua hieu: %p", (void*)&hieu);
//
//	printf("\n\nTich: %.2f", tich);
//	printf("\nDia chi cua tich: %p", (void*)&tich);
//
//	printf("\n\nThuong: %.2f", thuong);
//	printf("\nDia chi cua thuong: %p", (void*)&thuong);
//
//	return 0;
//}
//
//float tinhTong(float* a, float* b) {
//	return *a + *b;
//}
//
//float tinhHieu(float* a, float* b) {
//	return *a - *b;
//}
//
//float tinhTich(float* a, float* b) {
//	return *a * *b;
//}
//
//float tinhThuong(float* a, float* b) {
//	if (*b != 0) {
//		return *a / *b;
//	}
//	else {
//		printf("Loi: Mau so bang 0!\n");
//		return 0;
//	}
//}