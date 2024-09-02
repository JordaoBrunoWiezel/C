#include <stdio.h>

void number_to_str(int n, char str_number[]) {

sprintf(str_number, "%d", n);

}

int main() {
    char str[1000];
    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    number_to_str(x, str);

    printf("str_number = %s\n", str);

    return 0;
}