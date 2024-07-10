#include <ctime>
#include <stdio.h>

int tinhTuoi(int namSinh)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int namHH = 1900 + ltm->tm_year;

    try
    {
        if (namSinh <= 0 || namSinh > namHH)
            throw 101;
        else if (namSinh < 1920)
            throw 102;
        else
            return namHH - namSinh;
    }
    catch (int errCode)
    {
        if (errCode == 101)
            printf("nam sinh khong hop le\n");
        else
            printf("nam sinh < 1920 \n");
        return -1;
    }
}

int main()
{
    int tuoi = tinhTuoi(2003);
    if (tuoi != -1)
    {
        printf("Tuoi cua ban la: %d\n", tuoi);
    }
    return 0;
}
