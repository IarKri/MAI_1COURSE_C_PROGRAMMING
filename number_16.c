#include <stdio.h>


union Number {
    double real;
    unsigned long long bits;
};

int main(void) {
    //инициализация переменных
    union Number number;
    unsigned long long exponent;
    unsigned long long mantissa;
    unsigned long long sign;

    printf("Enter a real number: ");
    scanf("%lf", &number.real);

    //получение знака
    sign = number.bits & (1ULL << 63);

    //получение экспоненты
    exponent = (number.bits >> 52) & 11111111111ULL;
    
    //получение мантиссы
    mantissa = number.bits & ((1ULL << 52) - 1);

    //получение результата
    exponent--;
    number.bits = sign | (exponent << 52) | mantissa;

    printf("Result: %.15g\n", number.real);
    return 0;
}
