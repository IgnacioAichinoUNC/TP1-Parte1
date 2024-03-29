#include "stdio.h"
#include "math.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"
#include "macros.h"

int PRE_CDECL asm_sum( int num1, int num2 ) POST_CDECL;
int PRE_CDECL asm_sub( int num1, int num2 ) POST_CDECL;

long resolve_operation(int first, char operator, int second);
long str2int(char number[]);
long long int2bin(long long number_int);
bool is_sum(char operand);
bool is_subtraction(char operand);
bool is_binary(char number[]);
bool is_decimal(char number[]);

int main(int argc, char *argv[]) {
    
    if ((is_binary(argv[1]) && strlen(argv[1]) > 17) || (is_binary(argv[3]) && strlen(argv[3]) > 17)) {
        /* In order to prevent the user to insert binary values with more than 16 bits, this condition
         * checks that the length of both inserted values is not bigger than 17 characters (including 'b')
         */
        printf("Binary numbers should have less than 16 bits"); 
        return -1;
    }

    if (argc == 4) {
        printf("The operation is '%s %s %s'\n", argv[1], argv[2], argv[3]);
    }
    else {
        printf("Arguments expected: <number><operand><number>\n");
        return -1;
    }

    if ((is_decimal(argv[1]) && is_decimal(argv[3])) || (is_binary(argv[1]) && is_binary(argv[3]))) {          
        long first_number = str2int(argv[1]);
        long second_number = str2int(argv[3]);

        long long result = resolve_operation(first_number, argv[2][0], second_number);
        char bin_char = ' ';

        if (is_binary(argv[1]) && is_binary(argv[3])) {
            result = int2bin(result);
            bin_char = 'b'; 
        }

        printf("El resultado es: %lld%c\n" , result, bin_char);
    }
    else {
        printf("The operation entered is invalid. Please enter only decimal or binary numbers, but no both\n");
        return -1;     
    }

    return 0;
}

long resolve_operation(int first, char operator, int second) {
    if (is_sum(operator)) {
        return asm_sum(first, second);
    } 
    else if (is_subtraction(operator)) {
        return asm_sub(first, second);
    }
}

long str2int(char number[]) {
    if (is_decimal(number)) {
        return atoi(number);
    }
    else if (is_binary(number)) {
        long new_num = 0;
        int number_size = strlen(number) - 1;  //size of number without the 'b' character 

        for(int i = 0; i < number_size; i++) {
            int aux = number[number_size -1 - i] - 48;  //48 is subtracted because it is the equivalent number in ascii of char 0
            new_num += aux * pow(2, i);
        }
        return new_num;
    }
}

long long int2bin(long long number_int) {
    long long bin = 0, i = 1;
    int rem;
    while (number_int != 0) {
        rem = number_int % 2;
        number_int /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

bool is_sum(char operand) {
    return operand == '+';
}

bool is_subtraction(char operand) {
    return operand == '-';
}

bool is_binary(char number[]) {
    size_t number_size = strlen(number);
    bool is_bin = true;
        
    if (number[number_size-1] == 'b') {
        for (int i = 0; i < number_size-1; i++){
            if (number[i] != '0' && number[i] != '1'){
                is_bin = false;
            }
        }
    }
    else {
        is_bin = false;
    }
    return is_bin;
}

bool is_decimal(char number[]) {
    bool only_numbers = true;
    for (int i = 0; i < strlen(number); i++){
        if (number[i] >= '0' && number[i] <= '9'){
            continue;
        }
        else if (i == 0 && number[i] == '-') {
            continue;
        }
        else {
            only_numbers = false;
        }
    }
    return only_numbers;
}