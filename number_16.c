#include <stdio.h>


union Number {
    double real;
    unsigned long long bits;
};

int main(void)
{
    union Number number;
    unsigned long long exponent;
    unsigned long long mantissa;
    unsigned long long sign;

    printf("Enter a real number: ");
    scanf("%lf", &number.real);

    //оставит только тот бит, который одновременно уставновлен и в битовом представлении и в маске 1 unsigned long long, сдвинутой на 63 позиции влево и получившей самый старший бит
    // 0 - положительно, 1 - отрицательно
    sign = number.bits & (1ULL << 63);

    //сдвигом вправо на 52 позиции получим эскпоненту и побитовым сравнением с маской 0x7FFULL(где 0x7FF из 16 -> 2 будет 11 единиц), получим закодированную экспоненту числа
    exponent = (number.bits >> 52) & 0x7FFULL;
    
    // устанавливаем бит на позиции 52 и вычитаем единицу, чтобы расположить маску из 52 единиц в млдаших битах, чтобы после сравнить с битовым представлением, не затронув знак и экспоненту
    mantissa = number.bits & ((1ULL << 52) - 1);

    //уменьшение экспоненты на один = уменьшение возведения числа в степень двойки на 1 = число меньше вдвое
    exponent--;
    number.bits = sign | (exponent << 52) | mantissa;

    printf("Result: %.15g\n", number.real);
    return 0;
}
