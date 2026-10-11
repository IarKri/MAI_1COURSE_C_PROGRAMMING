#include <stdio.h>
int main(void){

    long long initial_sequence;
    scanf("%lld", &initial_sequence);


    int digits[64];
    int counter = 0;
    int unary_minus=0;

    if (initial_sequence<0){
        unary_minus = 1;
    }

    while (initial_sequence > 0) {
        digits[counter++] = (int)(initial_sequence % 9);
        initial_sequence /= 9;
    }

    for (int external_pointer = 0; external_pointer < counter - 1; external_pointer++){
        for (int internal_pointer = 0; internal_pointer < counter - 1 - external_pointer; internal_pointer++) {
            if (digits[internal_pointer] > digits[internal_pointer+1]){
                int swap = digits[internal_pointer];
                digits[internal_pointer] = digits[internal_pointer+1];
                digits[internal_pointer+1] = swap;
            }
        }
    }

    long long result = 0;
    for (int result_counter = counter - 1; result_counter >= 0; result_counter--){
        result = result * 10 + digits[result_counter];
    }
    if (unary_minus == 0){
        printf ("%lld\n", result);
    } else {
        printf ("%lld\n", -result);        
    }
}