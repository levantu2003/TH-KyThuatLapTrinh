#include <stdio.h>
#include <math.h>

float deQuy(int n)
{
    if (n == 1)
        return 1;
    return sqrt(5 + deQuy(n - 1));
}

int main(int argc, char const *argv[])
{
    int n = 5;
    printf("Ket qua: %f", deQuy(n));
    return 0;
}
