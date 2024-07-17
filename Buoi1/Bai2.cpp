#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <stdio.h>


int tinhTuoi(int namSinh) {
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	int namHH = 1900 + ltm.tm_year;

	try {
		if (namSinh <= 0 || namSinh > namHH)
			throw 101;
		else if (namSinh < 1920)
			throw 102;
		else
			return namHH - namSinh;
	}
	catch (int errCode) {
		if (errCode == 101)
			printf("Nam sinh khong hop le\n");
		else
			printf("Nam sinh < 1920\n");
		return -1;
	}
}

int main() {
	int tuoi = tinhTuoi(-1);
	if (tuoi != -1) {
		printf("Tuoi cua ban la: %d\n", tuoi);
	}
	return 0;
}

