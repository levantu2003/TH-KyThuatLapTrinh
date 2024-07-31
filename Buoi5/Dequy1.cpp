#include <stdio.h>

int deQuy(int n)
{
    if (n == 1)
        return 1;
    return n + deQuy(n - 1);
}

int main(int argc, char const *argv[])
{
    int n = 5;
    printf("Ket qua: %d", deQuy(n));
    return 0;
}
