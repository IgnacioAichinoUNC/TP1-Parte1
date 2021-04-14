#!/bin/bash

assert_equals () {
  if [ "$1" = "$2" ]; then
    echo -e "$Green $Check_Mark Success $Color_Off"
  else
    echo -e "$Red Failed $Color_Off"
    echo -e "$Red Expected -$1- to equal -$2- $Color_Off"
    Errors=$((Errors  + 1))
    exit 1
  fi
}

# Decimal sum
response=$(./execute 2 + 2)
result="The operation is '2 + 2'
El resultado es: 4 "
assert_equals "$response" "$result"

response=$(./execute 2 + -32)
result="The operation is '2 + -32'
El resultado es: -30 "
assert_equals "$response" "$result"

# Decimal subtraction
response=$(./execute 5 - 2)
result="The operation is '5 - 2'
El resultado es: 3 "
assert_equals "$response" "$result"

response=$(./execute -5 - 23)
result="The operation is '-5 - 23'
El resultado es: -28 "
assert_equals "$response" "$result"

# Binary sum
response=$(./execute 101b + 11b)
result="The operation is '101b + 11b'
El resultado es: 1000b"
assert_equals "$response" "$result"

response=$(./execute 1111111111111110b + 1b)
result="The operation is '1111111111111110b + 1b'
El resultado es: 1111111111111111b"
assert_equals "$response" "$result"

# Binary subtraction
response=$(./execute 101b - 11b)
result="The operation is '101b - 11b'
El resultado es: 10b"
assert_equals "$response" "$result"

response=$(./execute 1b - 100b)
result="The operation is '1b - 100b'
El resultado es: -11b"
assert_equals "$response" "$result"

# Errors
response=$(./execute 10000000000000000b - 1b)
result="Binary numbers should have less than 16 bits"
assert_equals "$response" "$result"

response=$(./execute 1b + 10000000000000000b)
result="Binary numbers should have less than 16 bits"
assert_equals "$response" "$result"

response=$(./execute 0x15 - 0xFF)
result="The operation is '0x15 - 0xFF'
The operation entered is invalid. Please enter only decimal or binary numbers, but no both"
assert_equals "$response" "$result"

response=$(./execute 111b + 25)
result="The operation is '111b + 25'
The operation entered is invalid. Please enter only decimal or binary numbers, but no both"
assert_equals "$response" "$result"

