#include <stdio.h>
int main(void){

    //инициализация переменных
    long long initial_sequence;
    printf("Initial sequence: ");
    scanf("%lld", &initial_sequence);
    int digits[32];
    int counter = 0;
    int unary_minus = 0;

    if (initial_sequence < 0){
        unary_minus = 1;

        initial_sequence = -initial_sequence;
    }

    //заполнение массива девятеричными цифрам числа
    while (initial_sequence > 0){

        if ((int)(initial_sequence % 10) != 9){
            digits[counter++] = (int)(initial_sequence % 10);
            initial_sequence /= 10;
        }

        else{
            initial_sequence /= 10;
            continue;
        }
    }

    //сортирвка цифр в порядке невозрастания
    for (int external_pointer = 0; external_pointer < counter - 1; external_pointer++){

        for (int internal_pointer = 0; internal_pointer < counter - 1 - external_pointer; internal_pointer++){

            if (digits[internal_pointer] > digits[internal_pointer + 1]){

                int swap = digits[internal_pointer];
                digits[internal_pointer] = digits[internal_pointer + 1];
                digits[internal_pointer + 1] = swap;
            }
        }
    }

    //формирование и вывод результата
    long long result = 0;
    for (int result_counter = counter - 1; result_counter >= 0; result_counter--){
        result = result * 10 + digits[result_counter];
    }

    if (unary_minus == 0){
        printf("Reversed sequence: %lld", result);
    }

    else{
        printf("Reversed sequence: %lld", -result);
    }
}
