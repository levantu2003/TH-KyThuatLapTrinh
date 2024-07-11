#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DO_DAI_TOI_DA 100

void inKyTu(char *chuoi);
void chuHoa(char *chuoi);
void chuHoaDauTu(char *chuoi);

int main() {
    char chuoi[DO_DAI_TOI_DA];
    char *conTro = chuoi;

    printf("Nhap chuoi: ");
    fgets(chuoi, DO_DAI_TOI_DA, stdin);
    chuoi[strcspn(chuoi, "\n")] = 0;

    printf("\na. Cac ky tu trong chuoi:\n");
    inKyTu(conTro);

    printf("\nb. Chuoi sau khi chuyen thanh chu hoa:\n");
    chuHoa(conTro);
    printf("%s\n", chuoi);

    strcpy(chuoi, conTro);

    printf("\nc. Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa:\n");
    chuHoaDauTu(conTro);
    printf("%s\n", chuoi);

    return 0;
}

void inKyTu(char *chuoi) {
    while (*chuoi != '\0') {
        printf("%c ", *chuoi);
        chuoi++;
    }
    printf("\n");
}

void chuHoa(char *chuoi) {
    while (*chuoi != '\0') {
        *chuoi = toupper(*chuoi);
        chuoi++;
    }
}

void chuHoaDauTu(char *chuoi) {
    int vietHoaTiep = 1;

    while (*chuoi != '\0') {
        if (vietHoaTiep && isalpha(*chuoi)) {
            *chuoi = toupper(*chuoi);
            vietHoaTiep = 0;
        } else if (isspace(*chuoi)) {
            vietHoaTiep = 1;
        } else {
            *chuoi = tolower(*chuoi);
        }
        chuoi++;
    }
}
