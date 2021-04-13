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

response=$(./execute 2 + 2)
result="The operation is '2 + 2'
El resultado es: 4 "
assert_equals "$response" "$result"

response=$(./execute 5 - 2)
result="The operation is '5 - 2'
El resultado es: 3 "
assert_equals "$response" "$result"

response=$(./execute 101b + 11b)
result="The operation is '101b + 11b'
El resultado es: 1000b"
assert_equals "$response" "$result"

response=$(./execute 101b - 11b)
result="The operation is '101b - 11b'
El resultado es: 10b"
assert_equals "$response" "$result"

response=$(./execute 0x15 - 0xFF)
result="The operation is '0x15 - 0xFF'
The operation entered is invalid. Please enter only decimal or binary numbers, but no both"
assert_equals "$response" "$result"