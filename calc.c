#include "stdio.h"
#include "stdbool.h"
#include "string.h"

int resolve_operation(char first[], char operator, char second[]);
bool is_sum(char operand);
bool is_subtraction(char operand);
bool is_binary(char number[]);
bool is_decimal(char number[]);
void print_error();

int main(int argc, char *argv[]) {
 
    if (argc == 4) {
        printf("The operation is '%s %s %s'\n", argv[1], argv[2], argv[3]);
    }
    else {
        printf("Arguments expected: <number><operand><number> \n");
    }
    
    int result = resolve_operation(argv[1], argv[2][0], argv[3]);

    return 0;
}

int resolve_operation(char first[], char operator, char second[]) {
    if (is_decimal(first) && is_decimal(second)) {
        if (is_sum(operator)) {
            // call asm_sum
            printf ("call asm_sum");
        } 
        else if (is_subtraction(operator)) {
            // call asm_sub
            printf ("call asm_sub");
        }
    } 
    else if (is_binary(first) && is_binary(second)) {
        if (is_sum(operator)) {
            // call asm_sum_bin
            printf ("call asm_sum_bin");
        } 
        else if (is_subtraction(operator)) {
            // call asm_sub_bin
            printf ("call asm_sub_bin");
        }
    }
    else {
        printf("The operation entered is invalid. Please enter only decimal or binary numbers, but no both\n");
    }

    return 0;
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
        
    if (number[0] == '0' && number[1] == 'b') { 
        for (int i = 2; i < number_size; i++){
            if (number[i] != '0' && number[i] != '1'){
                is_bin = false;
            }
        }
    }
    else if (number[number_size-1] == 'b') {
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
        else {
            only_numbers = false;
        }
    }
    return only_numbers;
}